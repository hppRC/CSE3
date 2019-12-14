kadai = kadai3
symbolTable = symbol-table-with-test.c

parser: y.tab.c lex.yy.c $(symbolTable)
	 cc y.tab.c lex.yy.c $(symbolTable) -ll -o parser

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	 ./parser samples/pl0c.p

kadai: parser
	cp ./symbol-table.c ./symbol-table.h ./Makefile ./scanner.l ./parser.y ./kadai/$(kadai)/ && \
	tar zcvf ./kadai/$(kadai)/$(kadai).tar.gz ./kadai/$(kadai)
