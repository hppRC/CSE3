parser: y.tab.c lex.yy.c utils.c symbol_table.c symbol_table.h
	 cc y.tab.c lex.yy.c utils.c symbol_table.c -ll -o parser

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	 ./parser samples/pl0b.p