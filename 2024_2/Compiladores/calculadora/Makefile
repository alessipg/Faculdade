calc: lexer.l parser.y calc.h
	bison -d parser.y
	flex -o lexer.c lexer.l
	gcc -o $@ parser.tab.c lexer.c calc.c -lm
	@echo Parser da calculadora pronto...
make clean:
	rm calc parser.tab.h parser.tab.c lexer.c