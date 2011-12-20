<<<<<<< HEAD
/**
 *@file power4.h
 *@brief Abstract data types implementation
 *defines the constants, enum and struct type to represents the objects of the game
 *@author Josuah Aron
 *@version 1.5
 */

#ifndef POWER4_H
  #define POWER4_H
#include <stdio.h>
#include <stdlib.h>


/**
 *@def LOGPATH "gamefiles/power4.log"
 *@brief logfile path
 *The macro-definition LOGFILE fixes the path of the logfile, for command line option --log
 */
#define LOGPATH "gamefiles/power4.log"

/**
 *@def MAXSTR 20
 *@brief max strings length
 *The macro-definition MAXSTR sets the max length of string in the program
 */
#define MAXSTR 20

/**
 *@enum E_boolean This enum implements a custom boolean type
 *@brief boolean type definition
 */
typedef enum
{
  FALSE,     /*!< FALSE == 0 */
  TRUE       /*!< TRUE == 1 */
}E_boolean;

/**
 *@enum E_pawn This enum represents the pawns of the game
 *@brief pawn type definition
 */
typedef enum
{
  NP,         /*!< No Pawn, empty cell. */
  X,          /*!< Default pwan of player 1. */
  O,          /*!< Defautl pawn of player 2. */
  N           /*!< Neutral pawn, for tests. */
}E_pawn;

/**
 *@enum E_playerNum This enum represents a player by his number
 *@brief player number
 */
typedef enum
{
  P1,          /*!< Player number 1. */
  P2,          /*!< Player number 2. */
  OP           /*!< O (zéro) player. */
}E_playerNum;

/**
 *@enum E_playStatus This enum represents the situation of the party after a player has played.
 *@brief game status
 */
typedef enum
{
  FULL_NOT_PLAYED,          /*!< The column is full, the pawn could not be set. */
  PLAYED_NOT_FULLED,        /*!< The column was not full, the pawn has been set. */
  PLAYED_FULLED,            /*!< The column is full after the pawn has been set. */
  QUIT_GAME                 /*!< The player chose to quit the game. */
}E_playStatus;

/**
 *@struct S_player This structure represents a player
 *@brief a player
 */
typedef struct
{
  short num;                  /*!< ID number of the player: type short */
  char name[MAXSTR];          /*!< Name of the player: type string */
  E_pawn pawnType;            /*!< The type of pawn of the player: type E_pawn */
}S_player;

/**
 *@struct S_game This structure represents the party.
 *@brief the party
 */
typedef struct
{
  E_pawn** grid;                 /*!< This field represents the play grid (6x7 array) and contains pawn (E_pawn type elements). */
  S_player* players[2];          /*!< This field is an array containing the players (2 S_player type elements) */
  short nbPlayers;               /*!< This field is the number of players created. */
  E_playerNum whoMustPlay;       /*!< This field memorize the number of the player who's turn to play.Player1 by default */
}S_game;

#endif //POWER4_H
=======
/*
 *Power4 v3
 *power4.h v2
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 20

typedef enum
{
  FALSE,TRUE
}E_boolean;

typedef enum
{
  X,O,N,NP
}E_pawn;
//NP: No Pawn
//N: Neutral pawn, for tests only

typedef enum
{
  P1,P2
}E_playerNum;

typedef enum
{
  FULL_NOT_PLAYED, PLAYED_NOT_FULLED, PLAYED_FULLED, QUIT_GAME
}E_playStatus;

typedef struct
{
  short num;
  char name[MAXSTR];
  E_pawn pawnType;
}S_player;

typedef struct
{
  E_pawn **grid;
  S_player *players[2];
  short nbPlayers;
  E_playerNum whoMustPlay; // Player1 par défaut
}S_game;


/****** DISPLAY.C  *******/


char convPawn(E_pawn pawn);

/*
 * convPawn: converts to a character ('X' ou 'O') sothat the grid can be displayed
 *   pawn: The pawn to be converted, type E_pawn (enum) defined above
 *   return a character 'X' or 'O'
 */

void printLine(E_pawn* vect, int nbElts);
/*
 *
 */

void hline(int lnLen);
/*
 *
 */

void numberize(int lnLen);
/*
 *
 */

void printGrid(E_pawn** mat, int nLgn, int nCol);
/*
 *
 */

void gameStats(S_game* aGame);
/*
 *
 */

void refreshScreen(S_game* aGame);
/*
 *
 */

void displayWinner(S_game* aGame);
/*
 *
 */


/********************  game.c ***********************/

void initGrid(S_game* aGame);
/*
 *
 */

short addPlayer(S_game* aGame, char* playerName, E_pawn pawnType);
/*
 *
 */

void destroyPlayers(S_game* aGame);
/*
 *
 */

void newGame(S_game* aGame, char* playerName1, E_pawn pawnType1, char* playerName2, E_pawn pawnType2);
/*
 *
 */

void destroyGame(S_game* aGame);
/*
 *
 */

/*********************  PLAY.C  ********************/


short askPlayer(S_player* player);
/*
 *
 */

E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum);
/*
 *
 */


/********************   CHECK.C   ******************/

E_pawn checkLines(E_pawn** aGrid);
/*
 *
 */

E_pawn checkCols(E_pawn** aGrid);
/*
 *
 */

E_pawn baseLineAsc(E_pawn** aGrid);
/*
 *
 */

E_pawn baseColAsc(E_pawn** aGrid);
/*
 *
 */

E_pawn baseLineDesc(E_pawn** aGrid);
/*
 *
 */

E_pawn baseColDesc(E_pawn** aGrid);
/*
 *
 */

E_pawn checkAscDiags(E_pawn** aGrid);
/*
 *
 */

E_pawn checkDescDiags(E_pawn** aGrid);
/*
 *
 */

E_pawn checkGrid(E_pawn** aGrid);
/*
 *
 */
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac
