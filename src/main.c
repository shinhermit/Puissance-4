#include "puissance4.h"

void usage(char* progName)
{
  printf("Usage:\n %s -j1 nom -p pion -j2 nom\n", progName);
  printf("Pour afficher cette aide:\n %s -h\n", progName);
}

int main(int argc, char** argv)
{
  S_partie* laPartie = (S_partie*)malloc( sizeof(S_partie) );
  E_pion pion;
  E_boolean won, full, stoppedByUser;
  short fullColCount;
  E_playStatus status;

  if(argc < 5)
  {
    usage(argv[0]);
    newGame(laPartie, "Joueur1", X, "Joueur2", O);
  }
  else
  {
    if(argv[4] == "X") pion = X;
    else pion = O;
    newGame(laPartie, argv[2], pion, argv[6], PDP);
  }
  gameStats(laPartie);
  fullColCount = 0;
  full = FALSE;
  won = FALSE;
  stoppedByUser = FALSE;
  while(!full && !won && !stoppedByUser)
  {
    status = playOneTurn(laPartie, laPartie->aQuiLeTour);
    refreshScreen(laPartie);
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
    pion = checkGrid(laPartie->grille);
    if(pion != PDP)
      won = TRUE;
  }
  printf("FIN DE PARTIE !\n");
  if(won)
    displayWinner(laPartie);
  else
    if(!stoppedByUser)
      printf("Match nul.\n");
  destroyGame(laPartie);
  return 0;
}
