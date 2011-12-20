<<<<<<< HEAD
#include "power4.h"
#include "display.h"
#include "game.h"
#include "play.h"
#include "check.h"
#include "cmndLine.h"
=======
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
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac

int main(int argc, char** argv)
{
  S_game* theGame = (S_game*)malloc( sizeof(S_game) );
  E_pawn pawn;
<<<<<<< HEAD
  E_boolean showUsage, won, full, stoppedByUser, help, no_gui, logfile;
  short fullColCount;
  int player1Name_index, player2Name_index;
  E_playStatus status;
  FILE* logpath;

  showUsage = !parseCmndLine(argc, argv, &help, &no_gui, &logfile, &player1Name_index, &player2Name_index, &pawn);
  if(argc < 2 || showUsage)
    usage(argv[0]);

  if(!help)
  {
    if(logfile)
      logpath = fopen(LOGPATH, "w");
    else
      logpath = NULL;
    if(player1Name_index > 0 && player2Name_index > 0)
      newGame(theGame, argv[player1Name_index], pawn, argv[player2Name_index], NP);
    else
      if(player1Name_index > 0)
	newGame(theGame, argv[player1Name_index], pawn, "Player2", NP);
      else
	if(player2Name_index > 0)
	  newGame(theGame, "Player1", pawn, argv[player2Name_index], NP);
	else
	  newGame(theGame, "Player1", pawn, "Player2", NP);
    fullColCount = 0;
    full = FALSE;
    won = FALSE;
    stoppedByUser = FALSE;
    if(!no_gui)
      gameStats(theGame);
    while(!full && !won && !stoppedByUser)
      {
	status = playOneTurn(theGame, theGame->whoMustPlay, no_gui, logfile, logpath);
	if(!no_gui)
	  refreshScreen(theGame);
	if(status == PLAYED_FULLED)
	  fullColCount++;
	else
	  if(status == FULL_NOT_PLAYED)
	    printf("The column is full, please play again\n");
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
    if(logfile)
      log_print(logpath, "END OF THE GAME.\n", NULL, -1);
    if(won)
      displayWinner(theGame, logfile, logpath);
    else
      if(!stoppedByUser)
      {
	printf("Draw.\n");
	if(logfile)
	  log_print(logpath, "Draw\n", NULL, -1);
      }
    destroyGame(theGame);
    if(logfile)
      fclose(logpath);
  }
  else
    showHelp(argv[0]);
=======
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
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac
  return 0;
}
