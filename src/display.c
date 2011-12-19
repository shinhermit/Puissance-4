#include "power4.h"
#include "display.h"

void log_print(FILE* logpath, const char* format, char* playerName, short col)
{
  fseek(logpath, 0L, SEEK_END);//on se place à la fin (append)

  if(playerName && col!=-1)
    fprintf(logpath, format, playerName, col);
  else
    if(playerName)
      fprintf(logpath, format, playerName);
    else
      if(col>0)
	fprintf(logpath, format, col);
      else
	fprintf(logpath, format);
}

void showHelp(char* progName)
{
  printf("\n %s [--help] [--nogui] [--log] [-j1 player1Name] [-p pawnType] [-j2 player2Name]\n\n", progName);
  printf("--help: Show this help. The program won't run.\n");
  printf("--nogui: desactivate basic gui. Actions are echoed as text messages.\n");
  printf("--log: Record actions in a logfile. The name of this file is %s.log\n", progName);
  printf("-j1: enter the name of player1 after this marker.\n");
  printf("-j2: enter the name of player2 after this marker.\n");
  printf("-p: enter the type of pawn for player 1.\n\t X or O\n");
}

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
  case N:
    return '*';
    break;
  case NP:
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

void displayColsNum(int lnLen)
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
  displayColsNum(nCol);
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
  system("clear");
  gameStats(aGame);
}

void displayWinner(S_game* aGame, E_boolean logfile, FILE* logpath)
{
  E_playerNum playerNum;

  if(aGame->whoMustPlay == P1)
    playerNum = P2;
  else
    playerNum = P1;

  printf("%s Is the winner!\n", aGame->players[playerNum]->name);
  if(logfile)
    log_print(logpath, "%s Is the winner!\n", aGame->players[playerNum]->name, -1);
}
