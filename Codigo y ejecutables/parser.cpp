/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */

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
	struct expresionstruct makeNot(std::string &s1);
	//Función unir de dos vectores
	vector<int> *unir(vector<int> lis1, vector<int> lis2);

	void fixSkips(vector<int> lis1);

	Codigo codigo;


#line 95 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENTIFIER = 258,
    TINTEGER = 259,
    TFLOAT = 260,
    TMUL = 261,
    TDIV = 262,
    TPLUS = 263,
    TMINUS = 264,
    TSEMIC = 265,
    TASSIG = 266,
    TPROGRAM = 267,
    TIF = 268,
    TTHEN = 269,
    TELSE = 270,
    TWHILE = 271,
    TDO = 272,
    TUNTIL = 273,
    TSKIP = 274,
    TREAD = 275,
    TPRINT = 276,
    TVAR = 277,
    TIN = 278,
    TOUT = 279,
    TINOUT = 280,
    TTIPEFLOAT = 281,
    TTIPEINTEGER = 282,
    TPROCEDURE = 283,
    TAND = 284,
    TOR = 285,
    TEQUAL = 286,
    TGREATEQ = 287,
    TFEWEQ = 288,
    TNOTEQ = 289,
    TGREATER = 290,
    TFEWER = 291,
    TNOT = 292,
    TLBRACE = 293,
    TRBRACE = 294,
    TLPAREN = 295,
    TRPAREN = 296,
    TCOMMA = 297,
    TDOUBLEDOT = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "parser.y" /* yacc.c:355  */

    string *str ; 
    vector<string> *list ;
    struct expresionstruct *expr ;
    int number ;
    vector<int> *numlist;

