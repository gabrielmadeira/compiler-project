
%{
    #include <stdio.h>

    //int yylex();
    void yyerror();

%}

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

%token TK_IDENTIFIER

%token LIT_INTEIRO
%token LIT_FLOAT
%token LIT_CHAR
%token LIT_STRING

%token TOKEN_ERROR

%left '<' '>'
%left '+' '-' 
%left '*' '/'


%%

program: lass
        ;

lass: cmd ';' tail     
        | cmd
        | block tail
        | func tail
        | cond tail
        |
        ;


tail: cmd ';' tail 
        | block tail
        | func tail
        | cond tail
        |
        ;       

cmd:    TK_IDENTIFIER '=' expr
        | gvar
        | fCall
        | TK_IDENTIFIER '[' expr ']' '=' expr
        | KW_ESCREVA escrev
        | KW_RETORNE expr
        |
        ;

cond:   KW_ENTAUM blockOrCmd KW_SE '(' expr ')'
        | KW_ENTAUM blockOrCmd KW_SENAUM blockOrCmd KW_SE '(' expr ')'
        | blockOrCmd KW_ENQUANTO '(' expr ')'
        ;


blockOrCmd:     cmd
                | block
                ;

escrev: LIT_STRING escrev
        | expr escrev
        |
        ;

block: '{' lass '}'
        ;


vect:   expr vect
        |
        ;

expr:   LIT_INTEIRO
        | LIT_CHAR
        | LIT_FLOAT
        | LIT_STRING
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

gvar:   type TK_IDENTIFIER '=' expr
        | type TK_IDENTIFIER '[' LIT_INTEIRO ']' vect
        ;

type:   KW_INTE
        | KW_CARA
        | KW_REAL
        ;
    

func:   type TK_IDENTIFIER '(' param ')' block
        ;

param:  type TK_IDENTIFIER param
        |
        ;

fCall:  expr '(' pfCall ')'

pfCall: expr pfCall
        |
        ;
    
%%

void yyerror() {
    fprintf(stderr,"Opps. Syntax error! Line %d\n", getLineNumber());
    exit(3);
}