conversor: lexer.l parser.y conversor.h
	bison -d -t parser.y
	flex -o lexer.c lexer.l
	gcc -o $@ parser.tab.c lexer.c conversor.c -lm
	@echo Conversor pronto...
make clean:
	rm conversor parser.tab.h parser.tab.c lexer.c agente.py