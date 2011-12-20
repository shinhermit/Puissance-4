<<<<<<< HEAD
#include "power4.h"
#include "display.h"
#include "game.h"
#include "play.h"
=======
/*
 *Power4 v3
 *play.c v2
 */
#include "power4.h"
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac

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

<<<<<<< HEAD
E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum, E_boolean no_gui, E_boolean logfile, FILE* logpath)
{
  short i, col;
  E_boolean emptyCell;
=======
E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum)
{
  short i, col;
  E_boolean blankSet;
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac

  col = askPlayer(aGame->players[playerNum]);
  if(col == -1)
    return QUIT_GAME;
<<<<<<< HEAD
  emptyCell = TRUE;
  i=0;
  while(i<6 && emptyCell)
=======
  blankSet = TRUE;
  i=0;
  while(i<6 && blankSet)
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac
  {
    if(aGame->grid[i][col] == NP)
       ++i;
    else
<<<<<<< HEAD
      emptyCell = FALSE;
  }
  if(i == 0)
  {
    if(logfile)
      log_print(logpath, "%s tried to play in column %d\nImpossible action: column is full\n\n", aGame->players[playerNum]->name, col+1);
    return FULL_NOT_PLAYED;
  }
=======
      blankSet = FALSE;
  }
  if(i == 0)
    return FULL_NOT_PLAYED;
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac
  if(i > 0)
  {
    aGame->grid[i-1][col] = aGame->players[playerNum]->pawnType;

    if(playerNum == P1)
      aGame->whoMustPlay = P2;
    else
      aGame->whoMustPlay = P1;
    
<<<<<<< HEAD
    if(no_gui)
      printf("%s played in column %d\n", aGame->players[playerNum]->name, col+1);
    if(logfile)
      log_print(logpath, "%s played in column %d\n\n", aGame->players[playerNum]->name, col+1);

=======
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac
    if(i == 1)
      return PLAYED_FULLED;
    else
      return PLAYED_NOT_FULLED;
  }
}
