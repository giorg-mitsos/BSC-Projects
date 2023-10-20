/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PHASEB_H_INCLUDED
# define YY_YY_PHASEB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONST_INT = 259,
    CONST_FLOAT = 260,
    STRING = 261,
    AUTO = 262,
    CASE = 263,
    CHAR = 264,
    DEFAULT = 265,
    DO = 266,
    DOUBLE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    GOTO = 271,
    INT = 272,
    LONG = 273,
    REGISTER = 274,
    SHORT = 275,
    SIGNED = 276,
    SIZEOF = 277,
    STATIC = 278,
    STRUCT = 279,
    SWITCH = 280,
    TYPEDEF = 281,
    UNION = 282,
    UNSIGNED = 283,
    VOID = 284,
    VOLATILE = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    FUNCTION = 290,
    RETURN = 291,
    BREAK = 292,
    CONTINUE = 293,
    AND = 294,
    NOT = 295,
    OR = 296,
    LOCAL = 297,
    TRUE = 298,
    FALSE = 299,
    NIL = 300,
    EQUAL = 301,
    PLUS = 302,
    MINUS = 303,
    MULTIPLY = 304,
    DIVIDE = 305,
    MODERATE = 306,
    ASSIGNATION = 307,
    NOT_EQUAL = 308,
    PLUS_PLUS = 309,
    MINUS_MINUS = 310,
    GREATER_THAN = 311,
    LESS_THAN = 312,
    GREATER_EQUAL = 313,
    LESS_EQUAL = 314,
    QUESTION_MARK = 315,
    AMPERSAND = 316,
    UMINUS = 317,
    LEFT_BRACKET = 318,
    RIGHT_BRACKET = 319,
    LEFT_SQUARE_BRACKET = 320,
    RIGHT_SQUARE_BRACKET = 321,
    LEFT_PARENTHESIS = 322,
    RIGHT_PARENTHESIS = 323,
    SEMICOLON = 324,
    COMMA = 325,
    COLON = 326,
    DOUBLE_COLON = 327,
    DOT = 328,
    DOUBLE_DOT = 329,
    APOSTROPHE = 330,
    DEBUG = 331,
    LINE_COMMENT = 332,
    BLOCK_COMMENT = 333,
    BASIC_IF = 334
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONST_INT 259
#define CONST_FLOAT 260
#define STRING 261
#define AUTO 262
#define CASE 263
#define CHAR 264
#define DEFAULT 265
#define DO 266
#define DOUBLE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define GOTO 271
#define INT 272
#define LONG 273
#define REGISTER 274
#define SHORT 275
#define SIGNED 276
#define SIZEOF 277
#define STATIC 278
#define STRUCT 279
#define SWITCH 280
#define TYPEDEF 281
#define UNION 282
#define UNSIGNED 283
#define VOID 284
#define VOLATILE 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define FUNCTION 290
#define RETURN 291
#define BREAK 292
#define CONTINUE 293
#define AND 294
#define NOT 295
#define OR 296
#define LOCAL 297
#define TRUE 298
#define FALSE 299
#define NIL 300
#define EQUAL 301
#define PLUS 302
#define MINUS 303
#define MULTIPLY 304
#define DIVIDE 305
#define MODERATE 306
#define ASSIGNATION 307
#define NOT_EQUAL 308
#define PLUS_PLUS 309
#define MINUS_MINUS 310
#define GREATER_THAN 311
#define LESS_THAN 312
#define GREATER_EQUAL 313
#define LESS_EQUAL 314
#define QUESTION_MARK 315
#define AMPERSAND 316
#define UMINUS 317
#define LEFT_BRACKET 318
#define RIGHT_BRACKET 319
#define LEFT_SQUARE_BRACKET 320
#define RIGHT_SQUARE_BRACKET 321
#define LEFT_PARENTHESIS 322
#define RIGHT_PARENTHESIS 323
#define SEMICOLON 324
#define COMMA 325
#define COLON 326
#define DOUBLE_COLON 327
#define DOT 328
#define DOUBLE_DOT 329
#define APOSTROPHE 330
#define DEBUG 331
#define LINE_COMMENT 332
#define BLOCK_COMMENT 333
#define BASIC_IF 334

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "PhaseB.y" /* yacc.c:1909  */

    char* stringValue;
    int intValue;
    double realValue;
    struct SymbolList *symbol;
    struct expr *exprValue;
    struct expr *next;
    struct funcCall *funCall;

#line 222 "PhaseB.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHASEB_H_INCLUDED  */
