# Makefile for main.c
SOD:main.o read.o initial.o boundary.o grid.o calc.o fds.o rungekutta.o output.o
	gcc -g3 -o SOD main.o read.o initial.o boundary.o grid.o calc.o fds.o rungekutta.o output.o

main.o:main.c global.h read.h initial.h boundary.h grid.h calc.h fds.h rungekutta.h output.h
	gcc -g3 -c main.c

read.o:read.c global.h read.h
	gcc -g3 -c read.c

initial.o:initial.c global.h initial.h
	gcc -g3 -c initial.c

boundary.o:boundary.c global.h boundary.h
	gcc -g3 -c boundary.c

grid.o:grid.c global.h grid.h
	gcc -g3 -c grid.c

calc.o:calc.c global.h calc.h
	gcc -g3 -c calc.c

fds.o:fds.c global.h fds.h
	gcc -g3 -c fds.c 
	
rungekutta.o:rungekutta.c global.h rungekutta.h
	gcc -g3 -c rungekutta.c

output.o:output.c output.h global.h
	gcc -g3 -c output.c

clean:
	rm