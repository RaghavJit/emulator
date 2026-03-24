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
# define YYDEBUG 0
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
    PUSH_TOKEN = 258,              /* PUSH_TOKEN  */
    POP_TOKEN = 259,               /* POP_TOKEN  */
    IN_TOKEN = 260,                /* IN_TOKEN  */
    OUT_TOKEN = 261,               /* OUT_TOKEN  */
    DAA_TOKEN = 262,               /* DAA_TOKEN  */
    CMA_TOKEN = 263,               /* CMA_TOKEN  */
    CMC_TOKEN = 264,               /* CMC_TOKEN  */
    STC_TOKEN = 265,               /* STC_TOKEN  */
    RET_TOKEN = 266,               /* RET_TOKEN  */
    EI_TOKEN = 267,                /* EI_TOKEN  */
    DI_TOKEN = 268,                /* DI_TOKEN  */
    HLT_TOKEN = 269,               /* HLT_TOKEN  */
    NOP_TOKEN = 270,               /* NOP_TOKEN  */
    LDA_TOKEN = 271,               /* LDA_TOKEN  */
    STA_TOKEN = 272,               /* STA_TOKEN  */
    LHLD_TOKEN = 273,              /* LHLD_TOKEN  */
    SHLD_TOKEN = 274,              /* SHLD_TOKEN  */
    INX_TOKEN = 275,               /* INX_TOKEN  */
    DCX_TOKEN = 276,               /* DCX_TOKEN  */
    INR_TOKEN = 277,               /* INR_TOKEN  */
    DCR_TOKEN = 278,               /* DCR_TOKEN  */
    ADD_TOKEN = 279,               /* ADD_TOKEN  */
    SUB_TOKEN = 280,               /* SUB_TOKEN  */
    ANA_TOKEN = 281,               /* ANA_TOKEN  */
    ORA_TOKEN = 282,               /* ORA_TOKEN  */
    XRA_TOKEN = 283,               /* XRA_TOKEN  */
    CMP_TOKEN = 284,               /* CMP_TOKEN  */
    RST_TOKEN = 285,               /* RST_TOKEN  */
    MOV_TOKEN = 286,               /* MOV_TOKEN  */
    MVI_TOKEN = 287,               /* MVI_TOKEN  */
    LXI_TOKEN = 288,               /* LXI_TOKEN  */
    A_REG = 289,                   /* A_REG  */
    B_REG = 290,                   /* B_REG  */
    C_REG = 291,                   /* C_REG  */
    D_REG = 292,                   /* D_REG  */
    E_REG = 293,                   /* E_REG  */
    H_REG = 294,                   /* H_REG  */
    L_REG = 295,                   /* L_REG  */
    BC_REG = 296,                  /* BC_REG  */
    DE_REG = 297,                  /* DE_REG  */
    HL_REG = 298,                  /* HL_REG  */
    SP_REG = 299,                  /* SP_REG  */
    RSTNUM_VALUE = 300,            /* RSTNUM_VALUE  */
    DATA_VALUE = 301,              /* DATA_VALUE  */
    DATA16_VALUE = 302,            /* DATA16_VALUE  */
    ADDRESS = 303                  /* ADDRESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
