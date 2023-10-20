/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "PhaseB.y" /* yacc.c:339  */

    /* Prologue */
    #include "PhaseD.h"

    

#line 73 "PhaseB.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "PhaseB.h".  */
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
#line 17 "PhaseB.y" /* yacc.c:355  */

    char* stringValue;
    int intValue;
    double realValue;
    struct SymbolList *symbol;
    struct expr *exprValue;
    struct expr *next;
    struct funcCall *funCall;

#line 281 "PhaseB.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHASEB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "PhaseB.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   633

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    88,    92,    94,    95,   107,   108,   109,
     110,   111,   115,   118,   120,   121,   122,   123,   127,   131,
     138,   144,   153,   159,   165,   174,   183,   192,   201,   209,
     217,   224,   231,   252,   256,   267,   275,   282,   282,   291,
     298,   298,   307,   310,   334,   338,   341,   345,   349,   353,
     356,   378,   384,   388,   391,   395,   402,   403,   406,   417,
     442,   449,   452,   455,   465,   475,   479,   489,   495,   510,
     528,   532,   542,   550,   550,   555,   555,   561,   569,   561,
     578,   602,   603,   578,   614,   618,   622,   626,   630,   634,
     640,   647,   658,   661,   662,   665,   665,   669,   672,   672,
     676,   682
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONST_INT", "CONST_FLOAT",
  "STRING", "AUTO", "CASE", "CHAR", "DEFAULT", "DO", "DOUBLE", "ENUM",
  "EXTERN", "FLOAT", "GOTO", "INT", "LONG", "REGISTER", "SHORT", "SIGNED",
  "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOID", "VOLATILE", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN",
  "BREAK", "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE", "FALSE", "NIL",
  "EQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODERATE",
  "ASSIGNATION", "NOT_EQUAL", "PLUS_PLUS", "MINUS_MINUS", "GREATER_THAN",
  "LESS_THAN", "GREATER_EQUAL", "LESS_EQUAL", "QUESTION_MARK", "AMPERSAND",
  "UMINUS", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT",
  "APOSTROPHE", "DEBUG", "LINE_COMMENT", "BLOCK_COMMENT", "BASIC_IF",
  "$accept", "program", "stmts", "M", "stmt", "expr", "term", "$@1", "$@2",
  "assignexpr", "primary", "Debugger", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "block", "$@3", "$@4", "funcdef", "$@5", "$@6", "$@7",
  "$@8", "$@9", "const", "idlist", "ifstmt", "whilestmt", "$@10", "dostmt",
  "forstmt", "$@11", "returnstmt", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};
