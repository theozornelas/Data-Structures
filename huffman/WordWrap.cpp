/*****************************************************
 *AUTHOR         :  The Oz
 *CLASS          :  CS 1B
 *SECTION        :  TTh:  8am - 11:50am
 *DUE DATE       :  3/19/15
 *****************************************************/

#include "Functions.h"

/***********************************************************
 *FUNCTION WordWrap
 *__________________________________________________________
 * This function formats the synopsis to be in a paragraph
 * instead of a long sentence. It formats it to be 75 spaces
 * per line.
 * _________________________________________________________
 *
 * PRE-CONDITIONS
 * 	synopsis  : the movie synopsis
 * 	outputT   : Output stream
 *
 * CONSTANTS
 * 	STRING_SIZE : Maximum lenght for the line
 *	LENGHT      : synopsis lenght
 *POST-CONDITIONS
 *
 * wrap :  wrapped paragraph
 *
 ***********************************************************/

void WordWrap(ostream& outputT, //OUT - Output stream
		      string synopsis) //IN   - synopsis of the movie
{

	const int STRING_SIZE = 75;

	int count;         //CALC - for loop lcv
	string outLineStr; //CALC - main line to be outputted
	string outWordStr; //CALC - temporary line
	string wrap;       //CALC - line to be outputted

	const int LENGTH = synopsis.length();

	//from 0 to dtring lenght
	for(count = 0; count < LENGTH; count ++)
	{

		//check char
		if(!isspace(synopsis[count]))
		{

			//add the char to the word
			outWordStr = outWordStr + synopsis[count];

		}
		else
		{
			//if the lenght is bugger than the max lenght
			if((outWordStr.length() + outLineStr.length()) >= STRING_SIZE)
			{
			//output line
			outputT << outLineStr << endl;
			//clear the line
			outLineStr.clear();

			}

		//add the word and a space
		outLineStr = outLineStr + outWordStr + ' ';

		outWordStr.clear();

		}

	}

	//PROCESSING - output what is left, and prevent the text from going
	//             out of bound (75 as max).
	wrap = outLineStr + outWordStr;

	//if the line is greater than the max
	if( wrap.length() > STRING_SIZE)
	{

		//output the line, then add what is left stored in outWordStr
		outputT << outLineStr << endl
				<< outWordStr;

	}
	else
	{
		//if is less tha 75, output the line.
		outputT << wrap;

	}

}
