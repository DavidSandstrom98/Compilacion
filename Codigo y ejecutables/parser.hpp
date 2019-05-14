/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    TNOT = 286,
    TEQUAL = 287,
    TGREATEQ = 288,
    TFEWEQ = 289,
    TNOTEQ = 290,
    TGREATER = 291,
    TFEWER = 292,
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
#line 35 "parser.y" /* yacc.c:1909  */

    string *str ; 
    vector<string> *list ;
    struct expresionstruct *expr ;
    int number ;
    vector<int> *numlist;

#line 106 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
