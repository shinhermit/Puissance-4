#include "puissance4.h"

char convPion(E_pion pion)
{
  switch(pion)
  {
  case X:
    return 'X';
    break;
  case O:
    return 'O';
    break;
  case N:
    return '*';
    break;
  case PDP:
    return ' ';
  }
}

void printLine(E_pion* vect, int nbElts)
{
	int i;
	
	printf("|");
	for(i=0; i<nbElts; i++)
	{
	  printf( "%c|", convPion(vect[i]) );
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

void printGrille(E_pion** mat, int nLgn, int nCol)
{
  int i;
  numberize(nCol);
  hline(2*nCol+1);
  for(i=0; i<nLgn; ++i)
  {
    printLine(mat[i], nCol);
    hline(2*nCol+1);
  }
  printf("\n");
}

void gameStats(S_partie* unePartie)
{
  printf( "%s(pion %c) vs %s(pion %c)\n\n", unePartie->players[0]->name, convPion(unePartie->players[0]->typePion), unePartie->players[1]->name, convPion(unePartie->players[1]->typePion) );
  printGrille( (E_pion**)unePartie->grille, 6, 7 );
}

void refreshScreen(S_partie* unePartie)
{
  //system("clear");
  gameStats(unePartie);
}

void displayWinner(S_partie* unePartie)
{
  E_playerNum playerNum;

  if(unePartie->aQuiLeTour == J1)
    playerNum = J2;
  else
    playerNum = J1;
  printf("%s est le vainqueur!\n", unePartie->players[playerNum]->name);
}
