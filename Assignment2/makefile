wordSearch2D: wordSearch2D.o puzzle2D.o
	gcc -ggdb -Wall -std=c99 -o wordSearch2D wordSearch2D.o puzzle2D.o

wordSearch2D.o: wordSearch2D.c puzzle2D.h
	gcc -ggdb -Wall -std=c99 -c wordSearch2D.c

puzzle2D.o: puzzle2D.c puzzle2D.h
	gcc -ggdb -Wall -std=c99 -c puzzle2D.c

clean:
	rm -f wordSearch2D *.o output.txt
