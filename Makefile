
kadai = kadai4

parser: y.tab.c y.tab.h lex.yy.c symbol-table.c data-structures.c display-llvm.c utils.c
	cc ./*.c -ll -o parser


y.tab.c y.tab.h: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

symbol-table.c: utils.h symbol-table.h

data-structures.c: utils.h data-structures.h

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	./parser samples/pascal/m.p

llvm: parser
	./parser samples/pascal/m.p
	lli result.ll


kadai: parser
	cp ./*.c ./*.h ./parser.y ./scanner.l ./Makefile ./kadai/$(kadai)/
	tar zcvf ./kadai/$(kadai)/$(kadai).tar.gz ./kadai/$(kadai)
