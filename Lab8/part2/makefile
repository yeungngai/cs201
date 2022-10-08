qsort: qsort.o quicksort.o
	gcc -Wall -std=c99 -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	gcc -Wall -std=c99 -c qsort.c

quicksort.o: quicksort.c quicksort.h
	gcc -Wall -std=c99 -c quicksort.c

clean:
	rm -f qsort *.o