/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


string InstructionHeader(string message, int keyVal, string strName);

void PrintHeader(ostream& outputF, // OUT - class header to file
                 string asName,    // IN  - Assignment name
                 string programers,// IN  - Programmer(s) name
                 char asType,      // IN  - Type of project
        //      (lab or assignment)
                 int asNum);       // IN  - Project number

void Fill(ostream& outputT, //OUT - output stream
          char fillChar,    //IN  - character to fill the line with
          int width);        //IN  - width of the line to be filled out

#endif /* FUNCTIONS_H_ */
