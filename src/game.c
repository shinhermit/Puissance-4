#include <string.h>
#include "puissance4.h"

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
