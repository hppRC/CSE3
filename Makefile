kadai = kadai4

parser: y.tab.c lex.yy.c symbol-table.c data-structures.c
	 cc y.tab.c lex.yy.c symbol-table.c data-structures.c -ll -o parser

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

symbol-table.c: utils.h symbol-table.h

data-structures.c: utils.h data-structures.h

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	 ./parser samples/pl0c.p

kadai: parser
	cp ./symbol-table.c ./symbol-table.h ./Makefile ./scanner.l ./parser.y ./kadai/$(kadai)/ && \
	tar zcvf ./kadai/$(kadai)/$(kadai).tar.gz ./kadai/$(kadai)
