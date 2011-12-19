/**
 *@file cmndLine.h
 *@brief Lunching options
 *functions to manage command line option
 *@author Josuah Aron
 *@version 1.5
 */
#ifndef CMNDLINE_H
  #define CMNDLINE_H

/**
 *@fn void usage(char* progName)
 *@brief how to?
 *displays how to run the program with the needed options and how to access the help
 *@return void
 *@param progName The name of the programme, generally provided by argv[0]
*/
void usage(char* progName);

/**
 *@fn E_boolean parseCmndLine(int argc, char** argv, E_boolean* help, E_boolean* no_gui, E_boolean* logfile, char* player1, char* player2, E_pion* player1_pawnType)
 *@brief manages command line options
 *Sets the values of the differents user control parameters.
 *@return E_boolean TRUE if all parameters are correct, FALSE if unknown options are uncountered.
 *@param argc command line number of parameters. Provided by function main argc argument
 *@param argv array of commande line parameters as strings. Provided by function main argv argument.
 *@param help this E_boolean variable will be assigned TRUE if parameter --help is encountered
 *@param no_gui This E_boolean variable will be assigned TRUE if option --nogui is encountered
 *@param lofile This E_boolean varaible will ne assigned TRUE if option --log is encountered
 *@param player1Name_index This int will be assigned the position of  the name of player 1 in array argv
 *@param player2Name_index This int will be assigned the position of thee name of player 2 in array argv
 *@param player1_pawnType This variable of type E_pawn will be assigned the type of pawn that player 1 will use
 */
E_boolean parseCmndLine(int argc, char** argv, E_boolean* help, E_boolean* no_gui, E_boolean* logfile, int* player1Name_index, int* player2Name_index, E_pawn* player1_pawnType);

#endif //CMNDLINE_H
