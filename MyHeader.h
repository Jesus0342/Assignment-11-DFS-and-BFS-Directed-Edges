/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include "directedgraph.h"
#include "Digraph.h"
using namespace std;

// GLOBAL CONSTANTS
const string         PROGRAMMER	 =	"Frances Ohide & Jesus Sanchez";
const string         CLASS       = 	"CS1D";
const string         SECTION     =  "MW - 3pm";
const string         AS_NAME     = 	"DFS and BFS - Directed Edges";
const char	         AS_TYPE     = 	'A'; // L OR A
const unsigned short AS_NUM	     = 	 11 ; // lab num


// FUNCTION DECLARATIONS
/*************************************************************************
 *  FUNCTION PrintHeaderStream
 * 		This function will output the header, including the names of the
 * 		programmers, class and assignment information.
 * 		- returns: the class header as a string stream
 ************************************************************************/
string PrintHeaderStream(const string PROGRAMMER,// IN - name of programmer
					     const string CLASS,	 // IN - class abbreviation
					     const string SECTION,	 // IN - class day/time
					     const string AS_NAME,   // IN - name of assign
					     const char   AS_TYPE,   // IN - assign or lab
					     const int    AS_NUM);	 // IN - assign or lab #
void ProgramDesc();
#endif /* MYHEADER_H_ */
