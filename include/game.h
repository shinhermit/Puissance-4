/**
 *@file game.h
 *@brief party ressources
 *functions to manage the party and the ressources
 *@author Josuah Aron
 *@version 1.4
 */
#ifndef GAME_H
  #define GAME_H

/**
 *@def MAXSTR 20
 *@brief max strings length
 *The macro-definition MAXSTR sets the max length of string in the program
 */
#define MAXSTR 20


/**
 *@fn void initGrid(S_game* aGame)
 *@brief new grid
 *Initializes the grid: allocates and fills it with NP type pawn (No Pawn)
 *@return void
 *@param aGame A S_game struct instance
*/
void initGrid(S_game* aGame);

/**
 *@fn short addPlayer(S_game* aGame, char* playerName, E_pawn pawnType)
 *@brief new player
 *@return A short int for the number ID of the added player
 *@param aGame the instance S_game struct which represents the party
 *@param playerName a char* containing the name of player
 *@param pawnType a value of type enum E_pawn, representing the type of pawn for the player
*/
short addPlayer(S_game* aGame, char* playerName, E_pawn pawnType);

/**
 *@fn void destroyPlayers(S_game* aGame)
 *@brief delete player
 *free the memory allocated to the instances of S_player which represents the players
 *@return void
 *@param aGame the instance of S_game struct that represents the party
*/
void destroyPlayers(S_game* aGame);

/**
 *@fn void newGame(S_game* aGame, char* playerName1, E_pawn pawnType1, char* playerName2, E_pawn pawnType2)
 *@brief new party
 *creates a new party, ie an instance of S_game struct, plus the instances of S_player struct
 *@return void
 *@param aGame the instance of S_game struct which represents the party
 *@param playerName1 a string containing the name for player 1
 *@param pawnType1 a value of type enum E_pawn representing the type pawn for player 1
 *@param playerName1 a string containing the name for player 2
 *@param pawnType1 a value of type enum E_pawn representing the type pawn for player 2
*/
void newGame(S_game* aGame, char* playerName1, E_pawn pawnType1, char* playerName2, E_pawn pawnType2);

/**
 *@fn void destroyGame(S_game* aGame)
 *@brief delete game
 *Free the memory allocated to the ressources needed by the instance of struct S_game which represents the party
 *@return void
 *@param aGame the instance of S_game struct which represents the party
*/
void destroyGame(S_game* aGame);


#endif //GAME_H
