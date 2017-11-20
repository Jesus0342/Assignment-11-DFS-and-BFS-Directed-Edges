/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#include "MyHeader.h"

/*************************************************************************
 *  FUNCTION ProgramDesc
 * 		This function will output detailed program description to the
 * 		console.
 * _______________________________________________________________________
 * PRE-CONDITIONS:
 *
 * POST-CONDITIONS:
 * 		Returns -> Nothing. Only output to the console.
 ************************************************************************/
void ProgramDesc()
{
	cout << "This program utilizes a user defined directed Graph ADT in\n"
			"order to demonstrate a DFS and a BFS. The DFS will begin at\n"
			"Dallas and visit all other vertices in the graph by choosing\n"
			"the edge with the smallest mileage. After the search is perf-\n"
			"ormed, the discovery, back, forward, and cross edges will be\n"
			"displayed, as well as the total distance traveled on the dis-\n"
			"covery edges. Then, the BFS will be performed, also starting\n"
			"at Dallas, and the discovery, back, and cross edges will be\n"
			"printed, as well as the total distance traveled.\n\n";

}
