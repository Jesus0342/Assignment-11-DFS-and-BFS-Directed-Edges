/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#include "MyHeader.h"

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
int main() {
	//Prints header of the lab
	cout << PrintHeaderStream(PROGRAMMER, CLASS, SECTION, AS_NAME, AS_TYPE,
					AS_NUM);

	//Prints program description
	ProgramDesc();

	Digraph digraph; // Graph object.

	cout << "Adding vertices to the graph...\n";

	// Initializes the graph by reading from Map.txt.
	digraph.initializeDigraph();

	cout << "\n****************\n"
			"* PART B - DFS *\n"
			"****************\n\n";

	// Vector of city names that will hold the cities visited during the DFS, in
	// the order they were visited.
	vector<string> dfs;

	cout << "\nPerforming a DFS starting at Dallas:\n";

	// Performs a DFS on the graph starting at Dallas and stores the total
	// distance traveled.
	int dfsDistance = digraph.DFS("Dallas", dfs);

	for (unsigned int i = 0; i < dfs.size(); i++) {
		cout << dfs.at(i) << endl;
	}

	cout << "\nTotal Distance Traveled: " << dfsDistance << endl;

	// Vectors containing the discovery and back edges of the graph.
	vector<string> dfsDiscoveryEdges = digraph.discoveryEdges(dfs);
	vector<string> dfsBackEdges = digraph.backEdges(dfs);
	vector<string> dfsForwardEdges = digraph.forwardEdges(dfs);

	cout << "\nPrinting DFS discovery edges:\n";
	for (unsigned int i = 0; i < dfsDiscoveryEdges.size(); i++) {
		cout << dfsDiscoveryEdges.at(i) << endl;
	}

	cout << "\nPrinting DFS back edges:\n";
	for (unsigned int i = 0; i < dfsBackEdges.size(); i++) {
		cout << dfsBackEdges.at(i) << endl;
	}

	cout << "\nPrinting DFS forward & cross edges:\n";
	for (unsigned int i = 0; i < dfsForwardEdges.size(); i++) {
		cout << dfsForwardEdges.at(i) << endl;
	}

	cout << "\n****************\n"
			"* PART B - BFS *\n"
			"****************\n\n";

	vector<string> bfs;

	cout << "Performing a BFS starting at Dallas: \n";
	int bfsDistance = digraph.BFS("Dallas", bfs);

	for (unsigned int i = 0; i < bfs.size(); i++) {
		cout << bfs.at(i) << endl;
	}

	cout << "\nTotal Distance Traveled: " << bfsDistance << endl;

	Graph<string, int> theG(12, DIRECTED_GRAPH); // 12 vertices
	theG.insert("Seattle", "San Francisco", 807);
	theG.insert("Seattle", "Denver", 1331);
	theG.insert("Chicago", "Seattle", 2097);
	theG.insert("Chicago", "Boston", 983);
	theG.insert("Denver", "San Francisco", 1267);
	theG.insert("Denver", "Chicago", 1003);
	theG.insert("San Francisco", "Los Angeles", 381);
	theG.insert("Los Angeles", "Denver", 1015);
	theG.insert("Kansas City", "Los Angeles", 1663);
	theG.insert("Kansas City", "Chicago", 533);
	theG.insert("Kansas City", "Denver", 599);
	theG.insert("Kansas City", "New York", 1260);
	theG.insert("Kansas City", "Atlanta", 864);
	theG.insert("Dallas", "Los Angeles", 1435);
	theG.insert("Dallas", "Kansas City", 496);
	theG.insert("Dallas", "Atlanta", 781);
	theG.insert("New York", "Chicago", 787);
	theG.insert("New York", "Atlanta", 888);
	theG.insert("Houston", "Dallas", 239);
	theG.insert("Houston", "Atlanta", 810);
	theG.insert("Miami", "Houston", 1187);
	theG.insert("Boston", "New York", 214);
	theG.insert("Atlanta", "Miami", 661);

	theG.BreadthFirstSearch("Dallas");

	theG.displayEdges(0);
	theG.displayEdges(1);
	theG.displayEdges(2);
	theG.displayEdges(3);
	theG.displayEdges(4);

	cout << "\n********************************\n"
			"* PART C - STRONGLY CONNECTED? *\n"
			"********************************\n\n";

	bool connection = theG.isStronglyConnected("Dallas");

	if (connection == true) {
		cout << "YES! The graph is strongly connected.";
	}

	return 0;
}

