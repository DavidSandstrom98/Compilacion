%error-verbose

%{
	#include <stdio.h>
	#include <iostream>
	#include <vector>
	#include <string>
	using namespace std; 

	extern int yylex();
	extern int yylineno;
	extern char *yytext;
	void yyerror (const char *msg) {
		printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
	}

	#include "Codigo.hpp"
	#include "Aux.hpp"

	struct expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3);
	struct expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3);

	//Función unir de dos vectores
	vector<int> *unir(vector<int> lis1, vector<int> lis2);

	void fixSkips(vector<int> lis1);

	Codigo codigo;

%}

/* 
   qué atributos tienen los símbolos 
*/
%union {
    string *str ; 
    vector<string> *list ;
    struct expresionstruct *expr ;
    int number ;
    vector<int> *numlist;
}


/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> TIDENTIFIER TINTEGER TFLOAT
%token <str> TMUL TDIV TPLUS TMINUS
%token <str> TSEMIC TASSIG
%token <str> TPROGRAM
%token <str> TIF TTHEN TELSE
%token <str> TWHILE TDO TUNTIL TSKIP
%token <str> TREAD TPRINT
%token <str> TVAR TIN TOUT TINOUT TTIPEFLOAT TTIPEINTEGER TPROCEDURE
%token <str> TAND TOR TNOT
%token <str> TEQUAL TGREATEQ TFEWEQ TNOTEQ TGREATER TFEWER
%token <str> TLBRACE TRBRACE TLPAREN TRPAREN TCOMMA TDOUBLEDOT 


/* 
   declaración de no terminales :
*/
%type <str> programa
%type <str> bloque
%type <str> declaraciones
%type <list> lista_de_ident
%type <list> resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <list> lista_de_param
%type <str> clase_par
%type <list> resto_lis_de_param
%type <numlist> lista_de_sentencias
%type <numlist> sentencia
%type <str> variable
%type <expr> expresion
%type <number> M

%left TNOT
%left TOR 
%left TAND
%nonassoc TEQUAL TGREATEQ TFEWEQ TNOTEQ TGREATER TFEWER TASSIG
%left TPLUS TMINUS
%left TMUL TDIV


%start programa


%%

programa :  TPROGRAM TIDENTIFIER { codigo.anadirInstruccion("prog " + *$2 + ";" );} 
            bloque TSEMIC 
			{
				codigo.anadirInstruccion("halt;");
                codigo.escribir();
			};



bloque : TLBRACE declaraciones decl_de_subprogs lista_de_sentencias TRBRACE
        {
			//En caso de haber alguna sentencia con un skip if sin haberlo completado, 
			//se ignora y redirigue a la instruccion siguiente.
			fixSkips(*$4);
        };



declaraciones : TVAR lista_de_ident TDOUBLEDOT tipo TSEMIC 
				{
					codigo.anadirDeclaraciones(*$2,*$4);
					delete $2; delete $4 ;
                }
                declaraciones {}
               
			    | /*vacio*/ {}
            	;



lista_de_ident : TIDENTIFIER resto_lista_id 
				{
					$$ = $2;
					$$->insert($$->begin(),*$1);
                };



resto_lista_id : TCOMMA TIDENTIFIER resto_lista_id 
				{
					$$ = $3;
					$$->insert($$->begin(),*$2); 
                }
                
				| /*vacio*/ 
				{
                	$$ = new vector<string>();
                };



tipo : TTIPEINTEGER {*$$ = "int";}
       | TTIPEFLOAT {*$$ = "real";}
       ;



decl_de_subprogs : decl_de_subprograma decl_de_subprogs {}
                   | /*vacio*/ {}
                   ;



decl_de_subprograma : TPROCEDURE TIDENTIFIER { codigo.anadirInstruccion("proc " + *$2 + ";" );} 
                      argumentos bloque TSEMIC
                      { codigo.anadirInstruccion("endproc;");}
                      ;



