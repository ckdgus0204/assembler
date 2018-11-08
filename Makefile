# Write this Makefile
gcc -c main.c
gcc -c trans.c
gcc -c check.c
gcc -o myas main.o check.o trans.o
