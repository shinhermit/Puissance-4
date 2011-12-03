#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 20

typedef enum
{
  FALSE,TRUE
}E_boolean;

typedef enum
{
  X,O,N,PDP
}E_pion;
//PDP: pas de pion
//N:Pion neutre, pour les tests

typedef enum
{
  J1,J2
}E_playerNum;

typedef enum
{
  FULL_NOT_PLAYED, PLAYED_NOT_FULLED, PLAYED_FULLED, QUIT_GAME
}E_playStatus;

typedef struct
{
  short num;
  char name[MAXSTR];
  E_pion typePion;
}S_joueur;

typedef struct
{
  E_pion **grille;
  S_joueur *players[2];
  short nbPlayers;
  E_playerNum aQuiLeTour; // Joueur1 par défaut
}S_partie;


/****** DISPLAY.C  *******/


char convPion(E_pion pion);

/*
 * convPion: permet la conversion du pion en un caractère ('X' ou 'O') pour l'affichage de la grille
 * Arguments:
 *   pion: Le pion à convertir, du type E_pion (enum) defini ci_dessus
 *   revoi un caractère 'X' ou 'O'
 */

void printLine(E_pion* vect, int nbElts);
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

void printGrille(E_pion** mat, int nLgn, int nCol);
/*
 *
 */

void gameStats(S_partie* unePartie);
/*
 *
 */

void refreshScreen(S_partie* unePartie);
/*
 *
 */

void displayWinner(S_partie* unePartie);
/*
 *
 */


/********************  game.c ***********************/

void initGrille(S_partie* unePartie);
/*
 *
 */

short addPlayer(S_partie* unePartie, char* nomJoueur, E_pion typePion);
/*
 *
 */

void destroyPlayers(S_partie* unePartie);
/*
 *
 */

void newGame(S_partie* unePartie, char* nomJoueur1, E_pion typePion1, char* nomJoueur2, E_pion typePion2);
/*
 *
 */

void destroyGame(S_partie* unePartie);
/*
 *
 */

/*********************  PLAY.C  ********************/


short askPlayer(S_joueur* joueur);
/*
 *
 */

E_playStatus playOneTurn(S_partie* unePartie, E_playerNum playerNum);
/*
 *
 */


/********************   CHECK.C   ******************/

E_pion checkLines(E_pion** uneGrille);
/*
 *
 */

E_pion checkCols(E_pion** uneGrille);
/*
 *
 */

E_pion baseLigneAsc(E_pion** uneGrille);
/*
 *
 */

E_pion baseColAsc(E_pion** uneGrille);
/*
 *
 */

E_pion baseLigneDesc(E_pion** uneGrille);
/*
 *
 */

E_pion baseColDesc(E_pion** uneGrille);
/*
 *
 */

E_pion checkAscDiags(E_pion** uneGrille);
/*
 *
 */

E_pion checkDescDiags(E_pion** uneGrille);
/*
 *
 */

E_pion checkGrid(E_pion** uneGrille);
/*
 *
 */
