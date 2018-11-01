CLANG=/home/xozzslip/Downloads/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/clang

all:
	gcc main.c count.c -o main.o

test:
	gcc count.c test.c -o test.o
	./test.o

llvm:
	${CLANG} -g -O0 -emit-llvm -c count.c -o count.bc
	${CLANG} -g -O0 -emit-llvm -c test.c -o test.bc
