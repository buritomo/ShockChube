# Makefile for main.c
Makefile
SOD:main.o read.o initial.o boundary.o grid.o calc.o fds.o rungekutta.o output.o
	gcc -g -o SOD main.o read.o initial.o boundary.o grid.o calc.o fds.o rungekutta.o output.o

main.o:main.c global.h read.h initial.h boundary.h grid.h calc.h fds.h rungekutta.h output.h
	gcc -g -c main.c

read.o:read.c global.h read.h
	gcc -g -c read.c

initial.o:initial.c global.h initial.h
	gcc -g -c initial.c

boundary.o:boundary.c global.h boundary.h
	gcc -g -c boundary.c

grid.o:grid.c global.h grid.h
	gcc -g -c grid.c

calc.o:calc.c global.h calc.h
	gcc -g -c calc.c

fds.o:fds.c global.h fds.h
	gcc -g -c fds.c 
	
rungekutta.o:rungekutta.c global.h rungekutta.h
	gcc -g -c rungekutta.c

clean:
	rm