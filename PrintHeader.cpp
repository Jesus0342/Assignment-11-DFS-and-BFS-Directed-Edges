/*************************************************************************
 * AUTHOR		: Frances Ohide, Sabrina Dang, Lee Evans
 * LAB #        : AS#10
 * CLASS		: CS1D
 * SECTION		: MW 3pm
 * DUE DATE		: 11/13/2017
 *************************************************************************/

#include "MyHeader.h"

/*************************************************************************
 *  FUNCTION PrintHeaderStream
 * 		This function will output the header, including the names of the
 * 		programmers, class and assignment information.
 * 		- returns: the class header as a string stream
 * _______________________________________________________________________
 * PRE-CONDITIONS:
 * 		PROGRAMMER  : predefined in main
 * 		CLASS		: predefined in main
 * 		SETION		: predefined in main
 * 		ASSIGN_NUM  : predefined in main
 * 		ASSIGN_TYPE : predefined in main
 * 		ASSIGN_NAME : predefined in main
 *
 * POST-CONDITIONS:
 * 		This function will return the class heading as a string
 ************************************************************************/
string PrintHeaderStream(const string PROGRAMMER,// IN - name of programmer/s
					     const string CLASS,	 // IN - class abbreviation
					     const string SECTION,	 // IN - class day/time
					     const string AS_NAME,   // IN - name of assign
					     const char   AS_TYPE,   // IN - assign or lab
					     const int    AS_NUM)	 // IN - assign or lab #
{
	ostringstream output;
	output << left;
	output << "******************************************************";
	output << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	output << "\n*  " << setw(14) << "CLASS"  << ": " << CLASS;
	output << "\n*  " << setw(14) << "SECTION"  << ": " << SECTION;
		if (toupper(AS_TYPE) == 'L')
		{
			output << "\n*  LAB #" << setw(9);
		}
		else
		{
			output << "\n*  ASSIGNMENT #" << setw(2);
		}
	output << AS_NUM << ": " << AS_NAME;
	output << "\n******************************************************\n";
	output << right;
	return output.str();
}