# endif

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-74)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -175,     2,   178,  -175,  -175,  -175,  -175,  -175,   -53,   -37,
     -14,   -11,    12,   224,   -24,   -10,   325,    82,  -175,  -175,
    -175,   325,     8,     8,    40,   255,   271,  -175,   111,  -175,
    -175,   -25,  -175,  -175,  -175,  -175,    57,  -175,   -38,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   178,   325,
     325,   325,  -175,  -175,  -175,   303,  -175,  -175,  -175,  -175,
    -175,    71,   -16,   -38,   -16,    59,   178,   325,   531,   -23,
     -18,  -175,   376,    53,  -175,  -175,  -175,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,  -175,   325,
     325,   325,   124,   126,    80,    89,  -175,  -175,  -175,   325,
     325,   143,    90,   399,   422,    47,    86,   152,  -175,  -175,
      88,  -175,  -175,    42,  -175,   325,  -175,    99,  -175,   104,
     325,   325,   560,    -9,    -9,  -175,  -175,  -175,   560,   101,
     101,   101,   101,   531,   468,   -61,  -175,   106,  -175,  -175,
     489,   -50,  -175,   145,   178,  -175,   325,  -175,  -175,    -8,
     104,   132,   325,   531,  -175,   325,   574,   546,  -175,  -175,
     325,  -175,  -175,   112,   153,   178,   352,   152,  -175,   185,
    -175,   510,    -7,    14,   325,   178,  -175,   325,    26,   127,
    -175,  -175,  -175,  -175,   445,  -175,    35,  -175,  -175,  -175,
    -175,   127,   178,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    50,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      87,     0,     0,     0,    75,    67,     0,    16,     0,    49,
       3,     0,    32,    18,    42,    17,    44,    53,    45,    46,
      14,    15,    48,     7,     8,     9,    10,    11,     0,     0,
       0,    67,    80,    77,     5,     0,    12,    13,    35,    51,
      34,     0,    36,     0,    39,     0,     0,     0,    65,     0,
       0,    70,     0,     0,    52,     5,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,    67,     0,     0,     0,     0,    59,    61,    62,     0,
      67,     0,     0,     0,     0,     0,     0,    92,   100,   101,
       0,    74,     4,     0,    68,     0,    69,     0,    33,    47,
       0,     0,    28,    19,    20,    21,    22,    23,    29,    24,
      26,    25,    27,    43,     0,     0,    54,     0,    38,    41,
       0,     0,    56,     0,     0,    95,     0,    81,    90,     0,
       0,     0,     0,    66,    71,    67,    30,    31,    55,    63,
      67,    57,    58,     0,    93,     0,     0,    92,    78,     0,
      76,     0,     0,     0,     0,     0,    96,    67,     0,     0,
      91,    72,    60,    64,     0,    94,     0,    82,    79,    97,
      98,     0,     0,    83,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,    79,    44,   -47,   -13,  -175,  -175,  -175,  -175,
    -175,  -175,   103,  -175,   118,  -175,  -175,  -175,   -45,  -175,
    -175,    75,  -174,  -175,  -175,   -22,  -175,  -175,  -175,  -175,
    -175,  -175,    27,  -175,  -175,  -175,  -175,  -175,  -175,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   108,    30,    31,    32,    94,    95,    33,
      34,    35,    36,    37,    38,    96,    97,    98,    69,    39,
      70,    71,    40,    65,    66,    41,   107,   179,   106,   167,
     191,    42,   149,    43,    44,   165,    45,    46,   192,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   102,     3,    58,    73,   188,   105,   159,    60,   115,
      48,     4,    68,    72,    75,    52,    76,   193,   162,   112,
     115,    77,    78,    79,    80,    81,    82,    99,    83,   100,
      49,    84,    85,    86,    87,   101,   103,   104,    68,   110,
      80,    81,    82,   114,    88,    56,   135,   115,   116,    90,
      17,    91,   117,    50,   113,   141,    51,    92,    93,    57,
     168,   182,   169,   115,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    61,   133,   134,    68,    53,
      28,    75,   183,    76,   115,    59,   140,    68,    77,    78,
      79,    80,    81,    82,   187,    83,   169,   164,    84,    85,
      86,    87,   153,   190,   -73,   115,    12,   156,   157,    89,
     172,   -37,   -40,   152,    74,   173,   146,   115,   176,   120,
     121,   119,    90,   111,    91,    62,    64,   136,   185,   137,
      92,    93,   186,   166,   138,     4,     5,     6,     7,   171,
      63,    63,    68,     8,   139,   194,   142,    68,    78,    79,
      80,    81,    82,   147,   143,   148,   150,   -74,   -74,   -74,
     -74,   184,    67,     9,    68,    10,    11,    12,    13,    14,
      15,   155,    16,   160,    17,    18,    19,    20,   163,   174,
      21,     4,     5,     6,     7,   175,    22,    23,   180,     8,
      24,   151,   154,     0,   178,    24,   170,    25,     0,    26,
       0,    27,     0,     0,    28,     0,     0,     0,    29,     9,
       0,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,     0,     0,    21,     4,     5,     6,
       7,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    25,     0,    26,     0,    27,     0,     0,
      28,     0,     0,     0,    29,     0,     0,     0,     4,     5,
       6,     7,     0,     0,    16,     0,    17,    18,    19,    20,
       0,     0,    21,     0,     4,     5,     6,     7,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,     0,    54,     0,    16,    28,    17,    18,    19,
      20,     0,     0,    21,     0,     0,    12,     0,     0,    22,
      23,    16,     0,    17,    18,    19,    20,     0,    67,    21,
      25,     0,    26,     0,     0,    22,    23,    28,     4,     5,
       6,     7,     0,     0,     0,     0,    25,     0,    26,     0,
       0,     0,    75,    28,    76,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,     0,    83,     0,     0,    84,
      85,    86,    87,     0,     0,    16,     0,    17,    18,    19,
      20,     0,   109,    21,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    75,    26,    76,     0,     0,     0,    28,    77,    78,
      79,    80,    81,    82,     0,    83,     0,     0,    84,    85,
      86,    87,     0,     0,     0,    75,     0,    76,     0,     0,
       0,   177,    77,    78,    79,    80,    81,    82,     0,    83,
       0,     0,    84,    85,    86,    87,     0,     0,    75,     0,
      76,     0,     0,     0,   118,    77,    78,    79,    80,    81,
      82,     0,    83,     0,     0,    84,    85,    86,    87,     0,
       0,    75,     0,    76,     0,     0,     0,   144,    77,    78,
      79,    80,    81,    82,     0,    83,     0,     0,    84,    85,
      86,    87,     0,     0,    75,     0,    76,     0,     0,     0,
     145,    77,    78,    79,    80,    81,    82,     0,    83,     0,
       0,    84,    85,    86,    87,     0,     0,    75,     0,    76,
       0,     0,     0,   189,    77,    78,    79,    80,    81,    82,
       0,    83,     0,     0,    84,    85,    86,    87,    75,     0,
      76,     0,     0,     0,   158,    77,    78,    79,    80,    81,
      82,     0,    83,     0,     0,    84,    85,    86,    87,    75,
       0,    76,     0,     0,     0,   161,    77,    78,    79,    80,
      81,    82,     0,    83,     0,     0,    84,    85,    86,    87,
      75,     0,    76,     0,   181,     0,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    75,     0,    84,    85,    86,
      87,     0,    77,    78,    79,    80,    81,    82,     0,    83,
       0,     0,    84,    85,    86,    87,   -74,    78,    79,    80,
      81,    82,     0,   -74,     0,     0,    84,    85,    86,    87,
      77,    78,    79,    80,    81,    82,     0,    83,     0,     0,
      84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      13,    48,     0,    16,    26,   179,    51,    68,    21,    70,
      63,     3,    25,    26,    39,     3,    41,   191,    68,    66,
      70,    46,    47,    48,    49,    50,    51,    65,    53,    67,
      67,    56,    57,    58,    59,    73,    49,    50,    51,    61,
      49,    50,    51,    66,    69,    69,    91,    70,    66,    65,
      42,    67,    70,    67,    67,   100,    67,    73,    74,    69,
      68,    68,    70,    70,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    67,    89,    90,    91,    67,
      72,    39,    68,    41,    70,     3,    99,   100,    46,    47,
      48,    49,    50,    51,    68,    53,    70,   144,    56,    57,
      58,    59,   115,    68,    64,    70,    35,   120,   121,    52,
     155,    54,    55,    71,     3,   160,    69,    70,   165,    75,
      76,    68,    65,    64,    67,    22,    23,     3,   175,     3,
      73,    74,   177,   146,    54,     3,     4,     5,     6,   152,
      22,    23,   155,    11,    55,   192,     3,   160,    47,    48,
      49,    50,    51,    67,    64,     3,    68,    56,    57,    58,
      59,   174,    63,    31,   177,    33,    34,    35,    36,    37,
      38,    67,    40,    67,    42,    43,    44,    45,    33,    67,
      48,     3,     4,     5,     6,    32,    54,    55,     3,    11,
      63,   112,   117,    -1,   167,    63,    64,    65,    -1,    67,
      -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    76,    31,
      -1,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    48,     3,     4,     5,
       6,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    48,    -1,     3,     4,     5,     6,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    67,    -1,    69,    -1,    40,    72,    42,    43,    44,
      45,    -1,    -1,    48,    -1,    -1,    35,    -1,    -1,    54,
      55,    40,    -1,    42,    43,    44,    45,    -1,    63,    48,
      65,    -1,    67,    -1,    -1,    54,    55,    72,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    65,    -1,    67,    -1,
      -1,    -1,    39,    72,    41,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    -1,    53,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    40,    -1,    42,    43,    44,
      45,    -1,    69,    48,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    39,    67,    41,    -1,    -1,    -1,    72,    46,    47,
      48,    49,    50,    51,    -1,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,
      -1,    69,    46,    47,    48,    49,    50,    51,    -1,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    68,    46,    47,    48,    49,    50,
      51,    -1,    53,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    39,    -1,    41,    -1,    -1,    -1,    68,    46,    47,
      48,    49,    50,    51,    -1,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      68,    46,    47,    48,    49,    50,    51,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    39,    -1,    41,
      -1,    -1,    -1,    68,    46,    47,    48,    49,    50,    51,
      -1,    53,    -1,    -1,    56,    57,    58,    59,    39,    -1,
      41,    -1,    -1,    -1,    66,    46,    47,    48,    49,    50,
      51,    -1,    53,    -1,    -1,    56,    57,    58,    59,    39,
      -1,    41,    -1,    -1,    -1,    66,    46,    47,    48,    49,
      50,    51,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      39,    -1,    41,    -1,    64,    -1,    -1,    46,    47,    48,
      49,    50,    51,    -1,    53,    39,    -1,    56,    57,    58,
      59,    -1,    46,    47,    48,    49,    50,    51,    -1,    53,
      -1,    -1,    56,    57,    58,    59,    46,    47,    48,    49,
      50,    51,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      46,    47,    48,    49,    50,    51,    -1,    53,    -1,    -1,
      56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,    82,     0,     3,     4,     5,     6,    11,    31,
      33,    34,    35,    36,    37,    38,    40,    42,    43,    44,
      45,    48,    54,    55,    63,    65,    67,    69,    72,    76,
      84,    85,    86,    89,    90,    91,    92,    93,    94,    99,
     102,   105,   111,   113,   114,   116,   117,   119,    63,    67,
      67,    67,     3,    67,    69,    85,    69,    69,    85,     3,
      85,    67,    92,    94,    92,   103,   104,    63,    85,    98,
     100,   101,    85,   105,     3,    39,    41,    46,    47,    48,
      49,    50,    51,    53,    56,    57,    58,    59,    69,    52,
      65,    67,    73,    74,    87,    88,    95,    96,    97,    65,
      67,    73,    84,    85,    85,    98,   108,   106,    83,    69,
     105,    64,    84,    85,    66,    70,    66,    70,    68,    68,
      83,    83,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    98,     3,     3,    54,    55,
      85,    98,     3,    64,    68,    68,    69,    67,     3,   112,
      68,    82,    71,    85,   101,    67,    85,    85,    66,    68,
      67,    66,    68,    33,    84,   115,    85,   109,    68,    70,
      64,    85,    98,    98,    67,    32,    84,    69,   112,   107,
       3,    64,    68,    68,    85,    84,    98,    68,   102,    68,
      68,   110,   118,   102,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    82,    82,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    87,    86,    86,
      88,    86,    86,    89,    90,    90,    90,    90,    90,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    96,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   103,   102,   104,   102,   106,   107,   105,
     108,   109,   110,   105,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   113,   113,   115,   114,   116,   118,   117,
     119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     1,     3,     2,     2,     2,     0,     3,     2,
       0,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     2,     2,     1,     3,     4,     3,     4,     4,     2,
       6,     1,     1,     3,     5,     1,     3,     0,     3,     3,
       1,     3,     5,     0,     3,     0,     5,     0,     0,     7,
       0,     0,     0,     9,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     5,     7,     0,     6,     8,     0,    10,
       3,     3
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
#line 82 "PhaseB.y" /* yacc.c:1646  */
    {
                                    Emit(_exit,NULL,NULL,NULL,currQuad,linecounter);
                                    printf("Grammar: program(1) | stmts\n");
                                }
