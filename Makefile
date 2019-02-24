#
# EE 4374 Assignment 2 Makefile
# Author: Michael Contreras
#

all: mcontreras_prog2

mcontreras_prog2: mcontreras_prog2.o mcontreras_exec.o mcontreras_argtok.o
	cc -o $@ $^

mcontreras_prog2.o: mcontreras_prog2.c mcontreras_exec.h mcontreras_argtok.h
	cc -c mcontreras_prog2.c

mcontreras_exec.o: mcontreras_exec.c mcontreras_exec.h
	cc -c mcontreras_exec.c

mcontreras_argtok.o: mcontreras_argtok.c mcontreras_argtok.h
	cc -c mcontreras_argtok.c

clean:
	rm *.o; rm mcontreras_prog2
