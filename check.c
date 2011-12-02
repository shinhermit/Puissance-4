#include "puissance4.h"

E_pion checkLines(E_pion** uneGrille)
{
  E_boolean won;
  short i,j,cmpt;
  E_pion refPion;

  won = FALSE;
  i=0;
  while(i<6 && !won)
  {
    cmpt=0;
    refPion = uneGrille[i][0];
    j=0;
    while(j<7 && !won)
    {
      if(uneGrille[i][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][j] != PDP)
	won = TRUE;
      j++;
    }
    i++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion checkCols(E_pion** uneGrille)
{
  E_boolean won;
  short i,j,cmpt;
  E_pion refPion;

  won = FALSE;
  j=0;
  while(j<7 && !won)
  {
    cmpt=0;
    refPion = uneGrille[0][j];
    i=0;
    while(i<6 && !won)
    {
      if(uneGrille[i][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][j] != PDP)
	won = TRUE;
      i++;
    }
    j++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseLigneAsc(E_pion** uneGrille)
{
  short i,iDiag,j,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    refPion = uneGrille[i][0];
    cmpt = 0;
    iDiag=i;
    j=0;
    while(iDiag >= 0 && j<=i && !won)
    {
      if(uneGrille[iDiag][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[iDiag][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[iDiag][j] != PDP)
	won = TRUE;
      iDiag--;
      j++;
    }
    i++;
  }
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseColAsc(E_pion** uneGrille)
{
  short i,j,jDiag,cmpt;
  E_boolean won;
  E_pion refPion;
  
  won = FALSE;
  j=4-1; //4-1: indice débutant à 0
  while(j>0 && !won)
  {
    refPion = uneGrille[6-1][j];
    cmpt = 0;
    i=6-1;
    jDiag=j;
    while(jDiag<7 && i>=j-1 && !won)
    {
      if(uneGrille[i][jDiag] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][jDiag];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][jDiag] != PDP)
	won = TRUE;
      i--;
      jDiag++;
    }
    j--;
    }
  
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseLigneDesc(E_pion** uneGrille)
{
  short i,j,jDiag,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  j=4-1;
  while(j<7-1 && !won)
  {
    refPion = uneGrille[6-1][j];
    cmpt = 0;
    i=6-1;
    jDiag=j;
    while(jDiag >= 0 && i<=(i-j+1) && !won)
    {
      if(uneGrille[i][jDiag] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[i][jDiag];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[i][jDiag] != PDP)
	won = TRUE;
      i--;
      jDiag--;
    }
    j++;
  }
  
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion baseColDesc(E_pion** uneGrille)
{
  short i,iDiag,j,cmpt;
  E_boolean won;
  E_pion refPion;

  won = FALSE;
  i=4-1; //4-1: indice débutant à 0
  while(i<6 && !won)
  {
    refPion = uneGrille[i][7-1];
    cmpt = 0;
    j=7-1;
    iDiag=i;
    while(iDiag >= 0 && j<=(j-i+1) && !won)
    {
      if(uneGrille[iDiag][j] == refPion)
	++cmpt;
      else
      {
	refPion = uneGrille[iDiag][j];
	cmpt = 1;
      }
      if(cmpt == 4 && uneGrille[iDiag][j] != PDP)
	won = TRUE;
      j--;
      iDiag--;
    }
    i++;
  }
  
  if(won)
    return refPion;
  else
    return PDP;
}

E_pion checkAscDiags(E_pion** uneGrille)
{
  E_pion pion;

  pion = baseLigneAsc(uneGrille);
  if(pion != PDP)
    return pion;
  pion = baseColAsc(uneGrille);
  return pion;
}

E_pion checkDescDiags(E_pion** uneGrille)
{
  E_pion pion;

  pion = baseLigneDesc(uneGrille);
  if(pion != PDP)
    return pion;
  pion = baseColDesc(uneGrille);
  return pion;
}

E_pion checkGrid(E_pion** uneGrille)
{
  E_pion pion;

  pion = checkLines(uneGrille);
  if(pion != PDP)
    return pion;
  pion = checkCols(uneGrille);
  if(pion != PDP)
    return pion;
  pion = checkAscDiags(uneGrille);
  if(pion != PDP)
    return pion;
  return checkDescDiags(uneGrille);
}
