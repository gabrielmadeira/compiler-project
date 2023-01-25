# Gabriel Madeira (00322863)

etapa3: main.o y.tab.o lex.yy.o hash.o ast.o
		gcc -o etapa3 main.o y.tab.o lex.yy.o hash.o ast.o 

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d parser.y


lex.yy.o: lex.yy.c
		gcc -c lex.yy.c

lex.yy.c: scanner.l
		flex --header-file=lex.yy.h scanner.l

clean:
	rm *.o lex.yy.c y.tab.c y.tab.h lex.yy.h etapa3