#line 187 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    92,   101,   111,   110,   117,   122,   130,
     137,   143,   144,   149,   150,   155,   155,   162,   163,   168,
     168,   176,   177,   178,   183,   183,   187,   192,   195,   205,
     215,   225,   248,   262,   272,   280,   291,   296,   301,   310,
     319,   328,   337,   346,   355,   364,   373,   381,   389,   400,
     412,   425,   426,   427,   428
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TFLOAT",
  "TMUL", "TDIV", "TPLUS", "TMINUS", "TSEMIC", "TASSIG", "TPROGRAM", "TIF",
  "TTHEN", "TELSE", "TWHILE", "TDO", "TUNTIL", "TSKIP", "TREAD", "TPRINT",
  "TVAR", "TIN", "TOUT", "TINOUT", "TTIPEFLOAT", "TTIPEINTEGER",
  "TPROCEDURE", "TAND", "TOR", "TEQUAL", "TGREATEQ", "TFEWEQ", "TNOTEQ",
  "TGREATER", "TFEWER", "TNOT", "TLBRACE", "TRBRACE", "TLPAREN", "TRPAREN",
  "TCOMMA", "TDOUBLEDOT", "$accept", "programa", "$@1", "bloque",
  "declaraciones", "$@2", "lista_de_ident", "resto_lista_id", "tipo",
  "decl_de_subprogs", "decl_de_subprograma", "$@3", "argumentos",
  "lista_de_param", "$@4", "clase_par", "resto_lis_de_param", "$@5",
  "lista_de_sentencias", "sentencia", "M", "variable", "expresion", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,     4,     9,  -112,  -112,   -20,    12,    20,    19,    10,
    -112,    -7,     2,    37,     0,    10,    45,  -112,   -12,  -112,
    -112,     7,  -112,    13,    39,    17,    26,    11,     0,    48,
    -112,    -7,  -112,  -112,    57,    28,  -112,  -112,  -112,     7,
       7,   132,     7,  -112,     7,    66,     7,  -112,  -112,     7,
    -112,  -112,    19,   -20,   212,    78,     7,     7,     7,     7,
      32,  -112,  -112,     7,     7,     7,     7,     7,     7,   122,
       0,   163,    30,    91,   171,    12,    29,    35,    63,  -112,
      -5,    -5,    -1,    -1,  -112,     7,     7,   220,   220,   220,
     220,   220,   220,  -112,    38,  -112,    79,    80,  -112,  -112,
       8,  -112,  -112,     0,  -112,  -112,     0,    70,  -112,  -112,
    -112,  -112,  -112,   -12,  -112,  -112,  -112,  -112,    52,    53,
       7,    83,    84,    85,   202,    19,  -112,  -112,  -112,    64,
      58,  -112,     8,     0,   -12,    65,  -112,    93,    83,  -112,
    -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     7,     0,     0,    14,
       3,    10,     0,     0,    28,    14,     0,     8,     0,    15,
      37,     0,    36,     0,     0,     0,     0,     0,    28,     0,
      13,    10,    12,    11,     0,    18,    51,    52,    53,     0,
       0,     0,     0,    36,     0,     0,     0,     4,    27,     0,
       9,     5,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    36,    36,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     7,     0,     0,     0,    54,
      46,    47,    44,    45,    36,     0,     0,    38,    41,    42,
      43,    39,    40,    36,     0,    33,     0,     0,    29,     6,
       0,    17,    16,    28,    49,    48,    28,     0,    34,    35,
      21,    22,    23,     0,    36,    36,    36,    19,     0,     0,
       0,    26,     0,     0,     0,     0,    20,    30,    31,     0,
       0,    36,     0,    28,     0,     0,    24,     0,    26,    32,
      25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,  -112,    62,    31,  -112,   -51,    87,  -111,   101,
    -112,  -112,  -112,  -112,  -112,     1,    -4,  -112,   -28,  -112,
     -35,    90,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     7,     9,    75,    12,    17,    34,    14,
      15,    35,    53,    77,   121,   113,   126,   138,    27,    28,
      42,    29,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    76,   117,    20,     1,    56,    57,     3,    70,     4,
      36,    37,    38,    21,    32,    33,    22,    23,     6,    24,
      25,    26,    11,   136,    61,    62,    85,    86,    61,    62,
      10,   110,   111,   112,     8,    16,    54,    55,    13,    69,
      19,    71,    94,    73,    39,    18,    74,    40,    31,   103,
      47,    43,    44,    80,    81,    82,    83,    45,   106,    49,
      87,    88,    89,    90,    91,    92,    46,    51,    52,    20,
      84,    96,   100,   102,   130,   114,   101,   107,   115,   118,
     119,   120,   104,   105,    56,    57,    58,    59,   116,   108,
     109,   122,   123,   125,   127,   128,   133,    56,    57,    58,
      59,   132,   131,   139,   137,   135,    99,    61,    62,    63,
      64,    65,    66,    67,    68,    78,    30,   124,    50,    79,
      61,    62,    63,    64,    65,    66,    67,    68,    56,    57,
      58,    59,    97,   134,   140,    72,     0,     0,    56,    57,
      58,    59,     0,     0,     0,     0,    60,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      93,    61,    62,    63,    64,    65,    66,    67,    68,    56,
      57,    58,    59,    95,     0,     0,     0,    56,    57,    58,
      59,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      61,    62,    63,    64,    65,    66,    67,    68,    56,    57,
      58,    59,     0,     0,     0,     0,     0,   129,    56,    57,
      58,    59,     0,     0,     0,     0,    56,    57,    58,    59,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      28,    52,   113,     3,    12,     6,     7,     3,    43,     0,
       3,     4,     5,    13,    26,    27,    16,    17,    38,    19,
      20,    21,     3,   134,    29,    30,    61,    62,    29,    30,
      10,    23,    24,    25,    22,    42,    39,    40,    28,    42,
       3,    44,    70,    46,    37,    43,    49,    40,     3,    84,
      39,    38,    13,    56,    57,    58,    59,    40,    93,    11,
      63,    64,    65,    66,    67,    68,    40,    10,    40,     3,
      38,    41,    43,    10,   125,   103,    41,    39,   106,   114,
     115,   116,    85,    86,     6,     7,     8,     9,    18,    10,
      10,    39,    39,    10,    10,    10,   131,     6,     7,     8,
       9,    43,    38,    10,    39,   133,    75,    29,    30,    31,
      32,    33,    34,    35,    36,    53,    15,   120,    31,    41,
      29,    30,    31,    32,    33,    34,    35,    36,     6,     7,
       8,     9,    41,   132,   138,    45,    -1,    -1,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    29,    30,    31,    32,    33,    34,    35,    36,     6,
       7,     8,     9,    10,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      29,    30,    31,    32,    33,    34,    35,    36,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    15,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    29,
      30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    45,     3,     0,    46,    38,    47,    22,    48,
      10,     3,    50,    28,    53,    54,    42,    51,    43,     3,
       3,    13,    16,    17,    19,    20,    21,    62,    63,    65,
      53,     3,    26,    27,    52,    55,     3,     4,     5,    37,
      40,    66,    64,    38,    13,    40,    40,    39,    62,    11,
      51,    10,    40,    56,    66,    66,     6,     7,     8,     9,
      14,    29,    30,    31,    32,    33,    34,    35,    36,    66,
      64,    66,    65,    66,    66,    49,    50,    57,    47,    41,
      66,    66,    66,    66,    38,    64,    64,    66,    66,    66,
      66,    66,    66,    38,    62,    10,    41,    41,    10,    48,
      43,    41,    10,    64,    66,    66,    64,    39,    10,    10,
      23,    24,    25,    59,    62,    62,    18,    52,    64,    64,
      64,    58,    39,    39,    66,    10,    60,    10,    10,    15,
      50,    38,    43,    64,    59,    62,    52,    39,    61,    10,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    49,    48,    48,    50,    51,
      51,    52,    52,    53,    53,    55,    54,    56,    56,    58,
      57,    59,    59,    59,    61,    60,    60,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     5,     0,     7,     0,     2,     3,
       0,     1,     1,     2,     0,     0,     6,     3,     0,     0,
       6,     1,     1,     1,     0,     7,     0,     2,     0,     4,
       9,     9,    14,     4,     5,     5,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       2,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 92 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("prog " + *(yyvsp[0].str) + ";" );}
