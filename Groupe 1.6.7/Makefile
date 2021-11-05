CC=gcc
CFLAGS=-g -Wall -ansi -pedantic
FILE=piece.o coup.o maillon.o pile.o double_liste.o plateau.o deplacement.o main.o
PROG=chess

all:$(FILE)
	$(CC) $(CFLAGS) $(FILE) -o $(PROG)

piece.o:piece.c
	$(CC) -c $(CFLAGS) piece.c
coup.o:coup.c
	$(CC) -c $(CFLAGS) coup.c
maillon.o:maillon.c
	$(CC) -c $(CFLAGS) maillon.c
pile.o:pile.c
	$(CC) -c $(CFLAGS) pile.c
double_liste.o:double_liste.c
	$(CC) -c $(CFLAGS) double_liste.c
plateau.o:plateau.c
	$(CC) -c $(CFLAGS) plateau.c
deplacement.o:deplacement.c
	$(CC) -c $(CFLAGS) deplacement.c
main.o:main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f *.o
