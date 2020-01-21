
kadai = kadai7
source = pl2a
target = pl2a.p

define TEST
10
10
10
endef
export TEST

build: parser
	./parser samples/pascal/$(target)

parser: y.tab.c y.tab.h lex.yy.c symbol-table.c data-structures.c display-llvm.c utils.c
	cc ./*.c -ll -o parser


y.tab.c y.tab.h: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

symbol-table.c: utils.h symbol-table.h
data-structures.c: utils.h data-structures.h
display-llvm.c : display-llvm.h
utils.c: utils.h

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	./parser samples/pascal/pl0a.p && echo 10 | lli result.ll
	./parser samples/pascal/pl0b.p && echo 10 | lli result.ll
	./parser samples/pascal/pl0c.p && echo 10 | lli result.ll
	./parser samples/pascal/pl0d.p && echo 10 | lli result.ll
	./parser samples/pascal/pl1a.p && echo 10 | lli result.ll
	./parser samples/pascal/pl1b.p && echo 10 | lli result.ll
	./parser samples/pascal/pl1c.p && echo 10 | lli result.ll
	./parser samples/pascal/pl1d.p && echo 10 | lli result.ll
	./parser samples/pascal/pl2a.p && echo 10 | lli result.ll
	./parser samples/pascal/pl2b.p && echo 10 | lli result.ll
	./parser samples/pascal/pl2c.p && echo 10 | lli result.ll
	./parser samples/pascal/pl2d.p && echo 10 | lli result.ll

llvm: parser
	./parser samples/pascal/$(target)
	lli result.ll


kadai: parser
	if [ ! -e ./kadai/$(kadai) ]; then mkdir ./kadai/$(kadai); fi
	cp ./*.c ./*.h ./parser.y ./scanner.l ./Makefile ./result.ll ./kadai/$(kadai)/
	tar zcvf ./kadai/$(kadai)/$(kadai).tar.gz ./kadai/$(kadai)

convert:
	clang -S -O0 -emit-llvm ./samples/c/$(source).c -o ./samples/llvm/$(source).ll