#include "puissance4.h"

short askPlayer(S_joueur* joueur)
{
  short col;
  char quit;

  printf("%s doit poser un pion\n", joueur->name);
  do
  {
    printf("Quitter: 0\n");
    printf("Colonne(1-7) ?  ");
    scanf("%hd%*c", &col);
  }while(col<0 || col > 7);
  return col-1;
}

E_playStatus playOneTurn(S_partie* unePartie, E_playerNum playerNum)
{
  short i, col;
  E_boolean caseVide;

  col = askPlayer(unePartie->players[playerNum]);
  if(col == -1)
    return QUIT_GAME;
  caseVide = TRUE;
  i=0;
  while(i<6 && caseVide)
  {
    if(unePartie->grille[i][col] == PDP)
       ++i;
    else
      caseVide = FALSE;
  }
  if(i == 0)
    return FULL_NOT_PLAYED;
  if(i > 0)
  {
    unePartie->grille[i-1][col] = unePartie->players[playerNum]->typePion;

    if(playerNum == J1)
      unePartie->aQuiLeTour = J2;
    else
      unePartie->aQuiLeTour = J1;
    
    if(i == 1)
      return PLAYED_FULLED;
    else
      return PLAYED_NOT_FULLED;
  }
}
