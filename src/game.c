#include "power4.h"
#include "display.h"
#include "game.h"

void initGrid(S_game* aGame)
{
  E_pawn **grid = (E_pawn**)malloc( 6*7*sizeof(E_pawn) );
  int i,j;
  for(i=0; i<6; ++i)
  {
    grid[i] = (E_pawn*)malloc( 7*sizeof(E_pawn) );
    for(j=0; j<7; ++j)
      grid[i][j] = NP;
  }
  aGame->grid = grid;
}

short addPlayer(S_game* aGame, char* playerName, E_pawn pawnType)
{
  S_player* player = (S_player*)malloc( sizeof(S_player) );

  if(0 <= aGame->nbPlayers && aGame->nbPlayers < 2)
  {
    player->num = aGame->nbPlayers + 1;
    if(playerName)
      strcpy(player->name, playerName);
    if(aGame->nbPlayers == 0)
    {
      if(!playerName)
	strcpy(player->name, "Player1");
      if(pawnType != NP)
	player->pawnType = pawnType;
      else
	player->pawnType = X;
    }
    else
    {
      if(!playerName)
	strcpy(player->name, "Player2");
      player->pawnType = (aGame->players[aGame->nbPlayers-1]->pawnType == X) ? O : X;
    }
    aGame->players[aGame->nbPlayers] = player;
    aGame->nbPlayers ++;
    return aGame->nbPlayers;
  }
  else
  {
    printf("Maximum: 2 player\n");
    return 0;
  }
}

void destroyPlayers(S_game* aGame)
{
  int i;
  for(i=0; i<aGame->nbPlayers; ++i)
    free(aGame->players[i]);
}

void newGame(S_game* aGame, char* playerName1, E_pawn pawnType1, char* playerName2, E_pawn pawnType2)
{
  initGrid(aGame);
  aGame->nbPlayers = 0;
  aGame->whoMustPlay = P1;
  addPlayer(aGame, playerName1, pawnType1);
  addPlayer(aGame, playerName2, pawnType2);
}

void destroyGame(S_game* aGame)
{
  destroyPlayers(aGame);
  free(aGame->grid);
  free(aGame);
}
