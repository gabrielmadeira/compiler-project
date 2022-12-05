/*
	Gabriel Madeira (00322863)
*/

int main(int argc, char **argv) {
	
	if(argc<2){
		fprintf(stderr, "Call: etapa1 filename\n"); 
		exit(1);
	}
	if(0==(yyin = fopen(argv[1],"r"))){
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
		exit(2);	
	}

	initMe();

	printf("\nRunning: %d \n", isRunning());

	int tok;
	while(running) {
		tok = yylex();
		if(!running) break;
		switch(tok) {
			case KW_CARA: { printf("KW_CARA "); } break;
			case KW_INTE: { printf("KW_INTE "); } break;
			case KW_REAL: { printf("KW_REAL "); } break;

			case KW_SE: { printf("KW_SE "); } break;
			case KW_ENTAUM: { printf("KW_ENTAUM "); } break;
			case KW_SENAUM: { printf("KW_SENAUM "); } break;
			case KW_ENQUANTO: { printf("KW_ENQUANTO "); } break;
			case KW_ENTRADA: { printf("KW_ENTRADA "); } break;
			case KW_ESCREVA: { printf("KW_ESCREVA "); } break;
			case KW_RETORNE: { printf("KW_RETORNE "); } break;

			case OPERATOR_LE: { printf("OPERATOR_LE "); } break;
			case OPERATOR_GE: { printf("OPERATOR_GE "); } break;
			case OPERATOR_EQ: { printf("OPERATOR_EQ "); } break;
			case OPERATOR_DIF: { printf("OPERATOR_DIF "); } break;

			case TK_IDENTIFIER: { printf("TK_IDENTIFIER "); } break;
			
			case LIT_INTEIRO: { printf("LIT_INTEIRO "); } break; // inserir no hash
			case LIT_FLOAT: { printf("LIT_FLOAT "); } break;
			case LIT_CHAR: { printf("LIT_CHAR "); } break;
			case LIT_STRING: { printf("LIT_STRING "); } break;

			case TOKEN_ERROR: { printf("TOKEN_ERROR "); } break;
			default: { printf("SYMBOL%c ", tok); } break;
		}
	}
	printf("\nFile had %d lines\n", getLineNumber());
	
	printf("\nRunning: %d \n", isRunning());
	
	hashPrint();
}
