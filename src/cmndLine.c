#include "power4.h"
#include "display.h"
#include "cmndLine.h"

void usage(char* progName)
{
  printf("Usage:\n %s -j1 name -p pawn -j2 name\n", progName);
  printf("More options:\n %s --help\n", progName);
}

E_boolean parseCmndLine(int argc, char** argv, E_boolean* help, E_boolean* no_gui, E_boolean* logfile, int* player1Name_index, int* player2Name_index, E_pawn* player1_pawnType)
{
  int i;
  E_boolean weCanStop, alright;
  FILE* logpath;

  i=1;
  weCanStop = FALSE;
  alright = TRUE;
  *no_gui = FALSE;
  *logfile = FALSE;
  *help = FALSE;
  *player1Name_index = -1;
  *player2Name_index = -1;
  *player1_pawnType = X;
  while( i < argc && !weCanStop )
  {
    //unknown parameter
    if( strcmp(argv[i], "--help") != 0 && strcmp(argv[i], "--nogui") == 0 && strcmp(argv[i], "--log") == 0 && strcmp(argv[i], "-j1") == 0 && strcmp(argv[i], "-j2") == 0 && strcmp(argv[i], "-p") == 0 )
      alright = FALSE;

    if( strcmp(argv[i], "--help") == 0 )
    {
       *help = TRUE;
       weCanStop = TRUE;
    }
    if( strcmp(argv[i], "--nogui") == 0 )
      *no_gui = TRUE;
    if( strcmp(argv[i], "--log") == 0 )
      *logfile = TRUE;
    if( strcmp(argv[i], "-j1") == 0 )
      if(argv[i+1][0] != '-')
      {
	*player1Name_index = i+1;
	++i;
      }
    if( strcmp(argv[i], "-j2") == 0 )
      if(argv[i+1][0] != '-')
      {
	*player2Name_index = i+1;
	++i;
      }      
    if( strcmp(argv[i], "-p") == 0 )
      if(argv[i+1][0] != '-')
      {
	if( strcmp(argv[i+1], "X") == 0 || strcmp(argv[i+1], "x") == 0 )
	  *player1_pawnType = X;
	else
	  *player1_pawnType = O;
	++i;
      }

      ++i;
  }
  return alright;
}
