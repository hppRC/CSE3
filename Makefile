
kadai = kadai10
source = pl3b
target = pl2b.p
ARG = 10

define TEST
./parser samples/pascal/$1.p && echo ${ARG} | lli result.ll
endef


build: parser
	./parser samples/pascal/$(target)

parser: y.tab.c y.tab.h lex.yy.c symbol-table.c data-structures.c display-llvm.c utils.c
	cc ./*.c -ll -o parser


y.tab.c y.tab.h: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

symbol-table.c: utils.h
data-structures.c: utils.h
utils.c: utils.h

clean:
	rm parser y.tab.* lex.yy.c

test: parser
	$(call TEST,pl0a)
	$(call TEST,pl0b)
	$(call TEST,pl0c)
	$(call TEST,pl0d)
	$(call TEST,pl1a)
	$(call TEST,pl1b)
	$(call TEST,pl1c)
	$(call TEST,pl1d)
	$(call TEST,pl2a)
	./parser samples/pascal/pl2b.p && echo 4 2 | lli result.ll
	$(call TEST,pl2c)
	$(call TEST,pl2d)
	$(call TEST,pl2e)
	$(call TEST,pl2f)
	./parser samples/pascal/pl3a.p && echo 4 10 4 8 7 | lli result.ll
	$(call TEST,pl3b)
	./parser samples/pascal/pl3c.p && echo 8 1 2 3 4 5 6 7 8 | lli result.ll
	$(call TEST,pl3b)
	$(call TEST,pl4a)
	$(call TEST,pl4b)
	$(call TEST,opt1)
	$(call TEST,opt2)
	./parser samples/pascal/msort.p && echo 4 10 4 8 7 | lli result.ll

llvm: parser
	./parser samples/pascal/$(target)
	lli result.ll


kadai: parser
	if [ ! -e ./kadai/$(kadai) ]; then mkdir ./kadai/$(kadai); fi
	cp ./*.c ./*.h ./parser.y ./scanner.l ./Makefile ./result.ll ./kadai/$(kadai)/
	tar zcvf ./kadai/$(kadai)/$(kadai).tar.gz ./kadai/$(kadai)

convert:
	clang -S -O0 -emit-llvm ./samples/c/$(source).c -o ./samples/llvm/$(source).ll

count:
	wc parser.y display-llvm.c data-structures.c symbol-table.c utils.h