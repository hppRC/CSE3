parser: y.tab.c lex.yy.c symbol-table.c data-structures.c
	 cc y.tab.c lex.yy.c symbol-table.c data-structures.c -ll -o parser

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	 ./parser samples/ex1.p