#line 1397 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 94 "parser.y" /* yacc.c:1646  */
    {
				codigo.anadirInstruccion("halt;");
                codigo.escribir();
			}
#line 1406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 102 "parser.y" /* yacc.c:1646  */
    {
			//En caso de haber alguna sentencia con un skip if sin haberlo completado, 
			//se ignora y redirigue a la instruccion siguiente.
			fixSkips(*(yyvsp[-1].numlist));
        }
#line 1416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "parser.y" /* yacc.c:1646  */
    {
					codigo.anadirDeclaraciones(*(yyvsp[-3].list),*(yyvsp[-1].str));
					delete (yyvsp[-3].list); delete (yyvsp[-1].str) ;
                }
#line 1425 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    {}
#line 1431 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "parser.y" /* yacc.c:1646  */
    {}
#line 1437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parser.y" /* yacc.c:1646  */
    {
					(yyval.list) = (yyvsp[0].list);
					(yyval.list)->insert((yyval.list)->begin(),*(yyvsp[-1].str));
                }
#line 1446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 131 "parser.y" /* yacc.c:1646  */
    {
					(yyval.list) = (yyvsp[0].list);
					(yyval.list)->insert((yyval.list)->begin(),*(yyvsp[-1].str)); 
                }
#line 1455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 137 "parser.y" /* yacc.c:1646  */
    {
                	(yyval.list) = new vector<string>();
                }
#line 1463 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "int";}
#line 1469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 144 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "real";}
#line 1475 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "parser.y" /* yacc.c:1646  */
    {}
#line 1481 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 150 "parser.y" /* yacc.c:1646  */
    {}
#line 1487 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("proc " + *(yyvsp[0].str) + ";" );}
#line 1493 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("endproc;");}
#line 1499 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "parser.y" /* yacc.c:1646  */
    {}