argumentos : TLPAREN lista_de_param TRPAREN {}
             | /*vacio*/ {}
             ;



lista_de_param : lista_de_ident TDOUBLEDOT clase_par tipo {
                 codigo.anadirParametros(*$1,*$3,*$4);
                 }
                 resto_lis_de_param {}
                 ;



clase_par : TIN
            | TOUT
            | TINOUT
            ;



resto_lis_de_param : TSEMIC lista_de_ident TDOUBLEDOT clase_par tipo {
                     codigo.anadirParametros(*$2,*$4,*$5);
                     }   
                     resto_lis_de_param {}
                     | /*vacio*/ {}
                     ;



lista_de_sentencias : sentencia lista_de_sentencias {                    
                      $$ = unir(*$1, *$2);
                      }
                      | /*vacio*/ {
                      $$ = new vector<int>();
                      }
                      ;



sentencia : variable TASSIG expresion TSEMIC
            {
				codigo.anadirInstruccion(*$1 + " := " + $3->str + ";");
				delete $1; 
				delete $3;
				//No hay ningun skip que almacenar en la sentencia
				$$ = new vector<int>();
            }


            | TIF expresion TTHEN TLBRACE M lista_de_sentencias M TRBRACE TSEMIC 
			{
				codigo.completarInstrucciones($2->trues,$5);
				codigo.completarInstrucciones($2->falses,$7);
				delete $2;
				//Se almacenan los skip de la lista de sentencias
				$$ = $6;
            }


            | TWHILE M expresion TLBRACE M lista_de_sentencias M TRBRACE TSEMIC 
			{
				codigo.completarInstrucciones($3->trues,$5);
				codigo.completarInstrucciones($3->falses,$7+1) ; //El mas uno es para saltar el goto del final

				//Despues de terminar todas las sentencias, se vuelve a evaluar la expresion directamente. 
				//Se añade un goto para ello.
				codigo.anadirInstruccion("goto");
				vector<int> tmp1; 
				tmp1.push_back($7);
				codigo.completarInstrucciones(tmp1, $2);

				//Aquí se completan los skip de la lista de sentencia, 
				//que vuelven a evaluar la condicion de la expresion del while (un continue si se satisface).
				codigo.completarInstrucciones(*$6,$2);

				//Se inicializa a vector vacio la sentencia, pues todos los skip de la lista 
				//de sentencia ya se han completado.
				$$ = new vector<int>();
				delete $3;
            }


            | TDO TLBRACE M lista_de_sentencias TRBRACE TUNTIL M expresion TELSE TLBRACE M lista_de_sentencias TRBRACE TSEMIC
            {
				codigo.completarInstrucciones($8->trues,$11);
				codigo.completarInstrucciones($8->falses,$3);

				//Los skip de la lista de sentencia saltan a evaluar la expresion. Se completa con la dirección de la expresión.
				codigo.completarInstrucciones(*$4,$7);
				
				//Se inicializa a vector vacio la sentencia, pues todos los skip de la lista de sentencia ya se han completado.
				$$ = new vector<int>();
				delete $8;
            }


            | TSKIP TIF expresion TSEMIC
            {
				//La sentencia almacena el valor de la direccion del goto cuando es true. 
				//Sirve para saber que instrucciones se deben completar añadiendo la direccion a la expresion del bucle.
				$$ = new vector<int>($3->trues);
				codigo.completarInstrucciones($3->falses, codigo.obtenRef());
				delete $3;
            }


            | TREAD TLPAREN variable TRPAREN TSEMIC 
            {
				codigo.anadirInstruccion("read " + *$3 + ";");
				delete $3;
				$$ = new vector<int>();
            }


            | TPRINT TLPAREN expresion TRPAREN TSEMIC
            {
				codigo.anadirInstruccion("write " + $3->str + ";");
				codigo.anadirInstruccion("writeln;");
				delete $3;
				$$ = new vector<int>();
            }
            ;



