/*
    Gabriel Madeira (00322863)
*/

%{
    #include "hash.h"
    #include "ast.h"
    int yylex(void); 
	int getLineNumber();

    void yyerror();

%}

%union 
{
    //HASH *symbol;
    struct hash_node* symbol;
    //AST* ast;
    struct ast_node* ast;
}


%token KW_INTE
%token KW_CARA
%token KW_REAL

%token KW_SE
%token KW_ENTAUM
%token KW_SENAUM
%token KW_ENQUANTO
%token KW_ENTRADA
%token KW_ESCREVA
%token KW_RETORNE

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token <symbol> TK_IDENTIFIER

%token <symbol> LIT_INTEIRO
%token <symbol> LIT_FLOAT
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING

%token TOKEN_ERROR

%type<ast> program
%type<ast> lDecl
%type<ast> lCom
%type<ast> cmd
%type<ast> gvar
%type<ast> gvarint
%type<ast> lstExpr
%type<ast> lstEscr
%type<ast> expr
%type<ast> block
%type<ast> fParamList
%type<ast> type
%type<ast> fCallParamList

%left '~'
%left '|'
%left '&'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-' 
%left '*' '/'


%%

program: lDecl { $$ = $1; } { astDecompile($1); } //astPrint($1,0);
        ;

lDecl: gvar ';' lDecl { $$ = astCreate(AST_LDCG, 0,$1,$3,0,0); } 
        | type TK_IDENTIFIER '(' fParamList ')' block lDecl { $$ = astCreate(AST_LDCF, $2,$1,$4,$6,$7); } 
        | { $$ = 0; }
        ;

lCom: cmd ';' lCom { $$ = astCreate(AST_LCMD, 0,$1,$3,0,0); } 
        | cmd { $$ = $1; }
        ;       

cmd:    TK_IDENTIFIER '=' expr { $$ = astCreate(AST_ASS, $1,$3,0,0,0); }
        | TK_IDENTIFIER '[' expr ']' '=' expr { $$ = astCreate(AST_ARAS, $1,$3,$6,0,0); }

        | KW_ENTAUM cmd KW_SE '(' expr ')' { $$ = astCreate(AST_ENTSE, 0,$2,$5,0,0); }
        | KW_ENTAUM cmd KW_SENAUM cmd KW_SE '(' expr ')' { $$ = astCreate(AST_ENTSNSE, 0,$2,$4,$7,0); }
        | cmd KW_ENQUANTO '(' expr ')' { $$ = astCreate(AST_ENQ, 0,$1,$4,0,0); }

        | KW_ESCREVA lstEscr { $$ = astCreate(AST_ESCR, 0,$2,0,0,0); }
        | KW_RETORNE expr { $$ = astCreate(AST_RET, 0,$2,0,0,0); }
        | block { $$ = $1; }
        | { $$ = 0; }
        ;

gvar:   type TK_IDENTIFIER '=' expr { $$ = astCreate(AST_GVAR, $2,$1,$4,0,0); } 
        | type TK_IDENTIFIER '[' gvarint ']' lstExpr { $$ = astCreate(AST_GARR, $2,$1,$4,$6,0); } 
        ;

gvarint: LIT_INTEIRO { $$ = astCreate(AST_SYMBOL, $1,0,0,0,0); } 
        ;

lstExpr:   expr lstExpr { $$ = astCreate(AST_LEXP, 0,$1,$2,0,0); } 
        | { $$ = 0; }
        ;

lstEscr:   expr lstEscr { $$ = astCreate(AST_LEEXP, 0,$1,$2,0,0); } 
        | LIT_STRING lstEscr { $$ = astCreate(AST_LESTR, $1,$2,0,0,0); } 
        | { $$ = 0; }
        ;


expr:   LIT_INTEIRO { $$ = astCreate(AST_SYMBOL, $1,0,0,0,0); } 
        | LIT_CHAR  { $$ = astCreate(AST_SYMBOL, $1,0,0,0,0); }
        | LIT_FLOAT { $$ = astCreate(AST_SYMBOL, $1,0,0,0,0); } 
        | TK_IDENTIFIER { $$ = astCreate(AST_SYMBOL, $1,0,0,0,0); } 
        | TK_IDENTIFIER '[' expr ']' { $$ = astCreate(AST_ACALL, $1,$3,0,0,0); } 
        | TK_IDENTIFIER '(' fCallParamList ')' { $$ = astCreate(AST_FCALL, $1,$3,0,0,0); } 
        | expr '+' expr { $$ = astCreate(AST_ADD, 0,$1,$3,0,0); }
        | expr '-' expr { $$ = astCreate(AST_SUB, 0,$1,$3,0,0); }
        | expr '*' expr { $$ = astCreate(AST_MUL, 0,$1,$3,0,0); }
        | expr '/' expr { $$ = astCreate(AST_DIV, 0,$1,$3,0,0); }
        | expr '<' expr { $$ = astCreate(AST_LES, 0,$1,$3,0,0); }
        | expr '>' expr { $$ = astCreate(AST_GRE, 0,$1,$3,0,0); }
        | expr '&' expr { $$ = astCreate(AST_AND, 0,$1,$3,0,0); }
        | expr '|' expr { $$ = astCreate(AST_OR, 0,$1,$3,0,0); }
        | expr '~' expr { $$ = astCreate(AST_NOT, 0,$1,$3,0,0); }
        | expr OPERATOR_LE expr { $$ = astCreate(AST_LE, 0,$1,$3,0,0); }
        | expr OPERATOR_GE expr { $$ = astCreate(AST_GE, 0,$1,$3,0,0); }
        | expr OPERATOR_EQ expr { $$ = astCreate(AST_EQ, 0,$1,$3,0,0); }
        | expr OPERATOR_DIF expr { $$ = astCreate(AST_DIF, 0,$1,$3,0,0); }
        | '(' expr ')' { $$ = astCreate(AST_PAR, 0,$2,0,0,0); } //{ $$ = $2;} 
        | KW_ENTRADA { $$ = astCreate(AST_ENTRADA, 0,0,0,0,0); } 
        ;

block: '{' lCom '}' { $$ = astCreate(AST_BLOCK, 0,$2,0,0,0); } 
    ;

fParamList:  type TK_IDENTIFIER fParamList { $$ = astCreate(AST_FPL, $2,$1,$3,0,0); } 
        | { $$ = 0; }
        ;

type:   KW_INTE { $$ = astCreate(AST_INTE, 0,0,0,0,0); } 
        | KW_CARA { $$ = astCreate(AST_CARA, 0,0,0,0,0); } 
        | KW_REAL { $$ = astCreate(AST_REAL, 0,0,0,0,0); } 
        ;

fCallParamList: expr fCallParamList { $$ = astCreate(AST_FCPL, 0,$1,$2,0,0); } 
        | { $$ = 0; }
        ;
    
%%

#include <stdio.h>
#include <stdlib.h>

void yyerror() {
    fprintf(stderr,"Opps. Syntax error! Line %d\n", getLineNumber());
    exit(3);
}