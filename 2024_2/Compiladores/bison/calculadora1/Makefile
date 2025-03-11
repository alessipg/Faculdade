calc: calculadora.l calculadora.y
		bison -d calculadora.y
		flex calculadora.l
		gcc -o calc calculadora.tab.c lex.yy.c -lfl
