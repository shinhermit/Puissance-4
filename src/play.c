#include "power4.h"
#include "display.h"
#include "game.h"
#include "play.h"

short askPlayer(S_player* player)
{
  short col;
  char quit;

  printf("%s must play\n", player->name);
  do
  {
    printf("Quit: 0\n");
    printf("Colomn(1-7) ?  ");
    scanf("%1hd%*c", &col);
  }while(col<0 || col > 7);
  return col-1;
}

E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum, E_boolean no_gui, E_boolean logfile, FILE* logpath)
{
  short i, col;
  E_boolean emptyCell;

  col = askPlayer(aGame->players[playerNum]);
  if(col == -1)
    return QUIT_GAME;
  emptyCell = TRUE;
  i=0;
  while(i<6 && emptyCell)
  {
    if(aGame->grid[i][col] == NP)
       ++i;
    else
      emptyCell = FALSE;
  }
  if(i == 0)
  {
    if(logfile)
      log_print(logpath, "%s tried to play in column %d\nImpossible action: column is full\n\n", aGame->players[playerNum]->name, col+1);
    return FULL_NOT_PLAYED;
  }
  if(i > 0)
  {
    aGame->grid[i-1][col] = aGame->players[playerNum]->pawnType;

    if(playerNum == P1)
      aGame->whoMustPlay = P2;
    else
      aGame->whoMustPlay = P1;
    
    if(no_gui)
      printf("%s played in column %d\n", aGame->players[playerNum]->name, col+1);
    if(logfile)
      log_print(logpath, "%s played in column %d\n\n", aGame->players[playerNum]->name, col+1);

    if(i == 1)
      return PLAYED_FULLED;
    else
      return PLAYED_NOT_FULLED;
  }
}