#line 1615 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "PhaseB.y" /* yacc.c:1646  */
    {
                                    StmtReset();
                                    printf("Grammar: stmts(1) | stmts stmt\n");
                                }
#line 1624 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.intValue)=currQuad;}
#line 1630 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "PhaseB.y" /* yacc.c:1646  */
    {
                                        if((yyvsp[-1].exprValue)->type == boolexpr_e){
                                            
                                            BackPatch((yyvsp[-1].exprValue)->trueList,currQuad);
                                            printf("%s\n\n\n",(yyvsp[-1].exprValue)->strConst);
                                            Emit(assign,(yyvsp[-1].exprValue),NewConstBoolExpr('t'),NULL,currQuad,linecounter);
                                            Emit(jump,NewConstNumExpr(currQuad+2),NULL,NULL,currQuad,linecounter);
                                            BackPatch((yyvsp[-1].exprValue)->falseList,currQuad);
                                            Emit(assign,(yyvsp[-1].exprValue),NewConstBoolExpr('f'),NULL,currQuad,linecounter);
                                        }
                                        printf("Grammar: stmt(1) | expr SEMICOLON\n");
                                    }
#line 1647 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: stmt(2) | ifstmt\n");}
#line 1653 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 8:
#line 108 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: stmt(3) | whilestmt\n");}
#line 1659 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: stmt(4) | dostmt\n");}
#line 1665 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: stmt(5) | forstmt \n");}
#line 1671 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 11:
#line 111 "PhaseB.y" /* yacc.c:1646  */
    {  if(_flag[_isFunction] == 0)Error("Not in a function");
                                        else _flag[_isFunction]--;
                                        (yyval.exprValue)=NULL;
                                        printf("Grammar: stmt(6) | returnstmt\n");}
#line 1680 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isLoop]==0)Error("Not in a loop");
                                        else _flag[_isLoop]--;
                                        printf("Grammar: stmt(7) | BREAK SEMICOLON\n");}
