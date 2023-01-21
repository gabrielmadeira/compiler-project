/*
	Gabriel Madeira (00322863)
*/

%{
	
	#include "hash.h"
	#include "ast.h"
	#include "y.tab.h"
	
	#define SYMBOL_LIT_INTE 1
	#define SYMBOL_LIT_CARA 2
	#define SYMBOL_LIT_REAL 3
	#define SYMBOL_LIT_STRING 4
	#define SYMBOL_LIT_IDENTIFIER 5

	int running = 1;
	int lineCount = 1;

%}

%x COMMENT

%%

"cara"		{ return KW_CARA; }
"inte"		{ return KW_INTE; }
"real"		{ return KW_REAL; }

"se"		{ return KW_SE; }
"entaum"	{ return KW_ENTAUM; }
"senaum"	{ return KW_SENAUM; }
"enquanto"	{ return KW_ENQUANTO; }
"entrada"	{ return KW_ENTRADA; }
"escreva"	{ return KW_ESCREVA; }
"retorne"	{ return KW_RETORNE; }

"<="		{ return OPERATOR_LE; }
">="		{ return OPERATOR_GE; }
"=="		{ return OPERATOR_EQ; }
"!="		{ return OPERATOR_DIF; }

[0-9]+					{ yylval.symbol = hashInsert(SYMBOL_LIT_INTE, yytext); return LIT_INTEIRO; }
[0-9]+"."[0-9]+			{ yylval.symbol = hashInsert(SYMBOL_LIT_REAL, yytext); return LIT_FLOAT; }
'.'						{ yylval.symbol = hashInsert(SYMBOL_LIT_CARA, yytext); return LIT_CHAR; }
\"(\\.|[^"\\^(\n)])*\"	{ yylval.symbol = hashInsert(SYMBOL_LIT_STRING, yytext); return LIT_STRING; }


[-;()\[\]{}=+*/<>&|~]	{ return yytext[0]; }
([a-z]|_|".")+([a-z]|[0-9]|_|".")* 		{ yylval.symbol = hashInsert(SYMBOL_LIT_IDENTIFIER, yytext); return TK_IDENTIFIER; }

[,\t ]

"\n"		{ lineCount++; }
"///".*		{ BEGIN(COMMENT); }
"//".*
.		{ return TOKEN_ERROR; }


<COMMENT>"\n"		{ lineCount++; }
<COMMENT>.	
<COMMENT>"\\\\\\"	{ BEGIN(INITIAL); }

%%

int getLineNumber(void) {
	return lineCount;
}

int isRunning(void) {
	return running;
}

int yywrap() {
	running = 0;
	return 1;
}

void initMe(void) {
	hashInit();
}