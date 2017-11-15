/******************************************************************************
 * AUTHORS        : Jesus Sanchez &
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#include "Digraph.h"

/******************************************************************************
 * DFS & BFS DIRECTED EDGES
 * ----------------------------------------------------------------------------
 * This program utilizes a user defined directed Graph ADT in order to
 * demonstrate a DFS and a BFS. The DFS will begin at Dallas and visit all other
 * vertices in the graph by choosing the edge with the smallest mileage.
 * After the search is performed, the discovery, back, forward, and cross edges
 * will be displayed, as well as the total distance traveled on the discovery
 * edges. Then, the BFS will be performed, also starting at Dallas, and the
 * discovery, back, and cross edges will be printed, as well as the total
 * distance traveled.
 * ----------------------------------------------------------------------------
 * INPUT:
 *    <There is no input.>
 *
 * OUTPUT:
 *    DFS - Discovery Edges, Back Edges, Forward Edges, Cross Edges, and Total
 *    		Distance Traveled
 *    BFS - Discovery Edges, Back Edges, Cross Edges, and Total Distance Traveled
 *
 *****************************************************************************/
int main()
{
	cout << "***************************************************************\n"
		 << "* NAME           : Jesus Sanchez &\n"
		 << "* ASSIGNMENT #11 : DFS & BFS Directed Edges\n"
		 << "* CLASS          : CS1D - MW: 3:00pm\n"
		 << "* DUE DATE       : 11/20/2017\n*\n"
		 << "* DESCRIPTION: This program will demonstrate a DFS and BFS using\n"
		 << "* a Graph class with directed edges. After the DFS, the forward,\n"
		 << "* discovery, back and cross edges will be printed, and the back,\n"
		 << "* discovery, and cross edges will be printed after the BFS.\n"
		 <<	"****************************************************************\n\n";

	Digraph digraph; // Graph object.

	cout << "Adding vertices to the graph...\n";

	// Initializes the graph by reading from Map.txt.
	digraph.initializeDigraph();

	cout << "\n**********\n"
			"* PART A *\n"
			"**********\n";

	// Vector of city names that will hold the cities visited during the DFS, in
	// the order they were visited.
	vector<string> dfs;

	cout << "\nPerforming a DFS starting at Dallas:\n";

	// Performs a DFS on the graph starting at Dallas and stores the total
	// distance traveled.
	int dfsDistance = digraph.DFS("Dallas", dfs);

	for(unsigned int i = 0; i < dfs.size(); i++)
	{
		cout << dfs.at(i) << endl;
	}

//	cout << "\nTotal Distance Traveled: " << dfsDistance << endl;
//
	// Vectors containing the discovery and back edges of the graph.
	vector<string> dfsDiscoveryEdges = digraph.discoveryEdgesDFS(dfs);
	vector<string> dfsBackEdges = digraph.backEdgesDFS(dfs);
	vector<string> dfsForwardEdges = digraph.forwardEdgesDFS(dfs);

	cout << "\nPrinting DFS discovery edges:\n";
	for(unsigned int i = 0; i < dfsDiscoveryEdges.size(); i++)
	{
		cout << dfsDiscoveryEdges.at(i) << endl;
	}

	cout << "\nPrinting DFS back edges:\n";
	for(unsigned int i = 0; i < dfsBackEdges.size(); i++)
	{
		cout << dfsBackEdges.at(i) << endl;
	}

	cout << "\nPrinting DFS forward & cross edges:\n";
	for(unsigned int i = 0; i < dfsForwardEdges.size(); i++)
	{
		cout << dfsForwardEdges.at(i) << endl;
	}

//	cout << "\n**********\n"
//			"* PART B *\n"
//			"**********\n\n";
//
//	vector<string> bfs;
//
//	cout << "Performing a BFS starting at Dallas: \n";
//	int bfsDistance = digraph.BFS("Dallas",bfs);
//
//	for(unsigned int i = 0; i < bfs.size(); i++)
//	{
//		cout << bfs.at(i) << endl;
//	}
//
//	cout << "\nTotal Distance Traveled: " << bfsDistance << endl;
//
//	cout << "\nPrinting BFS discovery edges: \n";
//	vector<string> bfsDiscoveryEdges = digraph.getDiscoveryEdges(bfs);
//	for(unsigned int i = 0; i < bfsDiscoveryEdges.size(); i++)
//	{
//		cout << bfsDiscoveryEdges.at(i) << endl;
//	}
//
//	cout << "\nPrinting BFS cross edges: \n";
//	vector<string> bfsCrossEdges = digraph.getBackEdges(bfs);
//	for(unsigned int i = 0; i < bfsCrossEdges.size(); i++)
//	{
//		cout << bfsCrossEdges.at(i) << endl;
//	}

	return 0;
}
