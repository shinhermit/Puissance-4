/*
 *Power4 v3
 *display.c v2
 */
#include "power4.h"

char convPawn(E_pawn pawn)
{
  switch(pawn)
  {
  case X:
    return 'X';
    break;
  case O:
    return 'O';
    break;
  case N: // Neutral, for tests only
    return '*';
    break;
  case NP: //No Pawn
    return ' ';
  }
}

void printLine(E_pawn* vect, int nbElts)
{
	int i;
	
	printf("|");
	for(i=0; i<nbElts; i++)
	{
	  printf( "%c|", convPawn(vect[i]) );
	}
	printf("\n");	
}

void hline(int lnLen)
{
  int i;
  for(i=0; i<lnLen; ++i)
    printf("-");
  printf("\n");
}

void numberize(int lnLen)
{
  int i;
  printf(" ");
  for(i=1; i<=lnLen; ++i)
    printf("%d ", i);
  printf("\n");
}

void printGrid(E_pawn** mat, int nLn, int nCol)
{
  int i;
  numberize(nCol);
  hline(2*nCol+1);
  for(i=0; i<nLn; ++i)
  {
    printLine(mat[i], nCol);
    hline(2*nCol+1);
  }
  printf("\n");
}

void gameStats(S_game* aGame)
{
  printf( "%s(pawn %c) vs %s(pawn %c)\n\n", aGame->players[0]->name, convPawn(aGame->players[0]->pawnType), aGame->players[1]->name, convPawn(aGame->players[1]->pawnType) );
  printGrid( (E_pawn**)aGame->grid, 6, 7 );
}

void refreshScreen(S_game* aGame)
{
  //system("clear");
  gameStats(aGame);
}

void displayWinner(S_game* aGame)
{
  E_playerNum playerNum;

  if(aGame->whoMustPlay == P1)
    playerNum = P2;
  else
    playerNum = P1;
  printf("%s Is the winner!\n", aGame->players[playerNum]->name);
}
