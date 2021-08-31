/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/

#include "Functions.h"

/***********************************************************
 *FUNCTION Fill
 *__________________________________________________________
 * This function uses the fill function to fill a whole
 * line with a certain characeter and then it clears it
 * for the next one to be written anything
 * _________________________________________________________
 *
 * PRE-CONDITIONS
 * 	outputT  : output stream
 * 	fillChar : character to fill the line with
 * 	width    : width of the line to be filled out
 *
 *POST-CONDITIONS
 *
 *	NONE
 ***********************************************************/

void Fill(ostream& outputT, //OUT - output stream
          char fillChar,    //IN  - character to fill the line with
          int width)        //IN  - width of the line to be filled out
{

    outputT << setfill(fillChar) << setw(width) << fillChar;
    outputT << setfill(' ');
}


