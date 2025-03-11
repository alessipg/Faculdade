calc: lexer.l parser.y ast.h
	bison -d parser.y
	flex -o lexer.c lexer.l
	gcc -o $@ parser.tab.c lexer.c ast.c 
	@echo Parser da calculadora pronto...
make clean:
	rm calc parser.tab.h parser.tab.c lexer.c