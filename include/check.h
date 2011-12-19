/**
 *@file check.h
 *@brief check the grid
 *fonctions to check if a win state occured
 *@author Josuah Aron
 *@version 1.4
 */
#ifndef CHECK_H
  #define CHECK_H

/**
 *@fn E_pawn checkLines(E_pawn** aGrid)
 *@brief ckecks lines
 *Ckeck the grid in the horizontal direction to state if a win situation is detected
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn checkLines(E_pawn** aGrid);

/**
 *@fn E_pawn checkCols(E_pawn** aGrid)
 *@brief ckecks columns
 *Ckeck the grid in the vertical direction to state if a win situation is detected
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn checkCols(E_pawn** aGrid);

/**
 *@fn E_pawn baseLineAsc(E_pawn** aGrid)
 *@brief Diagonals checking 1
 * 1 2 3 4 5 6 7
 *| | | |o|x|#| |
 *---------------
 *| | |o|x|#| | |
 *---------------
 *| |o|x|#| | | |
 *---------------
 *|o|x|#| | | | |
 *---------------
 *|x|#| | | | | |
 *---------------
 *|#| | | | | | |
 *---------------
 *
 *Checks half of the ascending diagonals. Theses diagonals are those which bases are aligned vertically on the first column (at the start of a line => baseLine)
 *Not to be used directly; called by checkAcsDiags
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn baseLineAsc(E_pawn** aGrid);

/**
 *@fn E_pawn baseColAsc(E_pawn** aGrid)
 *@brief Diagonals checking 1
 * 1 2 3 4 5 6 7
 *| | | | | | |x|
 *---------------
 *| | | | | |x|o|
 *---------------
 *| | | | |x|o|*|
 *---------------
 *| | | |x|o|*| |
 *---------------
 *| | |x|o|*| | |
 *---------------
 *| |x|o|*| | | |
 *---------------
 *
 *Checks half of the ascending diagonals. Theses diagonals are those which bases are aligned horizontally on the last line (at the end of a column => baseCol)
 *Not to be used directly; called by checkAcsDiags
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn baseColAsc(E_pawn** aGrid);

/**
 *@fn E_pawn baseLineDesc(E_pawn** aGrid)
 * 1 2 3 4 5 6 7
 *|*| | | | | | |
 *---------------
 *|o|*| | | | | |
 *---------------
 *|x|o|*| | | | |
 *---------------
 *| |x|o|*| | | |
 *---------------
 *| | |x|o|*| | |
 *---------------
 *| | | |x|o|*| |
 *---------------
 *
 *Checks half of the descending diagonals. Theses diagonals are those which bases are aligned vertically on the last column (at the end a line => baseLine)
 *Not to be used directly; called by checkAcsDiags
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn baseLineDesc(E_pawn** aGrid);

/**
 *@fn E_pawn baseColDesc(E_pawn** aGrid)
 * 1 2 3 4 5 6 7
 *| |x|o|*| | | |
 *---------------
 *| | |x|o|*| | |
 *---------------
 *| | | |x|o|*| |
 *---------------
 *| | | | |x|o|*|
 *---------------
 *| | | | | |x|o|
 *---------------
 *| | | | | | |x|
 *---------------
 *
 *Checks half of the descending diagonals. Theses diagonals are those which bases are aligned horizontally on the last line (at the end a line => baseLine)
 *Not to be used directly; called by checkAcsDiags
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn baseColDesc(E_pawn** aGrid);

/**
 *@fn E_pawn checkAscDiags(E_pawn** aGrid)
 *Checks the ascending diagonals by calling baseLineAsc and baseColAsc
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn checkAscDiags(E_pawn** aGrid);

/**
 *@fn E_pawn checkDescDiags(E_pawn** aGrid)
 *Checks the descending diagonals by callign baseLineDesc and baseColDesc
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn checkDescDiags(E_pawn** aGrid);

/**
 *@fn E_pawn checkGrid(E_pawn** aGrid)
 *Checks the grid by calling checkAscDiags and checkDescDiags
 *@return a value of type E_pawn which is the type of pawn of the winner or NP if no winner
 *@param aGrid the playing grid, field of the instance of struct S_game representing the party
*/
E_pawn checkGrid(E_pawn** aGrid);

#endif //CHECK_H
