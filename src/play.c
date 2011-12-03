/*
 *Power4 v3
 *play.c v2
 */
#include "power4.h"

short askPlayer(S_player* player)
{
  short col;
  char quit;

  printf("%s must play\n", player->name);
  do
  {
    printf("Quit: 0\n");
    printf("Colomn(1-7) ?  ");
    scanf("%hd%*c", &col);
  }while(col<0 || col > 7);
  return col-1;
}

E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum)
{
  short i, col;
  E_boolean blankSet;

  col = askPlayer(aGame->players[playerNum]);
  if(col == -1)
    return QUIT_GAME;
  blankSet = TRUE;
  i=0;
  while(i<6 && blankSet)
  {
    if(aGame->grid[i][col] == NP)
       ++i;
    else
      blankSet = FALSE;
  }
  if(i == 0)
    return FULL_NOT_PLAYED;
  if(i > 0)
  {
    aGame->grid[i-1][col] = aGame->players[playerNum]->pawnType;

    if(playerNum == P1)
      aGame->whoMustPlay = P2;
    else
      aGame->whoMustPlay = P1;
    
    if(i == 1)
      return PLAYED_FULLED;
    else
      return PLAYED_NOT_FULLED;
  }
}
