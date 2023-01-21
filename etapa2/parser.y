/*
    Gabriel Madeira (00322863)
*/

%{
    #include <stdio.h>
    int getLineNumber();
    void initMe();
    void yyerror();
%}

%union
{
    struct hash_node* symbol;
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

%left '~'
%left '|'
%left '&'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-' 
%left '*' '/'


%%

program: lDecl
        ;

lDecl: gvar ';' lDecl
        | func lDecl
        |
        ;

lCom: cmd ';' lCom
        | cmd
        ;       

cmd:    atrib 
        | comFlux
        | KW_ESCREVA lstEscr
        | KW_RETORNE expr
        | block
        | 
        ;

gvar:   type TK_IDENTIFIER '=' expr
        | type TK_IDENTIFIER '[' LIT_INTEIRO ']' lstExpr
        ;

lstExpr:   expr lstExpr
        |
        ;

lstEscr:   expr lstEscr
        | LIT_STRING lstEscr
        |
        ;

atrib:
        TK_IDENTIFIER '=' expr
        | TK_IDENTIFIER '[' expr ']' '=' expr

comFlux:   KW_ENTAUM cmd KW_SE '(' expr ')'
        | KW_ENTAUM cmd KW_SENAUM cmd KW_SE '(' expr ')'
        | cmd KW_ENQUANTO '(' expr ')'
        ;

expr:   LIT_INTEIRO
        | LIT_CHAR
        | LIT_FLOAT
        | TK_IDENTIFIER 
        | TK_IDENTIFIER '[' expr ']'
        | fCall
        | expr '+' expr
        | expr '-' expr
        | expr '*' expr
        | expr '/' expr
        | expr '<' expr
        | expr '>' expr
        | expr '&' expr
        | expr '|' expr
        | expr '~' expr
        | expr OPERATOR_LE expr
        | expr OPERATOR_GE expr
        | expr OPERATOR_EQ expr
        | expr OPERATOR_DIF expr
        | '(' expr ')'
        | KW_ENTRADA
        ;


block: '{' lCom '}'
        ;

func:   type TK_IDENTIFIER '(' fParamList ')' block
        ;

fParamList:  type TK_IDENTIFIER fParamList
        |
        ;

type:   KW_INTE
        | KW_CARA
        | KW_REAL
        ;

fCall:  TK_IDENTIFIER '(' fCallParamList ')'

fCallParamList: expr fCallParamList
        |
        ;

%%

void yyerror() {
    fprintf(stderr,"Opps. Syntax error! Line %d\n", getLineNumber());
    exit(3);
}