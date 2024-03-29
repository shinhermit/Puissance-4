/**
 *@file play.h
 *@brief Implement actions
 *functions to implement the actions in the game
 *@author Josuah Aron
 *@version 1.3
 */
#ifndef PLAY_H
  #define PLAY_H

/**
 *@fn short askPlayer(S_player* player)
 *@brief what to do?
 *Prompts for the player decision
 *@return a value of type short corresponding to the column where the player chose to play
 *@param player the instance of struct S_player corresponding to the player who's turn to play
*/
short askPlayer(S_player* player);

/**
 *@fn E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum, no_gui, log)
 *@brief play!
 *modifies the game according to the decision of the player
 *@return a value of type enum E_playStatus which tell the program what to do (play again, next to play, quit game)
 *@param aGame the instance of struct S_game which represents the party
 *@param playerNum the number ID of the player who plays
 *@param no_gui if set to TRUE, desactivates the basic gui. Depends on whether the commandline option --nogui is passed or not
 *@param log if its value is TRUE, the partie is echoed in a log file power4.log
*/
E_playStatus playOneTurn(S_game* aGame, E_playerNum playerNum, E_boolean no_gui, E_boolean log, FILE* logpath);


#endif //PLAY_H