#line 1505 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "parser.y" /* yacc.c:1646  */
    {}
#line 1511 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "parser.y" /* yacc.c:1646  */
    {
                 codigo.anadirParametros(*(yyvsp[-3].list),*(yyvsp[-1].str),*(yyvsp[0].str));
                 }
#line 1519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 171 "parser.y" /* yacc.c:1646  */
    {}
#line 1525 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 183 "parser.y" /* yacc.c:1646  */
    {
                     codigo.anadirParametros(*(yyvsp[-3].list),*(yyvsp[-1].str),*(yyvsp[0].str));
                     }
#line 1533 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 186 "parser.y" /* yacc.c:1646  */
    {}
#line 1539 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "parser.y" /* yacc.c:1646  */
    {}
#line 1545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 192 "parser.y" /* yacc.c:1646  */
    {                    
                      (yyval.numlist) = unir(*(yyvsp[-1].numlist), *(yyvsp[0].numlist));
                      }
#line 1553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 195 "parser.y" /* yacc.c:1646  */
    {
                      (yyval.numlist) = new vector<int>();
                      }
#line 1561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1646  */
    {
				codigo.anadirInstruccion(*(yyvsp[-3].str) + " := " + (yyvsp[-1].expr)->str + ";");
				delete (yyvsp[-3].str); 
				delete (yyvsp[-1].expr);
				//No hay ningun skip que almacenar en la sentencia
				(yyval.numlist) = new vector<int>();
            }
#line 1573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "parser.y" /* yacc.c:1646  */
    {
				codigo.completarInstrucciones((yyvsp[-7].expr)->trues,(yyvsp[-4].number));
				codigo.completarInstrucciones((yyvsp[-7].expr)->falses,(yyvsp[-2].number));
				delete (yyvsp[-7].expr);
				//Se almacenan los skip de la lista de sentencias
				(yyval.numlist) = (yyvsp[-3].numlist);
            }
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 226 "parser.y" /* yacc.c:1646  */
    {
				codigo.completarInstrucciones((yyvsp[-6].expr)->trues,(yyvsp[-4].number));
				codigo.completarInstrucciones((yyvsp[-6].expr)->falses,(yyvsp[-2].number)+1) ; //El mas uno es para saltar el goto del final

				//Despues de terminar todas las sentencias, se vuelve a evaluar la expresion directamente. 
				//Se añade un goto para ello.
				codigo.anadirInstruccion("goto");
				vector<int> tmp1; 
				tmp1.push_back((yyvsp[-2].number));
				codigo.completarInstrucciones(tmp1, (yyvsp[-7].number));

				//Aquí se completan los skip de la lista de sentencia, 
				//que vuelven a evaluar la condicion de la expresion del while (un continue si se satisface).
				codigo.completarInstrucciones(*(yyvsp[-3].numlist),(yyvsp[-7].number));

				//Se inicializa a vector vacio la sentencia, pues todos los skip de la lista 
				//de sentencia ya se han completado.
				(yyval.numlist) = new vector<int>();
				delete (yyvsp[-6].expr);
            }
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 249 "parser.y" /* yacc.c:1646  */
    {
				codigo.completarInstrucciones((yyvsp[-6].expr)->trues,(yyvsp[-3].number));
				codigo.completarInstrucciones((yyvsp[-6].expr)->falses,(yyvsp[-11].number));

				//Los skip de la lista de sentencia saltan a evaluar la expresion. Se completa con la dirección de la expresión.
				codigo.completarInstrucciones(*(yyvsp[-10].numlist),(yyvsp[-7].number));
				
				//Se inicializa a vector vacio la sentencia, pues todos los skip de la lista de sentencia ya se han completado.
				(yyval.numlist) = new vector<int>();
				delete (yyvsp[-6].expr);
            }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 263 "parser.y" /* yacc.c:1646  */
    {
				//La sentencia almacena el valor de la direccion del goto cuando es true. 
				//Sirve para saber que instrucciones se deben completar añadiendo la direccion a la expresion del bucle.
				(yyval.numlist) = new vector<int>((yyvsp[-1].expr)->trues);
				codigo.completarInstrucciones((yyvsp[-1].expr)->falses, codigo.obtenRef());
				delete (yyvsp[-1].expr);
            }
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 273 "parser.y" /* yacc.c:1646  */
    {
				codigo.anadirInstruccion("read " + *(yyvsp[-2].str) + ";");
				delete (yyvsp[-2].str);
				(yyval.numlist) = new vector<int>();
            }
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 281 "parser.y" /* yacc.c:1646  */
    {
				codigo.anadirInstruccion("write " + (yyvsp[-2].expr)->str + ";");
				codigo.anadirInstruccion("writeln;");
				delete (yyvsp[-2].expr);
				(yyval.numlist) = new vector<int>();
            }
