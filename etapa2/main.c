/*
	Gabriel Madeira (00322863)
*/

int yyparse();

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

	yyparse();

	printf("\nHash Content:\n");
	hashPrint();

	printf("\nFile had %d lines\n", getLineNumber());
	printf("\nSuccess!\n\n");

	exit(0);
}
