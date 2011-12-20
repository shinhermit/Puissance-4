#Power4: A small game programming project for studies
author: Josuah Aron
version 1.5

##Rules
You can find informations about the rules of the game at the following:\n
	http://fr.wikipedia.org/wiki/Puissance_4

##How to compile

* Open a shell (Terminal)
* move to the root folder of the download
** if you run
	$ ls
	it should display 4 folders, 'build', gamefiles, 'include' and 'src'

* run the following commands:
	$ make
	$ make clean

* enjoy by running:
	$ ./power4

#list of options

./power4 [--help] [--nogui] [--log] [-j1 player1Name] [-p pawnType] [-j2 player2Name]

* --help: Show this help. The program won't run.
* --nogui: desactivate basic gui. Actions are echoed as text messages.
* --log: Record actions in a logfile. The name of this file is ./power4.log
* -j1: enter the name of player1 after this marker.
* -j2: enter the name of player2 after this marker.
* -p: enter the type of pawn for player 1.


#Description

directories:
* src: contains .c source files
* include: contains .h headers
* gamefiles: contains logfile power4.log
* build: contains Makefile and cmake files