#line 1659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.number) = codigo.obtenRef() ; }
#line 1665 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 302 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr);  
			}
#line 1682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 311 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr); 
			}
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 320 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr); 
			}
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 329 "parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr); 
			}
#line 1715 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr); 
			}
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 347 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr); 
			}
#line 1737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 356 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr);
            }
#line 1748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 365 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr);
            }
#line 1759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 374 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr);
            }
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 382 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
			    *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
			    delete (yyvsp[-2].expr); 
				delete (yyvsp[0].expr);
            }
#line 1781 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 390 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;

				codigo.completarInstrucciones((yyvsp[-3].expr)->falses, (yyvsp[-1].number));
				expresionstruct tmp;
				tmp.trues = *unir((yyvsp[-3].expr)->trues, (yyvsp[0].expr)->trues);
				tmp.falses = (yyvsp[0].expr)->falses;
				*(yyval.expr) = tmp;
			}
#line 1795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 401 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;

			    codigo.completarInstrucciones((yyvsp[-3].expr)->trues, (yyvsp[-1].number));
			   	expresionstruct tmp;
				tmp.trues = (yyvsp[0].expr)->trues;
				tmp.falses = *unir((yyvsp[-3].expr)->falses, (yyvsp[0].expr)->falses);
				*(yyval.expr) = tmp;
			}
#line 1809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 413 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
				expresionstruct tmp;

				tmp.trues = (yyvsp[0].expr)->trues;
				tmp.falses = (yyvsp[0].expr)->falses;

				*(yyval.expr) = tmp;
			}
#line 1823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 425 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str);}
#line 1829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 426 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str);}
#line 1835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 427 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str);}
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 429 "parser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new expresionstruct;
				(yyval.expr) = (yyvsp[-1].expr);

				(yyval.expr)->trues = (yyvsp[-1].expr)->trues;
				(yyval.expr)->falses = (yyvsp[-1].expr)->falses;
			}
#line 1853 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1857 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 438 "parser.y" /* yacc.c:1906  */


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

expresionstruct makeRelational(std::string &s1, std::string &s2, std::string &s3) 
{
	expresionstruct tmp; 
	tmp.str = codigo.nuevoId();
	codigo.anadirInstruccion(tmp.str + " := " + s1 +" "+ s2+" " + s3 + ";");     
	return tmp;
}

expresionstruct makeNot(std::string &s1)
{
	expresionstruct tmp; 
	tmp.str = codigo.nuevoId();
	codigo.anadirInstruccion(tmp.str + " := not " + s1 + ";") ;     
	return tmp;
}


vector<int> *unir(vector<int> lis1, vector<int> lis2){
	vector<int>* v = new vector<int>(lis1);
	v->insert(v->end(), lis2.begin(), lis2.end());
	return v;
}

void fixSkips(vector<int> lis1){
	for(std::vector<int>::iterator i=lis1.begin(); i!=lis1.end(); ++i){
		codigo.completarInstrucciones(*(new vector<int>(1,*i)), *i+2); 
	}
}
