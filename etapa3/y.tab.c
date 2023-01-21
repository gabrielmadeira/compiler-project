/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "parser.y"
    #include "hash.h"
    #include "ast.h"
    int yylex(void); 
	int getLineNumber();

    void yyerror();

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 15 "parser.y"
typedef union YYSTYPE 
{
    /*HASH *symbol;*/
    struct hash_node* symbol;
    /*AST* ast;*/
    struct ast_node* ast;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_INTE 257
#define KW_CARA 258
#define KW_REAL 259
#define KW_SE 260
#define KW_ENTAUM 261
#define KW_SENAUM 262
#define KW_ENQUANTO 263
#define KW_ENTRADA 264
#define KW_ESCREVA 265
#define KW_RETORNE 266
#define OPERATOR_LE 267
#define OPERATOR_GE 268
#define OPERATOR_EQ 269
#define OPERATOR_DIF 270
#define TK_IDENTIFIER 271
#define LIT_INTEIRO 272
#define LIT_FLOAT 273
#define LIT_CHAR 274
#define LIT_STRING 275
#define TOKEN_ERROR 276
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
   13,    0,    1,    1,    1,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    4,    4,    5,    6,
    6,    7,    7,    7,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    9,   10,   10,   11,   11,
   11,   12,   12,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    7,    0,    3,    1,    3,    6,    6,
    8,    5,    2,    2,    1,    0,    4,    6,    1,    2,
    0,    2,    2,    0,    1,    1,    1,    1,    4,    4,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    1,    3,    3,    0,    1,    1,
    1,    2,    0,
};
static const YYINT yydefred[] = {                         0,
   49,   50,   51,    0,    1,    0,    0,    2,    0,    0,
    3,    0,    0,    0,    0,    0,   45,    0,   25,   27,
   26,    0,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   47,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   33,   34,   18,    0,    0,    0,    0,    0,
    0,    0,   15,    4,   52,   30,   29,   20,    0,    0,
   13,    0,    0,    0,    0,   46,    0,    0,    0,    0,
   23,   22,    0,    0,    0,    6,    0,    0,    0,    0,
    0,    0,    0,   12,   10,    0,    0,    0,   11,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  258,  259,  278,  279,  282,  289,  291,   59,  271,
  279,   40,   61,   91,  288,  289,  264,  271,  272,  273,
  274,   40,  286,  272,  283,   41,  271,   40,   91,  286,
  267,  268,  269,  270,  126,  124,   38,   60,   62,   43,
   45,   42,   47,   93,  123,  287,  288,  286,  290,  286,
   41,  286,  286,  286,  286,  286,  286,  286,  286,  286,
  286,  286,  286,  286,  284,  286,  261,  265,  266,  271,
  280,  281,  287,  279,  290,   41,   93,  284,  281,  275,
  285,  286,  286,   61,   91,  125,  263,   59,  260,  262,
  285,  285,  286,  286,   40,  280,   40,  281,   93,  286,
  286,  260,   61,   41,   41,   40,  286,  286,   41,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
    5,   71,   72,    6,   25,   65,   81,   82,   73,   15,
    7,   49,    8,
};
static const YYINT yysindex[] = {                      -138,
    0,    0,    0,    0,    0,  -57, -253,    0, -138,  -11,
    0, -138,  142, -245,  -10, -231,    0,   -7,    0,    0,
    0,  142,  675,    0,  -41,  -64, -138,  142,  142,  -28,
  142,  142,  142,  142,  142,  142,  142,  142,  142,  142,
  142,  142,  142,  142, -117, -138,    0,  362,   38,  612,
    0,   19,   19,   19,   19,  681,  124,   -6,   19,   19,
   -4,   -4,    0,    0,    0,  362, -117,  105,  142,  -49,
  -44,  -58,    0,    0,    0,    0,    0,    0, -163,  105,
    0,  321,  675,  142,  142,    0,   43, -117,   45, -117,
    0,    0,  675,  628,  142,    0,  142, -187,   28,  638,
  654,   67,  142,    0,    0,  142,  675,  665,    0,
};
static const YYINT yyrindex[] = {                       108,
    0,    0,    0,    0,    0,    0,    0,    0,  108,    0,
    0,   71,    0,    0,    0,    0,    0,  -38,    0,    0,
    0,    0,   63,    0,    0,    0,   71,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   66,  -48,  108,    0,   82,    0,    0,
    0,   31,   54,   77,  249,  389,  349,  344,  272,  295,
  -15,    8,    0,    0,    0,   66, -158,  -51,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,  -51,
    0,  -51,  -43,    0,    0,    0,    0,  -48,    0, -157,
    0,    0,  233,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  237,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   11,   39,  -32,    0,    0,   62,  -17,  780,  103,  104,
   48,   87,    0,
};
#define YYTABLESIZE 951
static const YYINT yytable[] = {                         28,
   88,    9,   28,   28,   28,   45,   28,   24,   28,   37,
   16,   84,   51,   42,   40,   14,   41,   10,   43,   11,
   28,   28,   31,   28,   31,   31,   24,   31,   12,   31,
   26,   38,   28,   39,   79,   42,   40,   42,   41,   27,
   43,   85,   43,   31,   31,   32,   31,   32,   32,   13,
   32,   44,   32,   38,   28,   39,   74,   98,   45,   16,
   42,   40,   91,   41,   92,   43,   32,   32,   40,   32,
   40,   40,  102,   24,   16,   87,   16,   31,   76,   14,
   86,   14,   95,   29,   97,   28,   28,   28,  103,   40,
   40,   41,   40,   41,   41,   36,   89,   35,   90,   87,
   32,   16,   16,   16,   16,   16,  106,    5,   31,   31,
   31,   48,   41,   41,   42,   41,   42,   42,    1,    2,
    3,   17,   53,   40,   21,    7,   96,   78,   46,    0,
   47,   32,   32,   32,   75,   42,   42,    0,   42,    0,
    0,    0,    0,   67,   22,    0,   41,   68,   69,    0,
    0,    0,    0,   70,   40,   40,   40,    0,    0,    0,
    0,   37,    0,    0,    0,   42,   40,    0,   41,   42,
   43,    0,    0,    0,    0,    0,    0,   41,   41,   41,
    0,   22,    0,   38,    0,   39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,   42,   42,    0,   87,    0,    0,    0,   24,    0,
   24,   24,    0,    0,   16,    0,   14,    0,   14,   14,
    0,   28,    0,   28,   28,   28,    0,    0,   28,   28,
   28,   28,   28,   28,   28,   28,   28,    0,   31,   32,
   33,   34,    0,    0,   31,    0,   31,   31,   31,    0,
    0,   31,   31,   31,   31,   31,   31,   31,   31,   31,
   31,   32,   33,   34,    0,    0,    0,   32,    0,   32,
   32,   32,    0,    0,   32,   32,   32,   32,   32,   32,
   32,   32,   32,    0,    0,    0,   43,    0,   43,   43,
   40,    8,   40,   40,   40,    9,    0,   40,   40,   40,
   40,   40,   40,   40,   40,   40,    0,   43,   43,   35,
   43,   35,   35,   41,    0,   41,   41,   41,    0,    0,
   41,   41,   41,   41,   41,   41,   41,   41,   41,    0,
   35,   35,   36,   35,   36,   36,   42,    0,   42,   42,
   42,   43,    0,   42,   42,   42,   42,   42,   42,   42,
   42,   42,    0,   36,   36,    0,   36,    8,   37,    0,
   22,    9,   42,   40,   35,   41,    0,   43,   17,    0,
    0,    0,   43,   43,   43,   18,   19,   20,   21,   80,
   38,   37,   39,   37,   37,    0,    0,   36,   38,   38,
   31,   32,   33,   34,    0,   35,   35,   35,    0,   37,
    0,   22,   37,   42,   40,   17,   41,   38,   43,    0,
    0,    0,   18,   19,   20,   21,    0,    0,   36,   36,
   36,   38,    0,   39,    0,    0,    0,    0,   39,   39,
    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,
    0,   38,    0,    0,   36,    0,   35,   39,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,   37,   37,
    0,    0,   38,   38,   38,    0,    0,    0,    0,    0,
    0,   39,    0,    0,    0,   36,    0,   35,    0,    0,
    0,    0,    8,    0,    8,    8,    9,    0,    9,    9,
    0,    0,    0,    0,    0,    0,    0,    0,   43,    0,
   43,   43,   43,   39,   39,   43,   43,   43,   43,   43,
   43,   43,   43,   43,    0,    0,    0,    0,    0,    0,
    0,   35,    0,   35,   35,   35,    0,    0,   35,   35,
   35,   35,   35,   35,   35,   35,   35,    0,    0,    0,
    0,    0,    0,    0,   36,    0,   36,   36,   36,    0,
    0,   36,   36,   36,   36,   36,   36,   36,   36,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   17,    0,    0,   31,   32,   33,
   34,   18,   19,   20,   21,   80,    0,    0,    0,    0,
    0,    0,    0,   37,    0,   37,   37,   37,   38,    0,
   38,   38,   38,    0,   37,   37,   37,   37,   37,   38,
   38,   38,   38,   38,    0,   17,    0,    0,   31,   32,
   33,   34,   18,   19,   20,   21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,   37,
   39,   39,   39,   42,   40,    0,   41,    0,   43,   39,
   39,   39,   39,   39,    0,   37,    0,    0,    0,   42,
   40,   38,   41,   39,   43,   37,    0,    0,  104,   42,
   40,    0,   41,    0,   43,    0,    0,   38,    0,   39,
    0,   37,    0,    0,  105,   42,   40,   38,   41,   39,
   43,    0,   37,    0,   77,  109,   42,   40,    0,   41,
    0,   43,   37,   38,    0,   39,   42,   40,   37,   41,
   99,   43,   42,   40,   38,   41,   39,   43,    0,    0,
    0,    0,    0,    0,   38,   36,   39,   35,    0,    0,
   38,    0,   39,    0,    0,    0,    0,    0,    0,    0,
    0,   36,    0,   35,    0,    0,    0,    0,    0,    0,
    0,   36,    0,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0,   35,
    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,
   35,    0,   23,    0,    0,    0,    0,    0,   36,    0,
   35,   30,    0,    0,   36,    0,    0,   48,   50,    0,
   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,
   62,   63,   64,   66,    0,    0,    0,   48,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   66,    0,    0,   83,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   93,   94,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  100,    0,  101,    0,   31,   32,
   33,   34,  107,    0,    0,  108,    0,    0,    0,    0,
    0,    0,    0,    0,   31,   32,   33,   34,    0,    0,
    0,    0,    0,    0,   31,   32,   33,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,   32,   33,   34,    0,    0,    0,    0,    0,    0,
    0,   31,   32,   33,   34,    0,    0,    0,    0,    0,
    0,   31,   32,   33,   34,    0,    0,   31,   32,   33,
   34,
};
static const YYINT yycheck[] = {                         38,
   59,   59,   41,   42,   43,  123,   45,   59,   47,   38,
   59,   61,   41,   42,   43,   59,   45,  271,   47,    9,
   59,   60,   38,   62,   40,   41,  272,   43,   40,   45,
   41,   60,   40,   62,   67,   42,   43,   42,   45,  271,
   47,   91,   47,   59,   60,   38,   62,   40,   41,   61,
   43,   93,   45,   60,   93,   62,   46,   90,  123,   12,
   42,   43,   80,   45,   82,   47,   59,   60,   38,   62,
   40,   41,  260,  125,   27,  263,  125,   93,   41,   91,
  125,  125,   40,   91,   40,  124,  125,  126,   61,   59,
   60,   38,   62,   40,   41,  124,  260,  126,  262,  263,
   93,  260,  260,  262,  263,  263,   40,    0,  124,  125,
  126,   41,   59,   60,   38,   62,   40,   41,  257,  258,
  259,   59,   41,   93,   59,  125,   88,   66,   26,   -1,
   27,  124,  125,  126,   48,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,  261,   40,   -1,   93,  265,  266,   -1,
   -1,   -1,   -1,  271,  124,  125,  126,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   93,
   47,   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,  126,
   -1,   40,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  125,  126,   -1,  263,   -1,   -1,   -1,  260,   -1,
  262,  263,   -1,   -1,  263,   -1,  260,   -1,  262,  263,
   -1,  260,   -1,  262,  263,  264,   -1,   -1,  267,  268,
  269,  270,  271,  272,  273,  274,  275,   -1,  267,  268,
  269,  270,   -1,   -1,  260,   -1,  262,  263,  264,   -1,
   -1,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  267,  268,  269,  270,   -1,   -1,   -1,  260,   -1,  262,
  263,  264,   -1,   -1,  267,  268,  269,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   38,   -1,   40,   41,
  260,   59,  262,  263,  264,   59,   -1,  267,  268,  269,
  270,  271,  272,  273,  274,  275,   -1,   59,   60,   38,
   62,   40,   41,  260,   -1,  262,  263,  264,   -1,   -1,
  267,  268,  269,  270,  271,  272,  273,  274,  275,   -1,
   59,   60,   38,   62,   40,   41,  260,   -1,  262,  263,
  264,   93,   -1,  267,  268,  269,  270,  271,  272,  273,
  274,  275,   -1,   59,   60,   -1,   62,  125,   38,   -1,
   40,  125,   42,   43,   93,   45,   -1,   47,  264,   -1,
   -1,   -1,  124,  125,  126,  271,  272,  273,  274,  275,
   60,   38,   62,   40,   41,   -1,   -1,   93,   40,   41,
  267,  268,  269,  270,   -1,  124,  125,  126,   -1,   38,
   -1,   40,   59,   42,   43,  264,   45,   59,   47,   -1,
   -1,   -1,  271,  272,  273,  274,   -1,   -1,  124,  125,
  126,   60,   -1,   62,   -1,   -1,   -1,   -1,   40,   41,
   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,
   -1,   93,   -1,   -1,  124,   -1,  126,   59,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,  126,
   -1,   -1,  124,  125,  126,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,  124,   -1,  126,   -1,   -1,
   -1,   -1,  260,   -1,  262,  263,  260,   -1,  262,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,   -1,
  262,  263,  264,  125,  126,  267,  268,  269,  270,  271,
  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  260,   -1,  262,  263,  264,   -1,   -1,  267,  268,
  269,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  260,   -1,  262,  263,  264,   -1,
   -1,  267,  268,  269,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  260,   -1,  262,  263,  264,  260,   -1,
  262,  263,  264,   -1,  271,  272,  273,  274,  275,  271,
  272,  273,  274,  275,   -1,  264,   -1,   -1,  267,  268,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,   38,
  262,  263,  264,   42,   43,   -1,   45,   -1,   47,  271,
  272,  273,  274,  275,   -1,   38,   -1,   -1,   -1,   42,
   43,   60,   45,   62,   47,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   60,   -1,   62,
   -1,   38,   -1,   -1,   41,   42,   43,   60,   45,   62,
   47,   -1,   38,   -1,   93,   41,   42,   43,   -1,   45,
   -1,   47,   38,   60,   -1,   62,   42,   43,   38,   45,
   93,   47,   42,   43,   60,   45,   62,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   60,  124,   62,  126,   -1,   -1,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
  126,   -1,   13,   -1,   -1,   -1,   -1,   -1,  124,   -1,
  126,   22,   -1,   -1,  124,   -1,   -1,   28,   29,   -1,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   -1,   -1,   -1,   48,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   66,   -1,   -1,   69,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   84,   85,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   95,   -1,   97,   -1,  267,  268,
  269,  270,  103,   -1,   -1,  106,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  270,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,  270,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,  270,   -1,   -1,  267,  268,  269,
  270,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 292
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'",
"'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","KW_INTE","KW_CARA","KW_REAL","KW_SE",
"KW_ENTAUM","KW_SENAUM","KW_ENQUANTO","KW_ENTRADA","KW_ESCREVA","KW_RETORNE",
"OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_DIF","TK_IDENTIFIER",
"LIT_INTEIRO","LIT_FLOAT","LIT_CHAR","LIT_STRING","TOKEN_ERROR","$accept",
"program","lDecl","lCom","cmd","gvar","gvarint","lstExpr","lstEscr","expr",
"block","fParamList","type","fCallParamList","$$1","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"$$1 :",
"program : lDecl $$1",
"lDecl : gvar ';' lDecl",
"lDecl : type TK_IDENTIFIER '(' fParamList ')' block lDecl",
"lDecl :",
"lCom : cmd ';' lCom",
"lCom : cmd",
"cmd : TK_IDENTIFIER '=' expr",
"cmd : TK_IDENTIFIER '[' expr ']' '=' expr",
"cmd : KW_ENTAUM cmd KW_SE '(' expr ')'",
"cmd : KW_ENTAUM cmd KW_SENAUM cmd KW_SE '(' expr ')'",
"cmd : cmd KW_ENQUANTO '(' expr ')'",
"cmd : KW_ESCREVA lstEscr",
"cmd : KW_RETORNE expr",
"cmd : block",
"cmd :",
"gvar : type TK_IDENTIFIER '=' expr",
"gvar : type TK_IDENTIFIER '[' gvarint ']' lstExpr",
"gvarint : LIT_INTEIRO",
"lstExpr : expr lstExpr",
"lstExpr :",
"lstEscr : expr lstEscr",
"lstEscr : LIT_STRING lstEscr",
"lstEscr :",
"expr : LIT_INTEIRO",
"expr : LIT_CHAR",
"expr : LIT_FLOAT",
"expr : TK_IDENTIFIER",
"expr : TK_IDENTIFIER '[' expr ']'",
"expr : TK_IDENTIFIER '(' fCallParamList ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : expr '~' expr",
"expr : expr OPERATOR_LE expr",
"expr : expr OPERATOR_GE expr",
"expr : expr OPERATOR_EQ expr",
"expr : expr OPERATOR_DIF expr",
"expr : '(' expr ')'",
"expr : KW_ENTRADA",
"block : '{' lCom '}'",
"fParamList : type TK_IDENTIFIER fParamList",
"fParamList :",
"type : KW_INTE",
"type : KW_CARA",
"type : KW_REAL",
"fCallParamList : expr fCallParamList",
"fCallParamList :",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 156 "parser.y"

#include <stdio.h>
#include <stdlib.h>

void yyerror() {
    fprintf(stderr,"Opps. Syntax error! Line %d\n", getLineNumber());
    exit(3);
}
#line 714 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 74 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
#line 1387 "y.tab.c"
break;
case 2:
#line 74 "parser.y"
	{ astPrint(yystack.l_mark[-1].ast,0); }
#line 1392 "y.tab.c"
break;
case 3:
#line 77 "parser.y"
	{ yyval.ast = astCreate(AST_LDCG, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1397 "y.tab.c"
break;
case 4:
#line 78 "parser.y"
	{ yyval.ast = astCreate(AST_LDCF, yystack.l_mark[-5].symbol,yystack.l_mark[-6].ast,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,yystack.l_mark[0].ast); }
#line 1402 "y.tab.c"
break;
case 5:
#line 79 "parser.y"
	{ yyval.ast = 0; }
#line 1407 "y.tab.c"
break;
case 6:
#line 82 "parser.y"
	{ yyval.ast = astCreate(AST_LCMD, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1412 "y.tab.c"
break;
case 7:
#line 83 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
#line 1417 "y.tab.c"
break;
case 8:
#line 86 "parser.y"
	{ yyval.ast = astCreate(AST_ASS, yystack.l_mark[-2].symbol,yystack.l_mark[0].ast,0,0,0); }
#line 1422 "y.tab.c"
break;
case 9:
#line 87 "parser.y"
	{ yyval.ast = astCreate(AST_ARAS, yystack.l_mark[-5].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0); }
#line 1427 "y.tab.c"
break;
case 10:
#line 89 "parser.y"
	{ yyval.ast = astCreate(AST_ENTSE, 0,yystack.l_mark[-4].ast,yystack.l_mark[-1].ast,0,0); }
#line 1432 "y.tab.c"
break;
case 11:
#line 90 "parser.y"
	{ yyval.ast = astCreate(AST_ENTSNSE, 0,yystack.l_mark[-6].ast,yystack.l_mark[-4].ast,yystack.l_mark[-1].ast,0); }
#line 1437 "y.tab.c"
break;
case 12:
#line 91 "parser.y"
	{ yyval.ast = astCreate(AST_ENQ, 0,yystack.l_mark[-4].ast,yystack.l_mark[-1].ast,0,0); }
#line 1442 "y.tab.c"
break;
case 13:
#line 93 "parser.y"
	{ yyval.ast = astCreate(AST_ESCR, 0,yystack.l_mark[0].ast,0,0,0); }
#line 1447 "y.tab.c"
break;
case 14:
#line 94 "parser.y"
	{ yyval.ast = astCreate(AST_RET, 0,yystack.l_mark[0].ast,0,0,0); }
#line 1452 "y.tab.c"
break;
case 15:
#line 95 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
#line 1457 "y.tab.c"
break;
case 16:
#line 96 "parser.y"
	{ yyval.ast = 0; }
#line 1462 "y.tab.c"
break;
case 17:
#line 99 "parser.y"
	{ yyval.ast = astCreate(AST_GVAR, yystack.l_mark[-2].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0); }
#line 1467 "y.tab.c"
break;
case 18:
#line 100 "parser.y"
	{ yyval.ast = astCreate(AST_GARR, yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0); }
#line 1472 "y.tab.c"
break;
case 19:
#line 103 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol,0,0,0,0); }
#line 1477 "y.tab.c"
break;
case 20:
#line 106 "parser.y"
	{ yyval.ast = astCreate(AST_LEXP, 0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
#line 1482 "y.tab.c"
break;
case 21:
#line 107 "parser.y"
	{ yyval.ast = 0; }
#line 1487 "y.tab.c"
break;
case 22:
#line 110 "parser.y"
	{ yyval.ast = astCreate(AST_LEEXP, 0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
#line 1492 "y.tab.c"
break;
case 23:
#line 111 "parser.y"
	{ yyval.ast = astCreate(AST_LESTR, yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0); }
#line 1497 "y.tab.c"
break;
case 24:
#line 112 "parser.y"
	{ yyval.ast = 0; }
#line 1502 "y.tab.c"
break;
case 25:
#line 116 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol,0,0,0,0); }
#line 1507 "y.tab.c"
break;
case 26:
#line 117 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol,0,0,0,0); }
#line 1512 "y.tab.c"
break;
case 27:
#line 118 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol,0,0,0,0); }
#line 1517 "y.tab.c"
break;
case 28:
#line 119 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol,0,0,0,0); }
#line 1522 "y.tab.c"
break;
case 29:
#line 120 "parser.y"
	{ yyval.ast = astCreate(AST_ACALL, yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0); }
#line 1527 "y.tab.c"
break;
case 30:
#line 121 "parser.y"
	{ yyval.ast = astCreate(AST_FCALL, yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0); }
#line 1532 "y.tab.c"
break;
case 31:
#line 122 "parser.y"
	{ yyval.ast = astCreate(AST_ADD, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1537 "y.tab.c"
break;
case 32:
#line 123 "parser.y"
	{ yyval.ast = astCreate(AST_SUB, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1542 "y.tab.c"
break;
case 33:
#line 124 "parser.y"
	{ yyval.ast = astCreate(AST_MUL, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1547 "y.tab.c"
break;
case 34:
#line 125 "parser.y"
	{ yyval.ast = astCreate(AST_DIV, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1552 "y.tab.c"
break;
case 35:
#line 126 "parser.y"
	{ yyval.ast = astCreate(AST_LES, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1557 "y.tab.c"
break;
case 36:
#line 127 "parser.y"
	{ yyval.ast = astCreate(AST_GRE, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1562 "y.tab.c"
break;
case 37:
#line 128 "parser.y"
	{ yyval.ast = astCreate(AST_AND, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1567 "y.tab.c"
break;
case 38:
#line 129 "parser.y"
	{ yyval.ast = astCreate(AST_OR, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1572 "y.tab.c"
break;
case 39:
#line 130 "parser.y"
	{ yyval.ast = astCreate(AST_NOT, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1577 "y.tab.c"
break;
case 40:
#line 131 "parser.y"
	{ yyval.ast = astCreate(AST_LE, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1582 "y.tab.c"
break;
case 41:
#line 132 "parser.y"
	{ yyval.ast = astCreate(AST_GE, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1587 "y.tab.c"
break;
case 42:
#line 133 "parser.y"
	{ yyval.ast = astCreate(AST_EQ, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1592 "y.tab.c"
break;
case 43:
#line 134 "parser.y"
	{ yyval.ast = astCreate(AST_DIF, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1597 "y.tab.c"
break;
case 44:
#line 135 "parser.y"
	{ yyval.ast = astCreate(AST_PAR, 0,yystack.l_mark[-1].ast,0,0,0); }
#line 1602 "y.tab.c"
break;
case 45:
#line 136 "parser.y"
	{ yyval.ast = astCreate(AST_ENTRADA, 0,0,0,0,0); }
#line 1607 "y.tab.c"
break;
case 46:
#line 139 "parser.y"
	{ yyval.ast = astCreate(AST_BLOCK, 0,yystack.l_mark[-1].ast,0,0,0); }
#line 1612 "y.tab.c"
break;
case 47:
#line 142 "parser.y"
	{ yyval.ast = astCreate(AST_FPL, yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
#line 1617 "y.tab.c"
break;
case 48:
#line 143 "parser.y"
	{ yyval.ast = 0; }
#line 1622 "y.tab.c"
break;
case 49:
#line 146 "parser.y"
	{ yyval.ast = astCreate(AST_INTE, 0,0,0,0,0); }
#line 1627 "y.tab.c"
break;
case 50:
#line 147 "parser.y"
	{ yyval.ast = astCreate(AST_CARA, 0,0,0,0,0); }
#line 1632 "y.tab.c"
break;
case 51:
#line 148 "parser.y"
	{ yyval.ast = astCreate(AST_REAL, 0,0,0,0,0); }
#line 1637 "y.tab.c"
break;
case 52:
#line 151 "parser.y"
	{ yyval.ast = astCreate(AST_FCPL, 0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
#line 1642 "y.tab.c"
break;
case 53:
#line 152 "parser.y"
	{ yyval.ast = 0; }
#line 1647 "y.tab.c"
break;
#line 1649 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
