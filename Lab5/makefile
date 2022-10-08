check_nesting: check_nesting.o stack.o
	gcc -Wall -std=c99 -o check_nesting check_nesting.o stack.o

check_nesting.o: check_nesting.c stack.h
	gcc -Wall -std=c99 -c check_nesting.c

stack.o: stack.c stack.h
	gcc -Wall -std=c99 -c stack.c

clean:
	rm -f check_nesting *.o