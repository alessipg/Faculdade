basicLang: lexer.l parser.y basicLang.h
	bison -d parser.y
	flex -o lexer.c lexer.l
	gcc -o $@ parser.tab.c lexer.c basicLang.c -lm
	@echo Parser da Linguagem basica pronto...
make clean:
	rm basicLang parser.tab.h parser.tab.c lexer.c out.txt