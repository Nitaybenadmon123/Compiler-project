/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    CHAR_LITERAL = 259,            /* CHAR_LITERAL  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    NUM = 261,                     /* NUM  */
    TYPE_INT = 262,                /* TYPE_INT  */
    TYPE_CHAR = 263,               /* TYPE_CHAR  */
    TYPE_REAL = 264,               /* TYPE_REAL  */
    TYPE_BOOL = 265,               /* TYPE_BOOL  */
    TYPE_STRING = 266,             /* TYPE_STRING  */
    TYPE_INT_PTR = 267,            /* TYPE_INT_PTR  */
    TYPE_CHAR_PTR = 268,           /* TYPE_CHAR_PTR  */
    TYPE_REAL_PTR = 269,           /* TYPE_REAL_PTR  */
    DEF = 270,                     /* DEF  */
    T_BEGIN = 271,                 /* T_BEGIN  */
    T_END = 272,                   /* T_END  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    ELIF = 275,                    /* ELIF  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    DO = 278,                      /* DO  */
    CALL = 279,                    /* CALL  */
    RETURN = 280,                  /* RETURN  */
    RETURNS = 281,                 /* RETURNS  */
    VAR = 282,                     /* VAR  */
    NULLPTR = 283,                 /* NULLPTR  */
    TRUE = 284,                    /* TRUE  */
    FALSE = 285,                   /* FALSE  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    EQ = 289,                      /* EQ  */
    NE = 290,                      /* NE  */
    GT = 291,                      /* GT  */
    GE = 292,                      /* GE  */
    LT = 293,                      /* LT  */
    LE = 294,                      /* LE  */
    ASSIGN = 295,                  /* ASSIGN  */
    PLUS = 296,                    /* PLUS  */
    MINUS = 297,                   /* MINUS  */
    MULT = 298,                    /* MULT  */
    DIV = 299,                     /* DIV  */
    ADDRESS = 300,                 /* ADDRESS  */
    COLON = 301,                   /* COLON  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COMMA = 303,                   /* COMMA  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    LBRACK = 306,                  /* LBRACK  */
    RBRACK = 307,                  /* RBRACK  */
    BAR = 308,                     /* BAR  */
    TYPE = 309                     /* TYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    struct ast_node* ast ;
    char* sval;

#line 123 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
