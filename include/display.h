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
 *@fn void log_print(const char* format, ...)
 *@brief prints in logfile
 *Prints the current action in the logfile
 *@return void
 *@param logpath a FILE* ressource opened on the logfile with const LOGPATH
 *@param format printf type string format
 *@param playerName the name of the player who just played
 *@param col the column where he chose to play
 */
void log_print(FILE* logpath, const char* format, char* playerName, short col);

/**
 *@fn void showHelp(char* progName)
 *@brief command line options
 *Displays all command line options and their descriptions.
 *@return void
 *@param progName The name of the programme, generally provided by argv[0]
 */

void showHelp(char* progName);

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
 *@param logfile This E_boolean indicates if the function must write in the file power4.log
 *@param logpath a FILE ressource opened on the the log file
*/
void displayWinner(S_game* aGame, E_boolean logfile, FILE* logpath);

#endif //DISPLAY_H
