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