#line 1688 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isLoop]==0)Error("Not in a loop");
                                        printf("Grammar: stmt(8) | CONTINUE SEMICOLON\n");}
#line 1695 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: stmt(9) | block\n");}
#line 1701 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: stmt(10) | funcdef\n");}
#line 1707 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: stmt(11) | SEMICOLON\n");}
#line 1713 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 18:
#line 127 "PhaseB.y" /* yacc.c:1646  */
    {
                                                (yyval.exprValue) = (yyvsp[0].exprValue);
                                                printf("Grammar: expr(1) | assignexpr\n");
                                            }
#line 1722 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                /* Check for type Compatibility */
                                                if((yyvsp[-2].exprValue)->type==constbool_e || (yyvsp[0].exprValue)->type==constbool_e)Error("Incompatible Types");
                                                (yyval.exprValue)= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(add, (yyval.exprValue), (yyvsp[-2].exprValue), (yyvsp[0].exprValue), currQuad, linecounter);
                                                printf("Grammar: expr(2) | expr PLUS expr\n");
                                            }
#line 1734 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "PhaseB.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[-2].exprValue)->type==constbool_e || (yyvsp[0].exprValue)->type==constbool_e)Error("Incompatible Types");
                                                (yyval.exprValue)= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(sub, (yyval.exprValue), (yyvsp[-2].exprValue), (yyvsp[0].exprValue), currQuad, linecounter);
                                                printf("Grammar: expr(3) | expr MINUS expr\n");
                                            }
#line 1745 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "PhaseB.y" /* yacc.c:1646  */
    {
                                                //char *newTemp = (char *)NewTemporaryID();
                                                //InsertToSymbolList(Local_Variable,newTemp,_currentScope,linecounter);
                                                //struct SymbolList *temp = SearchSymbolInListInScope(newTemp,_currentScope);
                                                if((yyvsp[-2].exprValue)->type==constbool_e || (yyvsp[0].exprValue)->type==constbool_e)Error("Incompatible Types");
                                                (yyval.exprValue)= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(mul, (yyval.exprValue), (yyvsp[-2].exprValue), (yyvsp[0].exprValue), currQuad, linecounter);
                                                printf("Grammar: expr(4) | expr MULTIPLY expr\n");
                                            }
#line 1759 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                if((yyvsp[-2].exprValue)->type==constbool_e || (yyvsp[0].exprValue)->type==constbool_e)Error("Incompatible Types");
                                                (yyval.exprValue)= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(ddiv, (yyval.exprValue), (yyvsp[-2].exprValue), (yyvsp[0].exprValue), currQuad, linecounter);
                                                printf("Grammar: expr(5) | expr DIVIDE expr\n");
                                            }
#line 1770 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                if((yyvsp[-2].exprValue)->type==constbool_e || (yyvsp[0].exprValue)->type==constbool_e)Error("Incompatible Types");
                                                (yyval.exprValue)= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(mod, (yyval.exprValue), (yyvsp[-2].exprValue), (yyvsp[0].exprValue), currQuad, linecounter);
                                                printf("Grammar: expr(6) | expr MODERATE expr\n");
                                            }
#line 1781 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 24:
#line 165 "PhaseB.y" /* yacc.c:1646  */
    {   
                                            
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_greater,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(7) | expr GREATER_THAN expr\n");
                                            }
#line 1795 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_greatereq,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(8) | expr GREATER_EQUAL expr\n");
                                            }
#line 1809 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "PhaseB.y" /* yacc.c:1646  */
    {
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                printf("%s\n\n",(yyval.exprValue)->sym->nameOfSymbol);
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_less,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(9) | expr LESS_THAN expr\n");
                                            }
#line 1823 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 27:
#line 192 "PhaseB.y" /* yacc.c:1646  */
    {
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                printf("%s\n\n",(yyval.exprValue)->sym->nameOfSymbol);
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_lesseq,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(10) | expr LESS_EQUAL expr\n");
                                            }
#line 1837 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 28:
#line 201 "PhaseB.y" /* yacc.c:1646  */
    {
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_eq,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(11) | expr EQUAL expr\n");
                                            }
#line 1850 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = NewLabelList(currQuad);
                                                (yyval.exprValue)->falseList = NewLabelList(currQuad+1);
                                                Emit(if_noteq,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(12) | expr NOT_EQUAL expr\n");
                                            }
#line 1863 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "PhaseB.y" /* yacc.c:1646  */
    {  
                                                BackPatch((yyvsp[-3].exprValue)->trueList,(yyvsp[-1].intValue));
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = (yyvsp[0].exprValue)->trueList;
                                                (yyval.exprValue)->falseList = Merge((yyvsp[-3].exprValue)->falseList,(yyvsp[0].exprValue)->falseList);
                                                printf("Grammar: expr(13) | expr AND expr\n");
                                            }
#line 1875 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "PhaseB.y" /* yacc.c:1646  */
    {
                                                BackPatch((yyvsp[-3].exprValue)->falseList,(yyvsp[-1].intValue));
                                                (yyval.exprValue) = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                (yyval.exprValue)->trueList = Merge((yyvsp[-3].exprValue)->trueList,(yyvsp[0].exprValue)->trueList);
                                                (yyval.exprValue)->falseList = (yyvsp[0].exprValue)->falseList;
                                                printf("Grammar: expr(14) | expr OR expr\n");
                                            }
