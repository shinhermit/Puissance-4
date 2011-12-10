/**
 *@file cmndLine.h
 *@brief Lunching options
 *functions to manage command line option
 *@author Josuah Aron
 *@version 1.4
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

#endif //CMNDLINE_H
