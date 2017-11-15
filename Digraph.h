#ifndef DIDigraph_H_
#define DIDigraph_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struct representing an edge in the Digraph.
struct Edge
{
	string u; // Starting city.
	string v; // Ending city.
	bool discoveryEdge; // Whether or not edge is a discovery edge.
	bool backEdge; // Whether or not an edge is a back edge.
	bool forwardEdge; // Whether or not an edge is a forward edge.
	bool crossEdge; // Whether or not an edge is a cross edge.
	int weight; // Distance between the cities.

	// Edge object constructor.
	Edge()
	{
		u = "";
		v = "";
		discoveryEdge = false;
		backEdge = false;
		forwardEdge = false;
		crossEdge = false;
		weight = 0;
	}
};

// Struct representing a vertex in the Digraph.
struct Vertex
{
	string city; // Name of the city in the vertex.
	bool visited; // Whether or not the vertex has already been visited.
	vector<Edge> edgeList; // List of incident edges.

	// Vertex object constructor.
	Vertex()
	{
		city = "";
		visited = false;
	}
};

// Digraph class that uses an adjacency list to store edges.
class Digraph
{
public:
	Digraph();
	~Digraph();

	// Returns true if the Digraph is empty, else returns false.
	bool empty();

	// Returns the number of vertices in the Digraph.
	int size();

	// Reads the edges from a text file and adds them to the Digraph.
	// POST-CONDITION: The Digraph will be filled with the values in the text file.
	void initializeDigraph();

	// Inserts a vertex to the Digraph with the specified city name.
	// PRE-CONDITIONS:
	// city - City name of new vertex must be defined.
	// POST-CONDITION: A new vertex is added to the Digraph.
	void insertVertex(string city);

	// Returns the Digraph index of the specified city.
	// PRE-CONDITIONS:
	// city - Name of city to be searched for must be defined.
	unsigned int findVertex(string city);

	// Adds a new edge to the Digraph and a new vertex if a vertex with value "u"
	// does not yet exist.
	// PRE-CONDITIONS:
	// u - Starting city must be defined.
	// v - Ending city must be defined.
	// weight - Distance between the cities must be defined.
	// POST-CONDITION: A new edge is added to the edge list of vertex "u".
	void insertEdge(string u, string v, int weight);

	// Returns a list of the vertices in the Digraph.
	vector<string> vertices();

	// Returns a list of the edges in the Digraph.
	vector<string> edges();

	// Performs a depth-first search on the Digraph starting at the indicated city
	// using recursion.
	// PRE-CONDITIONS:
	// startingCity - City where the DFS will begin must be defined.
	// dfs - Vector of city names in the order they were visited during DFS does
	//		 not have to be defined.
	// POST-CONDITION: The list of cities visited in the DFS order is returned.
	int DFS(string startingCity, vector<string> &dfs);

	// Returns a list of the discovery edges created during the DFS.
	// PRE-CONDITIONS:
	// dfs - Vector of city names in the order they were visited during DFS must
	// 		 be defined.
	vector<string> discoveryEdgesDFS(vector<string> &dfs);

	// Returns a list of the back edges created by the DFS.
	// PRE-CONDITIONS:
	// dfs - Vector of city names in the order they were visited during DFS must
	// 		 be defined.
	vector<string> backEdgesDFS(vector<string> &dfs);

	vector<string> forwardEdgesDFS(vector<string> &dfs);

	// Performs a recursive breadth-first search on the Digraph starting at the
	// indicated city.
	// PRE-CONDITIONS:
	// startingCity - City where the BFS will begin must be defined.
	// bfs - Vector of city names in the order they were visited during DFS does
	//		 not have to be defined.
	// POST-CONDITION: The bfs vector is modified to include the city names in BFS order.
	int BFS(string startingCity, vector<string> &bfs);

private:
	//
	void markBackEdges(int currVertex, vector<string> &dfs);

	void markForwardEdges(vector<string> &dfs);

	// Finds the closest vertex to the current vertex and returns its Digraph index.
	// PRE-CONDITIONS:
	// currVertex - Index of the current vertex must be defined.
	// dfs - Vector of cities visited during DFS must be defined.
	int smallestEdgeDFS(int currVertex, vector<string> &dfs);

	int smallestBackEdge(int currVertex);

	// Returns the number of vertices that have been visited.
	unsigned int verticesVisited();

	// Returns the number of edges discovered from the specified vertex.
	// PRE-CONDITIONS:
	// currVertex - Digraph index of the current vertex must be defined.
	unsigned int edgesDiscovered(int currVertex);

	// Deletes edge pairs that have the same u & v.
	// If (u, v) already exists, all (v, u) edge pairs will be deleted.
	void deleteDuplicates(vector<Edge> &edgeList);

	vector<Vertex> digraph; // Vector of vertices used to represent a Digraph.

	int dfsDistance; // Distance traveled during DFS.

	// When called by BFS(), carries out the recursive breadth-first search,
	// continuing from each of the cities from previousLevel
	// PRE-CONDITIONS:
	// bfs - Vector of city names in the order they were visited during DFS does
	//		 not have to be defined.
	// previousLevel: the Digraph positions of all the cities visited in the previous level
	// POST-CONDITION: The bfs vector is modified to include the city names in BFS order.
	int BFSRecur(vector<string> &bfs, vector<int> previousLevel);

	// Returns the city name of the vertex in an edge that is not startingCity
	// PRE-CONDITIONS:
	// currEdge - Edge in question that contains startingCity and the city to be found
	// startingCity - city name of the vertex opposite of the city to be found
	string otherVertex(Edge currEdge, string startingCity);

    // Returns the distance between two vertices
	// PRE-CONDITIONS:
	// v1, v2 - the vertices to find the distance between
	int distance(Vertex * v1, Vertex * v2);
};

#endif
