<<<<<<< HEAD
#include "power4.h"
#include "display.h"
#include "game.h"
#include "play.h"
#include "check.h"
=======
/*
 *Power4 V3
 *check.c v6
 */
#include "power4.h"
>>>>>>> b52cfc3b286527643a1a14aff3dcfbe4b260dfac

E_pawn checkLines(E_pawn** aGrid)
{
  E_boolean won;
  short i,j,count;
  E_pawn refPawn;

  won = FALSE;
  i=0;
  while(i<6 && !won)
  {
    count=0;
    refPawn = aGrid[i][0];
    j=0;
    while(j<7 && !won)
    {
      if(aGrid[i][j] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[i][j];
	count = 1;
      }
      if(count == 4 && aGrid[i][j] != NP)
	won = TRUE;
      j++;
    }
    i++;
  }
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn checkCols(E_pawn** aGrid)
{
  E_boolean won;
  short i,j,count;
  E_pawn refPawn;

  won = FALSE;
  j=0;
  while(j<7 && !won)
  {
    count=0;
    refPawn = aGrid[0][j];
    i=0;
    while(i<6 && !won)
    {
      if(aGrid[i][j] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[i][j];
	count = 1;
      }
      if(count == 4 && aGrid[i][j] != NP)
	won = TRUE;
      i++;
    }
    j++;
  }
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn baseLineAsc(E_pawn** aGrid)
{
  short i,iDiag,j,count;
  E_boolean won;
  E_pawn refPawn;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    refPawn = aGrid[i][0];
    count = 0;
    iDiag=i;
    j=0;
    while(iDiag >= 0 && j<=i && !won)
    {
      if(aGrid[iDiag][j] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[iDiag][j];
	count = 1;
      }
      if(count == 4 && aGrid[iDiag][j] != NP)
	won = TRUE;
      iDiag--;
      j++;
    }
    i++;
  }
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn baseColAsc(E_pawn** aGrid)
{
  short i,j,jDiag,count;
  E_boolean won;
  E_pawn refPawn;
  
  won = FALSE;
  j=4-1; //4-1: indice débutant à 0
  while(j>0 && !won)
  {
    refPawn = aGrid[6-1][j];
    count = 0;
    i=6-1;
    jDiag=j;
    while(jDiag<7 && i>=j-1 && !won)
    {
      if(aGrid[i][jDiag] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[i][jDiag];
	count = 1;
      }
      if(count == 4 && aGrid[i][jDiag] != NP)
	won = TRUE;
      i--;
      jDiag++;
    }
    j--;
  }
  
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn baseLineDesc(E_pawn** aGrid)
{
  short i,j,jDiag,count;
  E_boolean won;
  E_pawn refPawn;

  won = FALSE;
  j=4-1;
  while(j<7-1 && !won)
  {
    refPawn = aGrid[6-1][j];
    count = 0;
    i=6-1;
    jDiag=j;
    while(jDiag >= 0 && i >= i-j+1 && !won)
    {
      if(aGrid[i][jDiag] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[i][jDiag];
	count = 1;
      }
      if(count == 4 && aGrid[i][jDiag] != NP)
	won = TRUE;
      i--;
      jDiag--;
    }
    j++;
  }
  
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn baseColDesc(E_pawn** aGrid)
{
  short i,iDiag,j,count;
  E_boolean won;
  E_pawn refPawn;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    refPawn = aGrid[i][7-1];
    count = 0;
    j=7-1;
    iDiag=i;
    while(iDiag >= 0 && j >= j-i+1 && !won)
    {
      if(aGrid[iDiag][j] == refPawn)
	++count;
      else
      {
	refPawn = aGrid[iDiag][j];
	count = 1;
      }
      if(count == 4 && aGrid[iDiag][j] != NP)
	won = TRUE;
      j--;
      iDiag--;
    }
    i++;
  }
  
  if(won)
    return refPawn;
  else
    return NP;
}

E_pawn checkAscDiags(E_pawn** aGrid)
{
  E_pawn pawn;

  pawn = baseLineAsc(aGrid);
  if(pawn != NP)
    return pawn;
  pawn = baseColAsc(aGrid);
  return pawn;
}

E_pawn checkDescDiags(E_pawn** aGrid)
{
  E_pawn pawn;

  pawn = baseLineDesc(aGrid);
  if(pawn != NP)
    return pawn;
  pawn = baseColDesc(aGrid);
  return pawn;
}

E_pawn checkGrid(E_pawn** aGrid)
{
  E_pawn pawn;

  pawn = checkLines(aGrid);
  if(pawn != NP)
    return pawn;
  pawn = checkCols(aGrid);
  if(pawn != NP)
    return pawn;
  pawn = checkAscDiags(aGrid);
  if(pawn != NP)
    return pawn;
  return checkDescDiags(aGrid);
}
