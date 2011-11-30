//il me faudra un .h !!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 20

typedef enum
{
  FALSE,TRUE
}E_boolean;

typedef enum
{
  X,O,PDP
}E_pion;
//PDP: pas de pion

typedef enum
{
  J1,J2
}E_playerNum;

typedef enum
{
  FULL_NOT_PLAYED, PLAYED_NOT_FULLED, PLAYED_FULLED, QUIT_GAME
}E_playStatus;

typedef struct
{
  short num;
  char name[MAXSTR];
  E_pion typePion;
}S_joueur;

typedef struct
{
  E_pion **grille;
  S_joueur *players[2];
  short nbPlayers;
  E_playerNum aQuiLeTour; // Joueur1 par défaut
}S_partie;

void usage(char* progName)
{
  printf("Usage:\n %s -j1 nom -p pion -j2 nom\n", progName);
  printf("Pour afficher cette aide:\n %s -h\n", progName);
}

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
  case PDP:
    return '*';
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
  system("clear");
  gameStats(unePartie);
}

void initGrille(S_partie* unePartie)
{
  E_pion **grille = (E_pion**)malloc( 6*7*sizeof(E_pion) );
  int i,j;
  for(i=0; i<6; ++i)
  {
    grille[i] = (E_pion*)malloc( 7*sizeof(E_pion) );
    for(j=0; j<7; ++j)
      grille[i][j] = PDP;
  }
  unePartie->grille = grille;
}

short addPlayer(S_partie* unePartie, char* nomJoueur, E_pion typePion)
{
  S_joueur* joueur = (S_joueur*)malloc( sizeof(S_joueur) );

  if(0 <= unePartie->nbPlayers && unePartie->nbPlayers < 2)
  {
    joueur->num = unePartie->nbPlayers + 1;
    if(nomJoueur)
      strcpy(joueur->name, nomJoueur);
    if(unePartie->nbPlayers == 0)
    {
      if(!nomJoueur)
	strcpy(joueur->name, "Joueur1");
      if(typePion != PDP)
	joueur->typePion = typePion;
      else
	joueur->typePion = X;
    }
    else
    {
      if(!nomJoueur)
	strcpy(joueur->name, "Joueur2");
      joueur->typePion = (unePartie->players[unePartie->nbPlayers-1]->typePion == X) ? O : X;
    }
    unePartie->players[unePartie->nbPlayers] = joueur;
    unePartie->nbPlayers ++;
    return unePartie->nbPlayers;
  }
  else
  {
    printf("Maximum: 2 joueurs\n");
    return 0;
  }
}

void destroyPlayers(S_partie* unePartie)
{
  int i;
  for(i=0; i<unePartie->nbPlayers; ++i)
    free(unePartie->players[i]);
}

void newGame(S_partie* unePartie, char* nomJoueur1, E_pion typePion1, char* nomJoueur2, E_pion typePion2)
{
  initGrille(unePartie);
  unePartie->nbPlayers = 0;
  unePartie->aQuiLeTour = J1;
  addPlayer(unePartie, nomJoueur1, typePion1);
  addPlayer(unePartie, nomJoueur2, typePion2);
}

void destroyGame(S_partie* unePartie)
{
  destroyPlayers(unePartie);
  free(unePartie->grille);
  free(unePartie);
}

