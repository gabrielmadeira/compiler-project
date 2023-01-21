#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE 
{
    /*HASH *symbol;*/
    struct hash_node* symbol;
    /*AST* ast;*/
    struct ast_node* ast;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