#line 1887 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 32:
#line 231 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: expr(15) | term\n");}
#line 1893 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 33:
#line 252 "PhaseB.y" /* yacc.c:1646  */
    {
                                                            (yyval.exprValue) = (yyvsp[-1].exprValue);
                                                            printf("Grammar: term(1) | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                        }
#line 1902 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 34:
#line 256 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                            char *newTemp = (char *)NewTemporaryID();
                                                            InsertToSymbolList(Local_Variable,newTemp,_currentScope,linecounter,currScopeSpace);
                                                            struct SymbolList *temp = SearchSymbolInListInScope(newTemp,_currentScope);
                                                            (yyval.exprValue) = NewUminusExpr((yyvsp[0].exprValue));
                                                            (yyval.exprValue)->sym = temp;
                                                            Emit(uminus,(yyval.exprValue),(yyvsp[0].exprValue),NewConstNumExpr(-1),currQuad,linecounter);
                                                            

                                                            printf("Grammar: term(2) | MINUS expr %prec UMINUS\n");
                                                        }
#line 1918 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 35:
#line 267 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                            (yyval.exprValue) = NewExpr(boolexpr_e);
                                                            (yyval.exprValue)->sym = (yyvsp[0].exprValue)->sym;
                                                            (yyval.exprValue)->strConst = strdup((yyvsp[0].exprValue)->sym->nameOfSymbol);
                                                            (yyval.exprValue)->trueList = (yyvsp[0].exprValue)->falseList;
                                                            (yyval.exprValue)->falseList = (yyvsp[0].exprValue)->trueList;
                                                            printf("Grammar: term(3) | NOT expr\n");
                                                        }
#line 1931 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 36:
#line 275 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                            struct SymbolList *temp = SearchSymbolInList((yyvsp[0].exprValue)->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (++lvalue)");
                                                            (yyval.exprValue) = (yyvsp[0].exprValue);
                                                            Emit(add,(yyval.exprValue),(yyval.exprValue),NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(4) | PLUS_PLUS lvalue \n");
                                                        }