M:  { $$ = codigo.obtenRef() ; }
	;



variable : TIDENTIFIER {$$ = $1;}
           ;



expresion : expresion TOR M expresion
			{
				codigo.completarInstrucciones($1->falses, $3);
				$$ = new expresionstruct;

				expresionstruct tmp;
				tmp.trues = *unir($1->trues, $4->trues);
				tmp.falses = $4->falses;
				*$$ = tmp;
			}

			| expresion TAND M expresion
			{
				codigo.completarInstrucciones($1->trues, $3);
				$$ = new expresionstruct;

			   	expresionstruct tmp;
				tmp.trues = $4->trues;
				tmp.falses = *unir($1->falses, $4->falses);
				*$$ = tmp;
			}


			| TNOT expresion
			{
				$$ = new expresionstruct;
				expresionstruct tmp;

				tmp.trues = $2->falses;
				tmp.falses = $2->trues;

				*$$ = tmp;
			}
			
			|expresion TEQUAL expresion 
			{ 
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3;  
			}
            
            
            | expresion TGREATER expresion
			{ 
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3; 
			}
            
            
            | expresion TFEWER expresion 
			{ 
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3; 
			}
            
            
            | expresion TGREATEQ expresion 
			{
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3; 
			}
            
            
            | expresion TFEWEQ expresion 
			{
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3; 
			}
            
            
            | expresion TNOTEQ expresion 
			{ 
                $$ = new expresionstruct;
			    *$$ = makecomparison($1->str,*$2,$3->str) ; 
			    delete $1; 
				delete $3; 
			}


            | expresion TPLUS expresion 
			{
				$$ = new expresionstruct;
			    *$$ = makearithmetic($1->str,*$2,$3->str) ;
			    delete $1; 
				delete $3;
            }


            | expresion TMINUS expresion 
			{
				$$ = new expresionstruct;
			    *$$ = makearithmetic($1->str,*$2,$3->str) ;
			    delete $1; 
				delete $3;
            }


            | expresion TMUL expresion
			{
				$$ = new expresionstruct;
			    *$$ = makearithmetic($1->str,*$2,$3->str) ;
			    delete $1; 
				delete $3;
            }

            | expresion TDIV expresion 
			{
				$$ = new expresionstruct;
			    *$$ = makearithmetic($1->str,*$2,$3->str) ;
			    delete $1; 
				delete $3;
            }

            
            | TINTEGER {$$ = new expresionstruct; $$->str = *$1;}
            | TFLOAT {$$ = new expresionstruct; $$->str = *$1;}
            | TLPAREN expresion TRPAREN 
			{
				$$ = new expresionstruct;
				$$ = $2;

				$$->trues = $2->trues;
				$$->falses = $2->falses;
			}
			| TIDENTIFIER {$$ = new expresionstruct; $$->str = *$1;}
			;


%%

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) 
{
	expresionstruct tmp; 
	tmp.trues.push_back(codigo.obtenRef());
	tmp.falses.push_back(codigo.obtenRef()+1);
	codigo.anadirInstruccion("if " + s1 +" "+ s2 +" "+ s3 + " goto");
	codigo.anadirInstruccion("goto");
	return tmp;
}
	
expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) 
{
	expresionstruct tmp; 
	tmp.str = codigo.nuevoId();
	codigo.anadirInstruccion(tmp.str + " := " + s1 +" "+ s2+" " + s3 + ";");     
	return tmp;
}

vector<int> *unir(vector<int> lis1, vector<int> lis2)
{
	vector<int>* v = new vector<int>(lis1);
	v->insert(v->end(), lis2.begin(), lis2.end());
	return v;
}

void fixSkips(vector<int> lis1)
{
	for(std::vector<int>::iterator i=lis1.begin(); i!=lis1.end(); ++i)
	{
		codigo.completarInstrucciones(*(new vector<int>(1,*i)), *i+2); 
	}
}
