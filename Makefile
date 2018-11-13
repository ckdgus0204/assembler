# Write this Makefile
myas: main.c check.c trans.c
	gcc -o myas main.o check.o trans.o -lm
main.c: main.c
	gcc -c main.c
check.c: check.c
	gcc -c check.c
trans.c: trans.c
	gcc -c trans.c

clean:
	rm-f main.o trans.o check.o myas

