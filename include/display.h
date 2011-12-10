/**
 *@file display.h
 *@brief Basic gui
 *function for a basic gui in terminal
 *@author Josuah Aron
 *@version 1.3
 */
#ifndef DISPLAY_H
  #define DISPLAY_H


/**
 *@fn char convPawn(E_pawn pawn)
 *@brief converts E_pawn to char
 *converts to a character ('X' ou 'O') sothat the grid can be displayed
 *@param E_pawn pawn: The pawn to be converted, type E_pawn (enum)
 *@return a character 'X' or 'O' corresponding to the pawn to be displayed
 */
char convPawn(E_pawn pawn);

/**
 *@fn void printLine(E_pawn* vect, int nbElts)
 *@brief prints grid lines
 * Prints a line of the grid considered as a vector
 *@return no return value
 *@param vect the line of the grid, considered as a vector
 *@param nbElts number of elements of the line 
 */
void printLine(E_pawn* vect, int nbElts);

/**
 *@fn void hline(int lnLen)
 *@brief gui separating line
 *Prints an horizontal separating line for the grid in the basic gui.
 *@return void.
 *@param lnLen line length, an integer.
*/
void hline(int lnLen);

/**
 *@fn void displayColsNum(int lnLen)
 *Displays the numbers the columns of the grid
 *@return void.
 *@param lnLen: width of the grid
*/
void displayColsNum(int lnLen);

/**
 *@fn void printGrid(E_pawn** mat, int nLgn, int nCol)
 *@brief displays the grid
 *Prints the game board (the grid, considered as a matrice actually)
 *@return void.
 *@param mat the grid (matrice) to be displayed. Must be correctly allocated first
 *@param nLgn number of lines of the grid
 *@param nCol numbre of columns of the grid
*/
void printGrid(E_pawn** mat, int nLgn, int nCol);

/**
 *@fn void gameStats(S_game* aGame)
 *@brief Game State
 *Displays the current situation of the game (the grid, the player who can play, etc.)
 *@return void
 *@param aGame A structure representing the game
*/
void gameStats(S_game* aGame);

/**
 *@fn void refreshScreen(S_game* aGame)
 *@grief refresh console
 *refresh the screen of the terminal (basic gui) an displays game stats again
 *@return void
 *@param aGame A structure representing the game
*/
void refreshScreen(S_game* aGame);

/**
 *@fn void displayWinner(S_game* aGame)
 *@brief win message
 *Displays the messages when a player wins
 *@return void
 *@param aGame A structure of type S_game representing the game
*/
void displayWinner(S_game* aGame);

#endif //DISPLAY_H
