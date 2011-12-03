#
#Power4 v3
#Makefile v3
#
compiler = gcc
the_exec = power4
display = display.c
game = game.c
play = play.c
check = check.c
dir_src = src
dir_include = include


all: thegame

thegame: theObjects
	cd ./$(dir_src); $(compiler) -o $(the_exec) main.o display.o  game.o  play.o  check.o
	mv $(dir_src)/$(the_exec) $(the_exec)

theObjects:  $(dir_src)/main.c  $(dir_src)/display.c  $(dir_src)/game.c  $(dir_src)/play.c  $(dir_src)/check.c $(dir_include)/power4.h
	cd ./$(dir_src); $(compiler) -I../$(dir_include) -c  main.c  display.c  game.c  play.c  check.c

clean:
	cd ./$(dir_src); rm  *.o

cleanall: clean
	rm $(the_exec)