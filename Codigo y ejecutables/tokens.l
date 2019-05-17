%option yylineno
%option nounput 

%{
 #include <string>
 #include <iostream>
 #include <vector>
 using namespace std ;
 #include "parser.hpp" 
 using namespace std;

 #define TOKEN(t) yylval.str = new string(yytext, yyleng) ; return t 

 extern "C" int yywrap() { return(1) ; }  

%}

%option nounput

%%
"program"	            TOKEN(TPROGRAM) ;

"if"					TOKEN(TIF);

"then"					TOKEN(TTHEN);

"while"					TOKEN(TWHILE);

"for"					TOKEN(TFOR);

"from"					TOKEN(TFROM);

"to"					TOKEN(TTO);

"do"					TOKEN(TDO);

"until"					TOKEN(TUNTIL);

"else"					TOKEN(TELSE);

"skip"					TOKEN(TSKIP);

"read"					TOKEN(TREAD);

"println"				TOKEN(TPRINT);

"var"					TOKEN(TVAR);

"in out"				TOKEN(TINOUT);

"in"					TOKEN(TIN);

"out"					TOKEN(TOUT);

"float"					TOKEN(TTIPEFLOAT);

"integer"				TOKEN(TTIPEINTEGER);

"procedure"				TOKEN(TPROCEDURE);

"or"                    TOKEN(TOR);

"and"                   TOKEN(TAND);

"not"                   TOKEN(TNOT);

"=="					TOKEN(TEQUAL);

">="					TOKEN(TGREATEQ);

"<="					TOKEN(TFEWEQ);			

"/="					TOKEN(TNOTEQ);

">"						TOKEN(TGREATER);

"<"						TOKEN(TFEWER);

"="                     TOKEN(TASSIG);


\{                      TOKEN(TLBRACE);

\}                      TOKEN(TRBRACE);

\(						TOKEN(TLPAREN);

\)						TOKEN(TRPAREN);

";"                     TOKEN(TSEMIC);

","                     TOKEN(TCOMMA);

":"						TOKEN(TDOUBLEDOT);

\*	                    TOKEN(TMUL);

\+						TOKEN(TPLUS);

\-						TOKEN(TMINUS);

\/                      TOKEN(TDIV);

[0-9]+								  TOKEN(TINTEGER);

[0-9]+\.[0-9]+([eE][-+]?[0-9]+)?      TOKEN(TFLOAT);

[a-zA-Z](_?[a-zA-Z0-9])*              TOKEN(TIDENTIFIER);

\/\*(([*]+[^/*])|[^*])*[*]+\/         ;

[ \t\n\r]				;

.                       { cout << "Token desconocido: " << yytext << endl; yyterminate();}
%%


