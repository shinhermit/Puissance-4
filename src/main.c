/*
 *Power4 v3
 *main.c v2
 */
#include "power4.h"

void usage(char* progName)
{
  printf("Usage:\n %s -j1 name -p pion -j2 name\n", progName);
  printf("Show this help:\n %s -h\n", progName);
}

int main(int argc, char** argv)
{
  S_game* theGame = (S_game*)malloc( sizeof(S_game) );
  E_pawn pawn;
  E_boolean won, full, stoppedByUser;
  short fullColCount;
  E_playStatus status;

  if(argc < 5)
  {
    usage(argv[0]);
    newGame(theGame, "Player1", X, "Player2", O);
  }
  else
  {
    if(argv[4] == "X") pawn = X;
    else pawn = O;
    newGame(theGame, argv[2], pawn, argv[6], NP);
  }
  gameStats(theGame);
  fullColCount = 0;
  full = FALSE;
  won = FALSE;
  stoppedByUser = FALSE;
  while(!full && !won && !stoppedByUser)
  {
    status = playOneTurn(theGame, theGame->whoMustPlay);
    refreshScreen(theGame);
    if(status == PLAYED_FULLED)
      fullColCount++;
    else
      if(status == FULL_NOT_PLAYED)
	printf("Colonne pleine, rejouer\n");
      else
	if(status == QUIT_GAME)
	  stoppedByUser = TRUE;
    if(fullColCount == 7)
      full = TRUE;
    pawn = checkGrid(theGame->grid);
    if(pawn != NP)
      won = TRUE;
  }
  printf("END OF THE GAME !\n");
  if(won)
    displayWinner(theGame);
  else
    if(!stoppedByUser)
      printf("Draw.\n");
  destroyGame(theGame);
  return 0;
}
