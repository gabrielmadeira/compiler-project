# Gabriel Madeira (00322863)

etapa2: y.tab.c lex.yy.o hash.o 
		gcc -o etapa2 lex.yy.o hash.o 

y.tab.c: parser.y
		yacc -d parser.y

hash.o: hash.c
		gcc -c hash.c

lex.yy.o: lex.yy.c
		gcc -c lex.yy.c

lex.yy.c: scanner.l
		flex scanner.l

clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa2
