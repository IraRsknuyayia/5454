all:  str.o addition.o main.o
	gcc -o laba str.o addition.o main.o
	
str.o: src/str.c
	gcc -c src/str.c

addition.o: src/addition.c
	gcc -c src/addition.c

main.o: src/laba.c
	gcc -o main.o -c src/laba.c

.PHONY: clean

clean :
	rm *.o