E_pion checkLines(E_pion** uneGrille)
{
  E_boolean won;
  short i,j,cmpt;
  E_pion refPion;

  won = FALSE;
  i=0;
  while(i<6 && !won)
  {
    cmpt=0;
    refPion = uneGrille[i][0];
    j=0;
    while(j<7 && !won)
    {
      if(uneGrille[i][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][j] != PDP)
	won = TRUE;
      j++;
    }
    i++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion checkCols(E_pion** uneGrille)
{
  E_boolean won;
  short i,j,cmpt;
  E_pion refPion;

  won = FALSE;
  j=0;
  while(j<7 && !won)
  {
    cmpt=0;
    refPion = uneGrille[0][j];
    i=0;
    while(i<6 && !won)
    {
      if(uneGrille[i][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][j] != PDP)
	won = TRUE;
      i++;
    }
    j++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseLigneAsc(E_pion** uneGrille)
{
  short i,iDiag,j,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    iDiag=i;
    while(iDiag >= 0 && !won)
    {
      refPion = uneGrille[iDiag][0];
      cmpt = 0;
      j=0;
      while(j<=i && !won)
      {
	if(uneGrille[iDiag][j] == refPion)
	  ++cmpt;
	else
	{
	  refPion = uneGrille[iDiag][j];
	  cmpt = 1;
	}
	if(cmpt == 4 && uneGrille[iDiag][j] != PDP)
	  won = TRUE;
	j++;
      }
      iDiag--;
    }
    i++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseColAsc(E_pion** uneGrille)
{
  short i,j,jDiag,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  j=4-1; //4-1: indice débutant à 0
  while(j>0 && !won)
  {
    jDiag=j;
    while(jDiag<7 && !won)
    {
      refPion = uneGrille[6-1][jDiag];
      cmpt = 0;
      i=6-1;
      while(i>=j-1 && !won)
      {
	if(uneGrille[i][jDiag] == refPion)
	  ++cmpt;
	else
	{
	  refPion = uneGrille[i][jDiag];
	  cmpt = 1;
	}
	if(cmpt == 4 && uneGrille[i][jDiag] != PDP)
	  won = TRUE;
	i--;
      }
      jDiag++;
    }
    j--;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseLigneDesc(E_pion** uneGrille)
{
  short i,j,jDiag,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  j=4-1;
  while(j<7-1 && !won)
  {
    jDiag=j;
    while(jDiag >= 0 && !won)
    {
      refPion = uneGrille[6-1][jDiag];
      cmpt = 0;
      i=6-1;
      while(i<=(i-j+1) && !won)
      {
	if(uneGrille[i][jDiag] == refPion)
	  ++cmpt;
	else
	{
	  refPion = uneGrille[i][jDiag];
	  cmpt = 1;
	}
	if(cmpt == 4 && uneGrille[i][jDiag] != PDP)
	  won = TRUE;
	i--;
      }
      jDiag--;
    }
    j++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseColDesc(E_pion** uneGrille)
{
  short i,iDiag,j,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    iDiag=i;
    while(iDiag >= 0 && !won)
    {
      refPion = uneGrille[iDiag][7-1];
      cmpt = 0;
      j=7-1;
      while(j<=(j-i+1) && !won)
      {
	if(uneGrille[iDiag][j] == refPion)
	  ++cmpt;
	else
	{
	  refPion = uneGrille[iDiag][j];
	  cmpt = 1;
	}
	if(cmpt == 4 && uneGrille[iDiag][j] != PDP)
	  won = TRUE;
	j--;
      }
      iDiag--;
    }
    i++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion checkAscDiags(E_pion** uneGrille)
{
  E_pion pion;

  pion = baseLigneAsc(uneGrille);
  if(pion != PDP)
    return pion;
  pion = baseColAsc(uneGrille);
  return pion;
}

E_pion checkDescDiags(E_pion** uneGrille)
{
  E_pion pion;

  pion = baseLigneDesc(uneGrille);
  if(pion != PDP)
    return pion;
  pion = baseColDesc(uneGrille);
  return pion;
}

E_pion checkGrid(E_pion** uneGrille)
{
  E_pion pion;

  pion = checkLines(uneGrille);
  if(pion != PDP)
    return pion;
  pion = checkCols(uneGrille);
  if(pion != PDP)
    return pion;
  pion = checkAscDiags(uneGrille);
  if(pion != PDP)
    return pion;
  return checkDescDiags(uneGrille);
}

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

void displayWinner(S_partie* unePartie)
{
  E_playerNum playerNum;

  if(unePartie->aQuiLeTour == J1)
    playerNum = J2;
  else
    playerNum = J1;
  printf("%s est le vainqueur!\n", unePartie->players[playerNum]->name);
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
