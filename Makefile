all:
	gcc main.c count.c -o main.o

test:
	gcc count.c test.c -o test.o
	./test.o
	rm test.o