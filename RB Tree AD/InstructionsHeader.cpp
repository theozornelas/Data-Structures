/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/

#include "Functions.h"

//outputs a header for the execution that is about to happen
string InstructionHeader(string message, int keyVal, string strName)
{
    ostringstream out;
    Fill(out,'*',75);
    out << endl << message<< keyVal << " --> " << strName <<  endl;
    Fill(out,'*',75);
    out << endl;
    return out.str();
}