#line 1943 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 37:
#line 282 "PhaseB.y" /* yacc.c:1646  */
    { 
                                                            struct SymbolList *temp = SearchSymbolInList((yyvsp[0].exprValue)->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (lvalue++)");
                                                        }
#line 1952 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 38:
#line 286 "PhaseB.y" /* yacc.c:1646  */
    {
                                                            (yyval.exprValue) = (yyvsp[-2].exprValue);
                                                            Emit(add,(yyval.exprValue),(yyval.exprValue),NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(5) | lvalue PLUS_PLUS\n");
                                                        }
#line 1962 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 39:
#line 291 "PhaseB.y" /* yacc.c:1646  */
    {
                                                            struct SymbolList *temp = SearchSymbolInList((yyvsp[0].exprValue)->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (--lvalue)");
                                                            (yyval.exprValue) = (yyvsp[0].exprValue);
                                                            Emit(sub,(yyval.exprValue),(yyval.exprValue),NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(6) | MINUS_MINUS lvalue\n");
                                                        }
#line 1974 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 40:
#line 298 "PhaseB.y" /* yacc.c:1646  */
    { 
                                                            struct SymbolList *temp = SearchSymbolInList((yyvsp[0].exprValue)->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (lvalue--)");
                                                        }
#line 1983 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 41:
#line 302 "PhaseB.y" /* yacc.c:1646  */
    {
                                                            (yyval.exprValue) = (yyvsp[-2].exprValue);
                                                            Emit(sub,(yyval.exprValue),(yyval.exprValue),NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(7) | lvalue MINUS_MINUS\n");
                                                        }
#line 1993 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 42:
#line 307 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue);printf("Grammar: term(8) | primary\n");}
#line 1999 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 43:
#line 310 "PhaseB.y" /* yacc.c:1646  */
    {  
                                                    if((yyvsp[0].exprValue)->type == boolexpr_e){
                                                        (yyvsp[0].exprValue)->sym = NewTemporarySymbol();
                                                        BackPatch((yyvsp[0].exprValue)->trueList,currQuad);
                                                        Emit(assign,(yyvsp[0].exprValue),NewConstBoolExpr('t'),NULL,currQuad,linecounter);
                                                        Emit(jump,NewConstNumExpr(currQuad+2),NULL,NULL,currQuad,linecounter);
                                                        BackPatch((yyvsp[0].exprValue)->falseList,currQuad);
                                                    }
                                                    if((yyvsp[-2].exprValue)->type == tableitem_e){
                                                        Emit(tablesetelem,(yyvsp[0].exprValue),(yyvsp[-2].exprValue),(yyvsp[-2].exprValue)->index,currQuad,linecounter);
                                                        (yyval.exprValue) = EmitIfTableItem((yyvsp[-2].exprValue));
                                                        (yyval.exprValue)->type = assignexpr_e;
                                                    }
                                                    else{
                                                        Emit(assign,(yyvsp[-2].exprValue),(yyvsp[0].exprValue),NULL,currQuad,linecounter);
                                                        (yyval.exprValue)= NewAExpr(assignexpr_e,NewTemporarySymbol());
                                                        //$$->sym = NewTemporarySymbol();
                                                       
                                                        Emit(assign,(yyval.exprValue),(yyvsp[-2].exprValue),NULL,currQuad,linecounter);
                                                    }
                                                    printf("Grammar: assignexpr(1) | lvalue ASSIGNATION expr\n");
                                                }
#line 2026 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                    (yyval.exprValue) =EmitIfTableItem((yyvsp[0].exprValue));
                                                                    printf("Grammar: primary(1) | lvalue\n");
                                                                }
#line 2035 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 45:
#line 338 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                                    printf("Grammar: primary(2) | call\n");
                                                                }
#line 2043 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 46:
#line 341 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                    (yyval.exprValue)=(yyvsp[0].exprValue);
                                                                    printf("Grammar: primary(3) | objectdef\n");
                                                                }
#line 2052 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 47:
#line 345 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                                    (yyval.exprValue)=NewAExpr(programfunc_e,(yyvsp[-1].symbol));
                                                                    printf("Grammar: primary(4) | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                                }
#line 2061 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 48:
#line 349 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.exprValue)=(yyvsp[0].exprValue); printf("Grammar: primary(5) | const\n");}
#line 2067 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 49:
#line 353 "PhaseB.y" /* yacc.c:1646  */
    {printf("\x1B[32m \n-----> %d <----- \x1B[0m\n",_currentScope);}
#line 2073 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 50:
#line 356 "PhaseB.y" /* yacc.c:1646  */
    { 
                                                    /* If given Symbol exist in SymbolTable */
                                                    if (temporaryID=SearchSymbolInList(yylval.stringValue)){
                                                        if(isValidAccess(SearchSymbolInList(yylval.stringValue))){
                                                            (yyval.exprValue) = NewlvalueExpr(SearchSymbolInList(yylval.stringValue));
                                            
                                                        }
                                                        else {
                                                            Error("Can not Access Variable between functions");
                                                        }
                                                        (yyval.exprValue) = NewlvalueExpr(SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                    }
                                                    else{
                                                        if (_currentScope == 0)InsertToSymbolList(Global_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                        else InsertToSymbolList(Local_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                        (yyval.exprValue) = NewlvalueExpr(SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                        
                                                    }
                                                    expr *e = (yyval.exprValue);

                                                    printf("Grammar: lvalue(1) | IDENTIFIER\n");
                                                }
#line 2100 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 51:
#line 378 "PhaseB.y" /* yacc.c:1646  */
    {   if (SearchSymbolInListInScope(yylval.stringValue,_currentScope)==NULL){
                                                        if(_currentScope==0)InsertToSymbolList(Global_Variable,yylval.stringValue,0,linecounter,currScopeSpace);
                                                        else if(InsertToSymbolList(Local_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace)==0)Error("Variable is Shadowing a Global Function");
                                                    }
                                                    printf("Grammar: lvalue(2) | LOCAL IDENTIFIER\n");
                                                }
#line 2111 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 52:
#line 384 "PhaseB.y" /* yacc.c:1646  */
    {   if (SearchSymbolInListInScope(yylval.stringValue,0)==NULL)Error("No Global Variable with given name");
                                                    printf("Grammar: lvalue(3) | DOUBLE_COLON IDENTIFIER\n");
                                                }
#line 2119 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 53:
#line 388 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: lvalue(4) | member\n");}
#line 2125 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 54:
#line 391 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                            (yyval.exprValue) = MemberItem((yyvsp[-2].exprValue),yylval.stringValue);
                                                                            printf("Grammar: member(1) | lvalue DOT IDENTIFIER\n");
                                                                        }
#line 2134 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 55:
#line 395 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                            (yyvsp[-3].exprValue) = EmitIfTableItem((yyvsp[-3].exprValue));
                                                                            (yyval.exprValue) = NewAExpr(tableitem_e,SearchSymbolInList((yyvsp[-3].exprValue)->sym->nameOfSymbol));
                                                                            (yyval.exprValue)->sym = (yyvsp[-3].exprValue)->sym;
                                                                            (yyval.exprValue)->index = (yyvsp[-1].exprValue);
                                                                            printf("Grammar: member(2) | lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET\n");
                                                                        }
#line 2146 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 56:
#line 402 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: member(3) | call DOT IDENTIFIER\n");}
#line 2152 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 57:
#line 403 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: member(4) | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET\n");}
#line 2158 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 58:
#line 406 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                                                                struct expr* par = par = ReverseElist((yyvsp[-1].exprValue));;
                                                                                                                while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist((yyvsp[-1].exprValue));
                                                                                                                Emit(call,(yyvsp[-3].exprValue),NULL,NULL,currQuad,linecounter);
                                                                                                                Emit(getretval,NewConstStringExpr(NewTemporaryID()),NULL,NULL,currQuad,linecounter);
                                                                                                            printf("Grammar: call(1) | call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                        }
#line 2174 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 59:
#line 417 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                                                                        
                                                                                                            
                                                                                                            struct expr *par = ReverseElist((yyvsp[0].funCall)->elist);
                                                                                                            while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist((yyvsp[0].funCall)->elist);
                                                                                                                Emit(call,(yyvsp[-1].exprValue),NULL,NULL,currQuad,linecounter);
                                                                                                                Emit(getretval,NewConstStringExpr(NewTemporaryID()),NULL,NULL,currQuad,linecounter);
                                                                                                            if((yyvsp[0].funCall)->method==1){
                                                                                                                while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist((yyvsp[0].funCall)->elist);

                                                                                                            } 
                                                                                                            else{

                                                                                                            }

                                                                                                            printf("Grammar: call(2) | lvalue callsuffix\n");
                                                                                                        }
#line 2204 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 60:
#line 442 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                                                            expr* func = NewAExpr(programfunc_e, (yyvsp[-4].symbol));
                                                                                                            (yyval.exprValue) = MakeCall(func,(yyvsp[-1].exprValue));
                                                                                                            printf("Grammar: call(3) | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                        }
#line 2214 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 61:
#line 449 "PhaseB.y" /* yacc.c:1646  */
    {
                                        (yyval.funCall)=(yyvsp[0].funCall); printf("Grammar: callsuffix(1) | normcall\n");
                                    }
#line 2222 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 62:
#line 452 "PhaseB.y" /* yacc.c:1646  */
    {(yyval.funCall)=(yyvsp[0].funCall); printf("Grammar: callsuffix(2) | methodcall\n");}
#line 2228 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 63:
#line 455 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                struct funcCall *fCall = (struct funcCall*)malloc(sizeof(struct funcCall));
                                                                (yyval.funCall) = fCall;
                                                                (yyval.funCall)->elist = (yyvsp[-1].exprValue);
                                                                (yyval.funCall)->method =0;
                                                                (yyval.funCall)->funcName = NULL;
                                                                printf("Grammar: normcall(1) | LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                            }
#line 2241 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 64:
#line 465 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                                                        struct funcCall *fCall = (struct funcCall*)malloc(sizeof(struct funcCall));
                                                                                        (yyval.funCall) = fCall;
                                                                                        (yyval.funCall)->elist = (yyvsp[-1].exprValue);
                                                                                        (yyval.funCall)->method = 1;
                                                                                        (yyval.funCall) ->funcName = (yyvsp[-3].stringValue);
                                                                                        printf("Grammar: methodcall(1) | DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                    }
#line 2254 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 65:
#line 475 "PhaseB.y" /* yacc.c:1646  */
    {   
                                        (yyval.exprValue) = (yyvsp[0].exprValue);
                                        printf("Grammar: elist(1) | expr\n");
                                    }
#line 2263 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 66:
#line 479 "PhaseB.y" /* yacc.c:1646  */
    {   
                                        expr *temp = (yyvsp[-2].exprValue);
                                        
                                        while(temp->next!=NULL){
                                            temp=temp->next;
                                        }
                                        temp->next = (yyvsp[0].exprValue);
                                        (yyval.exprValue) = (yyvsp[-2].exprValue);
                                        printf("Grammar: elist(2) | elist COMMA expr\n");
                                    }
#line 2278 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 67:
#line 489 "PhaseB.y" /* yacc.c:1646  */
    {
                                        (yyval.exprValue)=NewConstNilExpr();
                                        printf("Grammar: elist(3) | /*Empty*/\n");
                                    }
#line 2287 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 68:
#line 495 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                        expr* t = NewExpr(newtable_e);
                                                                        t->sym = NewTemporarySymbol();
                                                                        t->strConst = strdup(t->sym->nameOfSymbol); 
                                                                        Emit(tablecreate,t,NULL,NULL,currQuad,linecounter);
                                                                        int i = 0;
                                                                        expr *temp = (yyvsp[-1].exprValue);
                                                                        while(temp != NULL){
                                                                            Emit(tablesetelem,temp,t,NewConstNumExpr(i),currQuad,linecounter);
                                                                            temp = temp->next;
                                                                            i++;
                                                                        }
                                                                        (yyval.exprValue) = t;
                                                                        printf("Grammar: objectdef(1) | LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET\n");
                                                                    }
#line 2307 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 69:
#line 510 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                        expr *t = NewExpr(newtable_e);
                                                                        t->sym = NewTemporarySymbol();
                                                                        t->strConst = strdup(t->sym->nameOfSymbol); 
                                                                        Emit(tablecreate,t,NULL,NULL,currQuad,linecounter);
                                                                        expr *temp = (yyvsp[-1].exprValue);
                                                                        while(temp!=NULL){
                                                                            Emit(tablesetelem,temp->next,t,temp->index,currQuad,linecounter);
                                                                            temp = temp->nextIndexed;
                                                                        }
                                                                        (yyval.exprValue) = t;
                                                                        printf("Grammar: objectdef(2) | LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET\n");
                                                                    }
#line 2325 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 70:
#line 528 "PhaseB.y" /* yacc.c:1646  */
    {
                                                    (yyval.exprValue) = (yyvsp[0].exprValue);
                                                    printf("Grammar: indexed(1) | indexedelem\n");
                                                }
#line 2334 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 71:
#line 532 "PhaseB.y" /* yacc.c:1646  */
    {
                                                    expr* temp=(yyvsp[-2].exprValue);
                                                    while(temp->nextIndexed!=NULL){
                                                        temp =temp->nextIndexed;
                                                    }
                                                    temp->nextIndexed = (yyvsp[0].exprValue);
                                                    printf("Grammar: indexed(2) | indexed COMMA indexedelem\n");
                                                }
#line 2347 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 72:
#line 542 "PhaseB.y" /* yacc.c:1646  */
    {
                                                                (yyval.exprValue) = NewExpr(tableitem_e);
                                                                (yyval.exprValue)->index = (yyvsp[-3].exprValue);
                                                                (yyval.exprValue)->next = (yyvsp[-1].exprValue);
                                                                printf("Grammar: indexedelem(1) | LEFT_BRACKET expr COLON expr RIGHT_BRACKET\n");
                                                            }
#line 2358 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 73:
#line 550 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isFunction] == 0)GenerateScope(++_currentScope);}
#line 2364 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 74:
#line 551 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isFunction] == 0)KillScope(_currentScope--);              
                                                printf("Grammar: block(1) | LEFT_BRACKET RIGHT_BRACKET\n");
                                                
                                            }
#line 2373 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 75:
#line 555 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isFunction] == 0)GenerateScope(++_currentScope); }
#line 2379 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 76:
#line 556 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isFunction] == 0)KillScope(_currentScope--);     
                                                printf("Grammar: block(2) | LEFT_BRACKET stmt stmts RIGHT_BRACKET\n");
                                            }
#line 2387 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 77:
#line 561 "PhaseB.y" /* yacc.c:1646  */
    {   
                                                _flag[_isFunction]++; 
                                                _flag[_isFormalArgs]++;
                                                _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,NewTemporaryFuncSymbol());
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);
                                                GenerateScope(++_currentScope);
                                            }
#line 2400 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 78:
#line 569 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isFormalArgs] =0;}
#line 2406 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 79:
#line 571 "PhaseB.y" /* yacc.c:1646  */
    {   _flag[_isFunction]--;
                                                KillScope(_currentScope--);
                                                (yyval.symbol) = _tempExpr[--_tempExprCounter]->sym;
                                                Emit(funcend,NewAExpr(programfunc_e,SearchSymbolInList((yyval.symbol)->nameOfSymbol)),NULL,NULL,currQuad,linecounter);
                                                _tempExpr[_tempExprCounter]==NULL;
                                                printf("Grammar: funcdef(1) | FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                            }
#line 2418 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 80:
#line 578 "PhaseB.y" /* yacc.c:1646  */
    {   struct SymbolList *temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                if (temp!=NULL){
                                                    if(temp->typeOfSymbol == User_Function)Error("Duplicate Function");
                                                    else if(temp->typeOfSymbol == Library_Function)Error("Function shadows Library Function");
                                                    else if(temp->typeOfSymbol == Global_Variable || temp->typeOfSymbol == Local_Variable || temp->typeOfSymbol == Formal_Argument)Error("Already declared as Variable");
                                                    else{
                                                        /*Valid Access */
                                                        _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                        Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                        Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);

                                                    }
                                                    
                                                }
                                                else if(InsertToSymbolList(User_Function,yylval.stringValue,_currentScope,linecounter,currScopeSpace)==0)Error("Function shadows Library Function");
                                                else{
                                                    /*Valid Access */
                                                    temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                    _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,temp); 
                                                    Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                    Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);

                                                }
                                            }
#line 2447 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 81:
#line 602 "PhaseB.y" /* yacc.c:1646  */
    {   _flag[_isFunction]++; _flag[_isFormalArgs]++; GenerateScope(++_currentScope);}
#line 2453 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 82:
#line 603 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isFormalArgs] =0;}
#line 2459 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 83:
#line 605 "PhaseB.y" /* yacc.c:1646  */
    {   _flag[_isFunction]--;
                                                KillScope(_currentScope--);
                                                (yyval.symbol) = _tempExpr[--_tempExprCounter]->sym;
                                                Emit(funcend,NewAExpr(programfunc_e,SearchSymbolInList((yyvsp[-7].stringValue))),NULL,NULL,currQuad,linecounter);
                                                _tempExpr[_tempExprCounter]==NULL;
                                                printf("Grammar: funcdef(2) | FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                            }
#line 2471 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 84:
#line 614 "PhaseB.y" /* yacc.c:1646  */
    {
                                    (yyval.exprValue) = NewConstNumExpr((yyvsp[0].intValue));
                                    printf("Grammar: const(1) | CONST_INT\n");
                                }
#line 2480 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 85:
#line 618 "PhaseB.y" /* yacc.c:1646  */
    {   
                                    (yyval.exprValue) = NewConstNumExpr((yyvsp[0].realValue));
                                    printf("Grammar: const(2) | CONST_FLOAT\n");
                                }
#line 2489 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 86:
#line 622 "PhaseB.y" /* yacc.c:1646  */
    {
                                    (yyval.exprValue) = NewConstStringExpr((yyvsp[0].stringValue));
                                    printf("Grammar: const(3) | STRING\n");
                                }
#line 2498 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 87:
#line 626 "PhaseB.y" /* yacc.c:1646  */
    {
                                    (yyval.exprValue) = NewConstNilExpr();
                                    printf("Grammar: const(4) | NIL\n");
                                }
#line 2507 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 88:
#line 630 "PhaseB.y" /* yacc.c:1646  */
    {   
                                    (yyval.exprValue) = NewConstBoolExpr('t');
                                    printf("Grammar: const(5) | TRUE\n");
                                }
#line 2516 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 89:
#line 634 "PhaseB.y" /* yacc.c:1646  */
    {   
                                    (yyval.exprValue) = NewConstBoolExpr('f');
                                    printf("Grammar: const(6) | FALSE\n");
                                }
#line 2525 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 90:
#line 640 "PhaseB.y" /* yacc.c:1646  */
    {   if (_flag[_isFormalArgs]>0){
                                                    if(IsLibraryFunction(yylval.stringValue))Error("Formal Argument Shadowing global function");
                                                    else InsertToSymbolList(Formal_Argument,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                }
                                                printf("Grammar: idlist(1) | IDENTIFIER\n");
                                            }
#line 2536 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 91:
#line 647 "PhaseB.y" /* yacc.c:1646  */
    {
                                                if (_flag[_isFormalArgs]>0){
                                                    
                                                    if(IsLibraryFunction(yylval.stringValue))Error("Formal Argument Shadowing global function");
                                                    struct SymbolList *temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                    if (temp==NULL)InsertToSymbolList(Formal_Argument,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                    else if(SearchSymbolInListInScope(yylval.stringValue,_currentScope))Error("Duplicate Formal Argument");
                            
                                                }
                                                printf("Grammar: idlist(2) | idlist COMMA IDENTIFIER\n");
                                            }
#line 2552 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 92:
#line 658 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: idlist(3) | /*Empty*/\n");}
#line 2558 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 93:
#line 661 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: ifstmt(1) | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec BASIC_IF\n");}
#line 2564 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 94:
#line 662 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: ifstmt(2) | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");}
#line 2570 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 95:
#line 665 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isLoop]++;}
#line 2576 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 96:
#line 666 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isLoop]--;printf("Grammar: whilestmt(1) | WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");}
#line 2582 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 97:
#line 669 "PhaseB.y" /* yacc.c:1646  */
    {printf("Grammar: dostmt(1) | DO LEFT_BRACKET stmt RIGHT_BRACKET WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");}
#line 2588 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 98:
#line 672 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isLoop]++;}
#line 2594 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 99:
#line 673 "PhaseB.y" /* yacc.c:1646  */
    {_flag[_isLoop]--;printf("Grammar: forstmt(1) | FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");}
#line 2600 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 100:
#line 676 "PhaseB.y" /* yacc.c:1646  */
    {   if(_flag[_isFunction]>0){
                                                    Emit(ret,NULL,NULL,NULL,currQuad,linecounter);
                                                } 
                                                printf("Grammar: returnstmt(1) | RETURN SEMICOLON\n");
                                            }
#line 2610 "PhaseB.c" /* yacc.c:1646  */
    break;

  case 101:
#line 682 "PhaseB.y" /* yacc.c:1646  */
    {
                                                Emit(ret,(yyvsp[-1].exprValue),NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: returnstmt(2) | RETURN expr SEMICOLON\n");
                                            }
#line 2619 "PhaseB.c" /* yacc.c:1646  */
    break;


#line 2623 "PhaseB.c" /* yacc.c:1646  */
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
#line 687 "PhaseB.y" /* yacc.c:1906  */







int main(int argc, char  *argv[]){
    InitLibraryFunctions();

    if(argc>1){
        if(!(yyin = fopen(argv[1],"r"))){
            fprintf(stderr,"Cannot read file : %s\n",argv[1]);
            return 1;
        }
    }
    else{
        yyin = stdin;
    }

    yyparse();
    
    PrintSymbolTable(0);
    PrintQuads();
    generateTargetCode();
    Binary();
    
    return 1;
}
