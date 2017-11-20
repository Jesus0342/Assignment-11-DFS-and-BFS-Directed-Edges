/******************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 ******************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "heap.h"
#include "comparators.h"
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

// Enumeration types
enum myVertexEnum {
	UNVISITED_PLACE, VISITED_PLACE
};

enum EdgeEnum {
	UNVISITED, DISCOVERY_EDGE, FORWARD_EDGE, BACK_EDGE, CROSS_EDGE
};

enum GraphType {
	DIRECTED_GRAPH
};

/**************************************************************************
 * VERTEX CLASS
 **************************************************************************/
template<typename Type>
class myVertex {
public:
	myVertex();
	myVertex(Type setPlace, int setVIndex);
	~myVertex();

	//sets to see if the place is visited or not; sets the edge types.
	void setStatus(int setStatusStatus);

	//needed for directed graph ------
	void setArriveTime(int arrival);
	void setDepartTime(int departure);

	Type& operator*();

	/*************** ACCESSORS ***************/
	int getExploreStatus() const;
	int getVIndex() const;
	int getArriveTime() const;
	int getDepartTime() const;

private:
	Type placeInfo;
	int vIndex;
	myVertexEnum explorationStatus;
	int arrivalTime;
	int departureTime;
};

template<typename Type>
myVertex<Type>::myVertex() :
		placeInfo(Type()), vIndex(-1), explorationStatus(UNVISITED_PLACE), arrivalTime(
				0), departureTime(9999999) {

}
template<typename Type>
myVertex<Type>::myVertex(Type setPlace, int setVIndex) :
		placeInfo(setPlace), vIndex(setVIndex), explorationStatus(
				UNVISITED_PLACE), arrivalTime(0), departureTime(9999999) {

}

template<typename Type>
myVertex<Type>::~myVertex() {
}

template<typename Type>
Type& myVertex<Type>::operator*() {
	return placeInfo;
}

template<typename Type>
void myVertex<Type>::setStatus(int setStatusStatus) {
	// type cast into enumeration type
	explorationStatus = myVertexEnum(setStatusStatus);
}

template<typename Type>
void myVertex<Type>::setArriveTime(int arrival) {
	arrivalTime = arrival;
}

template<typename Type>
void myVertex<Type>::setDepartTime(int departure) {
	departureTime = departure;
}

template<typename Type>
int myVertex<Type>::getExploreStatus() const {
	//return 0 is place is unvisited, 1 if the place is visited
	switch (explorationStatus) {
	case UNVISITED_PLACE:
		return UNVISITED_PLACE;
		break;
	case VISITED_PLACE:
		return VISITED_PLACE;
		break;
	}
}

template<typename Type>
int myVertex<Type>::getVIndex() const {
	if (vIndex == -1) {
		cout << "No Index!";
	}

	return vIndex;
}

template<typename Type>
int myVertex<Type>::getArriveTime() const {
	return arrivalTime;
}
template<typename Type>
int myVertex<Type>::getDepartTime() const {
	return departureTime;
}

/**************************************************************************
 * EDGE2 CLASS - Modified name to be edge2 so it doesn't get confused with
 * Jesus' Digraph.h
 **************************************************************************/
template<typename Type, typename Distance>
class Edge2 {
public:
	Edge2(myVertex<Type>& setmyVertex1, myVertex<Type>& setmyVertex2,
			Distance setWeight);
	Edge2(const Edge2<Type, Distance>& otherEdge2);
	~Edge2();

	void setVertices(myVertex<Type>& setVertex1, myVertex<Type>& setVertex2);
	void resetEdges();
	void setStatus(int setStatusStatus);

	/******* Accessors *********/
	int getExploreStatus() const;
	myVertex<Type>* getmyVertex1() const;
	myVertex<Type>* getmyVertex2() const;
	myVertex<Type>* getOpposite(const myVertex<Type>& vertex) const;
	Distance getDistance() const;

private:
	myVertex<Type> *vertex1;
	myVertex<Type> *vertex2;
	Distance distance;
	EdgeEnum explorationStatus;

};

/******** EDGE2 CLASS DEFINITIONS ************/
template<typename Type, typename Distance>
Edge2<Type, Distance>::Edge2(myVertex<Type>& setmyVertex1,
		myVertex<Type>& setmyVertex2, Distance setWeight) :
		vertex1(&setmyVertex1), vertex2(&setmyVertex2), distance(setWeight), explorationStatus(
				UNVISITED)

{
}
template<typename Type, typename Distance>
Edge2<Type, Distance>::Edge2(const Edge2<Type, Distance>& otherEdge2) {
	*this = otherEdge2;
}

//destructor!
template<typename Type, typename Distance>
Edge2<Type, Distance>::~Edge2() {
	vertex1 = NULL;
	vertex2 = NULL;
}

//reset everything- used during INSERT new vertex(places)
template<typename Type, typename Distance>
void Edge2<Type, Distance>::resetEdges() {
	vertex1 = NULL;
	vertex2 = NULL;
	distance = Distance();
	explorationStatus = EdgeEnum(UNVISITED);
}

//used to see if strongly connected
template<typename Type, typename Distance>
void Edge2<Type, Distance>::setVertices(myVertex<Type>& setVertex1,
		myVertex<Type>& setVertex2) {
	vertex1 = &setVertex1;
	vertex2 = &setVertex2;
}

template<typename Type, typename Distance>
void Edge2<Type, Distance>::setStatus(int setStatusStatus) {
	explorationStatus = EdgeEnum(setStatusStatus);
}

template<typename Type, typename Distance>
int Edge2<Type, Distance>::getExploreStatus() const {
	// return appropriate exploration status and EDGES!!
	switch (explorationStatus) {
	case UNVISITED:
		return UNVISITED;
		break;
	case DISCOVERY_EDGE:
		return DISCOVERY_EDGE;
		break;
	case BACK_EDGE:
		return BACK_EDGE;
		break;
	case FORWARD_EDGE:
		return FORWARD_EDGE;
		break;
	case CROSS_EDGE:
		return CROSS_EDGE;
		break;
	}
}

template<typename Type, typename Distance>
myVertex<Type>* Edge2<Type, Distance>::getmyVertex1() const {
	return vertex1;
}
template<typename Type, typename Distance>
myVertex<Type>* Edge2<Type, Distance>::getmyVertex2() const {
	return vertex2;
}

template<typename Type, typename Distance>
myVertex<Type>* Edge2<Type, Distance>::getOpposite(
		const myVertex<Type>& vertex) const {
	// return opposite to vertex
	// checks if vertex1 points to same location as the given vertex
	if (vertex1->getVIndex() == vertex.getVIndex()) {
		return vertex2;
	} else if (vertex2->getVIndex() == vertex.getVIndex()) {
		return vertex1;
	} else {
		return NULL;
	}
}

template<typename Type, typename Distance>
Distance Edge2<Type, Distance>::getDistance() const {
	return distance;
}

/**************************************************************************
 *  GRAPH CLASS -- modified to be DIRECTED!!
 ***************************************************************************/
template<typename Type, typename Distance>
class Graph {
public:
	typedef Heap<TopLowestWeight<HeapItem<Edge2<Type, Distance>*> >,
			Edge2<Type, Distance>*> Heap;

	Graph(int numSize = 10, GraphType setGraphType = DIRECTED_GRAPH);
	~Graph();

	/****** MODIFIED FOR DIRECTED GRAPH!!!!!!! ******/
	void insert(Type placeInfo1, Type placeInfo2, Distance distance);
	void removemyVertex(myVertex<Type>& removeV);
	void removeEdge2(Type placeInfo1, Type placeInfo2, Distance distance);

	void incidentEdges(Type placeInfo, Heap& incidentEdge) const;
	vector<myVertex<Type>*>& incidentVertices(
			Edge2<Type, Distance>& edge) const;

	/******************************************************************
	 * 							BFS AND DFS
	 *****************************************************************/
	//DFS used in strongly connected
	void DepthFirstSearch(Type placeInfo, vector<myVertex<Type>*>& vertices);
	void DepthFirstSearch(myVertex<Type> &vertex,
			vector<myVertex<Type>*>& vertices);
	void BreadthFirstSearch(Type placeInfo); //just a wrapper
	void BreadthFirstSearch(myVertex<Type> &vertex);
	bool isAncestor(myVertex<Type> &vDescendant, myVertex<Type> &vAncestor);

	// used to see if strongly connected
	bool isStronglyConnected(Type beginmyVertex);
	void reverseEdges();

	/******************************************************************
	 * Displays!
	 *****************************************************************/
	void displayEdges(int explorationType) const;

private:
	//return data
	myVertex<Type>* returnVertex(Type placeInfo) const;
	Edge2<Type, Distance>* returnEdge(Type placeInfo1, Type placeInfo2,
			Distance distance) const;

	//used in insert method
	int availableIndex() const;

	//reset everything!!
	void resetAll();

	/******************************************************************
	 * Private Class Attributes
	 *****************************************************************/
	int vertexCount;
	int edgeCount;
	int size;
	GraphType graphType;
	int time;
	vector<vector<Edge2<Type, Distance>*> > edgeMatrix;
	vector<myVertex<Type>*> vertexList; //list of all vertices
	vector<Edge2<Type, Distance>*> edgeList; //list of all edges

};
template<typename Type, typename Distance>
Graph<Type, Distance>::Graph(int numSize, GraphType setGraphType) :
		edgeMatrix(numSize), vertexList(), edgeList(), vertexCount(0), edgeCount(
				0), size(numSize), graphType(setGraphType), time(0) {
	/* Create [size x size] matrix */
	for (int i = 0; i < size; i++) {
		(edgeMatrix[i]).resize(size);
	}

	/* initialize every location to NULL */
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			edgeMatrix[row][col] = NULL;
		}
	}

}
template<typename Type, typename Distance>
Graph<Type, Distance>::~Graph() {
}

template<typename Type, typename Distance>
void Graph<Type, Distance>::insert(Type placeInfo1,	// start place
		Type placeInfo2,	// end place
		Distance distance) {

	myVertex<Type> *vertex1;
	myVertex<Type> *vertex2;

	Edge2<Type, Distance> *newEdge2;
	Edge2<Type, Distance> *edgePtr;

	typename vector<myVertex<Type>*>::iterator vectorIt1;
	typename vector<myVertex<Type>*>::iterator vectorIt2;
	typename vector<Edge2<Type, Distance>*>::iterator edgeIt;
	int newIndex;

	newIndex = this->availableIndex();

	vertex1 = this->returnVertex(placeInfo1);
	vertex2 = this->returnVertex(placeInfo2);

	// if no such existing vertices, create both
	if (vertex1 == NULL && vertex2 == NULL) {
		if (vertexList.size() > (size - 2)) {
			cout << "FULL!";
		}

		vertex1 = new myVertex<Type>(placeInfo1, newIndex);

		vertexList.push_back(vertex1);
		++vertexCount;

		newIndex = this->availableIndex();

		vertex2 = new myVertex<Type>(placeInfo2, newIndex);
		vertexList.push_back(vertex2);

		//increment # of vertices
		++vertexCount;
	} else if (vertex1 == NULL) { // If vertex1 EMPTY
		if (vertexList.size() > (size - 1)) {
			cout << "FULL!";
		}
		vertex1 = new myVertex<Type>(placeInfo1, newIndex);
		vertexList.push_back(vertex1);
		++vertexCount;

	} else if (vertex2 == NULL) { //If vertex2 EMPTY
		if (vertexList.size() > (size - 1)) {
			cout << "FULL!";
		}
		vertex2 = new myVertex<Type>(placeInfo2, newIndex);

		vertexList.push_back(vertex2);
		++vertexCount;
	}

	newEdge2 = this->returnEdge(**vertex1, **vertex2, distance);

	if (newEdge2 == NULL) { //edge not found

		typename vector<Edge2<Type, Distance>*>::iterator edgeIt;

		if (edgeMatrix[vertex1->getVIndex()][vertex2->getVIndex()] != NULL) {
			// delete the edge
			edgePtr = edgeMatrix[vertex1->getVIndex()][vertex2->getVIndex()];
			edgeIt = edgeList.begin();
			while (edgeIt != edgeList.end() && *edgeIt != edgePtr) {
				edgeIt++;
			}
			if (edgeIt == edgeList.end()) {
				cout << "ERROR";
			} else {
				//remove from edgeList
				edgeList.erase(edgeIt);
				edgePtr->resetEdges();
				delete edgePtr;
				edgePtr = NULL;
			}
		}

		if (edgeMatrix[vertex2->getVIndex()][vertex1->getVIndex()] != NULL) {
			// delete the edge
			edgePtr = edgeMatrix[vertex2->getVIndex()][vertex1->getVIndex()];

			edgeIt = edgeList.begin();
			while (edgeIt != edgeList.end() && *edgeIt != edgePtr) {
				edgeIt++;
			}

			if (edgeIt == edgeList.end()) {
				cout << "ERROR";
			} else {

				//remove from edgeList
				edgeList.erase(edgeIt);
				edgePtr->resetEdges();

				delete edgePtr;
				edgePtr = NULL;
			}
		}
		/* create the edge */
		newEdge2 = new Edge2<Type, Distance>(*vertex1, *vertex2, distance);

		edgeList.push_back(newEdge2);
		edgeCount++;
	}

	if (vertexCount > size) {
		cout << "FULL!";
	}

	edgeMatrix[vertex1->getVIndex()][vertex2->getVIndex()] = newEdge2;

}

template<typename Type, typename Distance>
void Graph<Type, Distance>::BreadthFirstSearch(Type placeInfo) {
	myVertex<Type> *vertex;

	vertex = returnVertex(placeInfo);

	// reset all to unexplored
	resetAll();

	BreadthFirstSearch(*vertex);

}

template<typename Type, typename Distance>
void Graph<Type, Distance>::BreadthFirstSearch(myVertex<Type> &vertex) {
	Edge2<Type, Distance> *edgePtr = NULL;
	myVertex<Type> *oppositemyVertex = NULL;
	myVertex<Type> *beginmyVertex = NULL;
	bool typeOK = true;
	int size = 0;
	queue<myVertex<Type> *> queue;

	/* Set vertex VISITED */
	vertex.setStatus(VISITED_PLACE);

	/* Add vertex to Queue of vertices */
	queue.push(&vertex);

	while (!queue.empty()) {
		Heap listOfEdges; // sorted by lowest distance

		beginmyVertex = queue.front();
		queue.pop();

		/* Retrieve all possible edges */
		incidentEdges(**beginmyVertex, listOfEdges);

		/* compute size of this list */
		size = listOfEdges.getNumElements();

		for (int i = 0; i < size; i++) {
			edgePtr = listOfEdges.removeTop().getData();
			if (graphType == DIRECTED_GRAPH) {
				// beginmyVertex must be the starting vertex
				if (beginmyVertex != edgePtr->getmyVertex1()) {
					typeOK = false;
				}
			}
			if (edgePtr->getExploreStatus() == UNVISITED && typeOK) {
				oppositemyVertex = edgePtr->getOpposite(*beginmyVertex);
				if (oppositemyVertex->getExploreStatus() == UNVISITED_PLACE) {
					/* set edge status to a discovery edge */
					edgePtr->setStatus(DISCOVERY_EDGE);
					oppositemyVertex->setStatus(VISITED_PLACE);
					queue.push(oppositemyVertex);
				} else {
					if (isAncestor(*beginmyVertex, *oppositemyVertex)) {
						edgePtr->setStatus(BACK_EDGE);
					} else {
						edgePtr->setStatus(CROSS_EDGE);
					} // end else
				} // end else
			} // end if
		} // end for
	}// end while
}

template<typename Type, typename Distance>
bool Graph<Type, Distance>::isAncestor(myVertex<Type> &vDescendant,
		myVertex<Type> &vAncestor) {

	Heap *listOfEdges; // list of edges sorted by lowest distance
	Edge2<Type, Distance> *edgePtr;
	myVertex<Type> *vertexPtr;
	queue<myVertex<Type> *> queue;
	bool found = false;

	vertexPtr = &vAncestor;

	queue.push(vertexPtr);

	while (!queue.empty() && !found) {
		vertexPtr = queue.front();
		queue.pop();

		listOfEdges = new Heap;
		this->incidentEdges(**vertexPtr, *listOfEdges);

		while (listOfEdges->getNumElements() != 0 && !found) {
			edgePtr = listOfEdges->removeTop().getData();

			if (edgePtr != NULL) {
				if (edgePtr->getExploreStatus() == DISCOVERY_EDGE) {

					if (edgePtr->getOpposite(*vertexPtr) == &vDescendant) {
						found = true;
					} else {
						queue.push(edgePtr->getOpposite(*vertexPtr));
					}
				}
			} else {
				cout << "OMG ERROR!\n";
			}
		}

		vertexPtr = (edgePtr->getOpposite(*vertexPtr));

		delete listOfEdges; //delete!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	if (found) {
		return true;
	} else {
		return false;
	}
}

template<typename Type, typename Distance>
void Graph<Type, Distance>::incidentEdges(Type placeInfo,
		Heap& incidentEdge2List) const {
	Edge2<Type, Distance> * edgePtr = NULL;
	myVertex<Type> *vertexPtr = NULL;

	/* Find the vertex from the given vertex data */
	vertexPtr = this->returnVertex(placeInfo);

	if (vertexPtr != NULL) {
		int index = 0;
		//point edge to the available edge
		edgePtr = edgeMatrix[vertexPtr->getVIndex()][index];

		while (index < size) {
			//connect edge to vertex if it's not NULL!
			if (edgePtr != NULL) {
				incidentEdge2List.insert(edgePtr);
			}
			index++;
			edgePtr = edgeMatrix[vertexPtr->getVIndex()][index];
		}
	} else {
		cout << "NOT FOUND!";
	}
}

/**** DISPLAY EDGES!!! *****
 * 0 - UNVISITED EDGE
 * 1 - DISCOVERED EDGE
 * 2 - FORWARD EDGE
 * 3 - BACK EDGE
 * 4 - CROSS EDGE
 **************************/
template<typename Type, typename Distance>
void Graph<Type, Distance>::displayEdges(int explorationType) const {
	cout << endl;

	string outputEdge;

	switch (explorationType) {
	case UNVISITED:
		outputEdge = "UNEXPLORED EDGE";
		break;
	case DISCOVERY_EDGE:
		outputEdge = "DISCOVERY EDGE";
		break;
	case BACK_EDGE:
		outputEdge = "BACK EDGE";
		break;
	case FORWARD_EDGE:
		outputEdge = "FORWARD EDGE";
		break;
	case CROSS_EDGE:
		outputEdge = "CROSS EDGE";
		break;
	default:
		cout << "MISSING EDGE!!!\n";
		return;
		break;
	}

	cout << outputEdge << "S: " << endl;

	typename vector<Edge2<Type, Distance>*>::const_iterator edgeIt;
	bool atLeast1 = false;

	Distance totalDist = 0;
	if (edgeList.empty()) {
		cout << "N/A\n";
	} else {
		for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt) {
			if ((*edgeIt)->getExploreStatus() == explorationType) {
				cout << "(" << **((*edgeIt)->getmyVertex1()) << ", "
						<< **((*edgeIt)->getmyVertex2()) << ")" << endl;

				totalDist += (*edgeIt)->getDistance();
				atLeast1 = true;

			}
		}

		if (!atLeast1) {
			cout << "NONE!\n";
		}

		cout << "TOTAL DISTANCE: " << totalDist << endl;
	}
}
template<typename Type, typename Distance>
myVertex<Type>* Graph<Type, Distance>::returnVertex(Type placeInfo) const {
	typename vector<myVertex<Type>*>::const_iterator vertexIt;

	/* Check if vertex exists*/
	vertexIt = vertexList.begin();
	while (vertexIt != vertexList.end()) {
		if (***vertexIt == placeInfo) {
			return *vertexIt;
		} else {
			++vertexIt;
		}
	}
	return NULL;
}

template<typename Type, typename Distance>
Edge2<Type, Distance>* Graph<Type, Distance>::returnEdge(Type placeInfo1,
		Type placeInfo2, Distance distance) const {
	typename vector<Edge2<Type, Distance>*>::const_iterator edgeIt;

	myVertex<Type> *v1;
	myVertex<Type> *v2;

	/* Check if vertex exists*/
	edgeIt = edgeList.begin();

	while (edgeIt != edgeList.end()) {
		v1 = (*edgeIt)->getmyVertex1();
		v2 = (*edgeIt)->getmyVertex2();

		// compare to see if edge has same vertex values and distance
		if (**v1 == placeInfo1 && **v2 == placeInfo2
				&& (*edgeIt)->getDistance() == distance) {
			return *edgeIt;
		} else {
			++edgeIt;
		}
	}
	return NULL;
}

//Returns the first available index that may represent a vertex
template<typename Type, typename Distance>
int Graph<Type, Distance>::availableIndex() const {
	int index = 0;
	bool indexFound = false;
	bool indexExists = false;
	typename vector<myVertex<Type>*>::const_iterator vertexIt;

	while (index < size && !indexFound) {
		vertexIt = vertexList.begin();

		//find smallest index
		while (vertexIt != vertexList.end() && !indexExists) {
			if (index == (*vertexIt)->getVIndex()) {
				indexExists = true;
			} else {
				vertexIt++;
			}
		}

		if (!indexExists) {
			indexFound = true;
		} else {
			indexExists = false;
			index++;
		}
	}
	return index;
}

template<typename Type, typename Distance>
void Graph<Type, Distance>::resetAll() {
	// reset statuses! (is that a word?)
	typename vector<myVertex<Type>*>::const_iterator vertexIt;

	if (!vertexList.empty()) {
		for (vertexIt = vertexList.begin(); vertexIt != vertexList.end();
				++vertexIt) {
			(*vertexIt)->setStatus(UNVISITED_PLACE);
			(*vertexIt)->setArriveTime(0);
			(*vertexIt)->setDepartTime(9999999);

		}
	}

	/* RESET EDGE STATUSES */
	typename vector<Edge2<Type, Distance>*>::const_iterator edgeIt;

	if (!edgeList.empty()) {
		for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt) {
			(*edgeIt)->setStatus(UNVISITED);
		}
	}

}

template<typename Type, typename Distance>
bool Graph<Type, Distance>::isStronglyConnected(Type beginVertex) {
	// MUST REVERSE EDGES
	// EXPECTED OUTPUT = TRUE!!
	// Check if all vertices are accessed by DFS for a regular and
	// reversed graph (all edges reversed)
	vector<myVertex<Type>*> dfsVertexList;
	vector<myVertex<Type>*> dfsVertexListReversedGraph;

	DepthFirstSearch(beginVertex, dfsVertexList);
	this->reverseEdges();
	DepthFirstSearch(beginVertex, dfsVertexListReversedGraph);

	cout << "Reversing the edges and performing a BFS...\n\n";

	// set back to default
	this->reverseEdges();

	// see if they are equal- if Yes, then the graph is STRONGLY CONNECTED.
	// if no, it's wrong! SHOULD BE A YES!!!!!!!!!!
	if (dfsVertexList.size() == this->vertexList.size()
			&& dfsVertexListReversedGraph.size() == this->vertexList.size()) {
		return true;
	} else {
		return false;
	}
}

template<typename Type, typename Distance>
void Graph<Type, Distance>::reverseEdges() {
	//Iterates through vertex and reverse it
	//Is it worth it, let me work it
	//I put my thing down, flip it and reverse it
	//by Missy Elliot HAHAHA

	typename vector<Edge2<Type, Distance>*>::const_iterator edgeIt;
	myVertex<Type> *v1;
	myVertex<Type> *v2;

	if (edgeList.empty()) {
		cout << "CAN'T REVERSE! WHAT HAPPENED??? \n";
	} else {
		for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt) {
			v1 = (*edgeIt)->getmyVertex1();
			v2 = (*edgeIt)->getmyVertex2();

			(*edgeIt)->setVertices(*v2, *v1);
		}
	}

	vector<vector<Edge2<Type, Distance>*> > old;

	old = edgeMatrix;

	for (int col = 0; col < size; col++) {
		for (int row = 0; row < size; row++) {
			edgeMatrix[col][row] = old[row][col];
		}
	}
}

template<typename Type, typename Distance>
void Graph<Type, Distance>::DepthFirstSearch(Type placeInfo,
		vector<myVertex<Type>*>& vertices) {
	myVertex<Type> *vertex;

	vertex = returnVertex(placeInfo);

	// reset all
	resetAll();

	DepthFirstSearch(*vertex, vertices);

}

/**************************************************************************
 *  A recursive for a DFS - USED IN - strongly connected -.
 **************************************************************************/
template<typename Type, typename Distance>
void Graph<Type, Distance>::DepthFirstSearch(myVertex<Type> &vertex,
		vector<myVertex<Type>*>& vertices) {
	Heap listOfEdges; // list of edges sorted by lowest distance
	Edge2<Type, Distance> *edgePtr = NULL;
	myVertex<Type> *oppositeVertex = NULL;
	bool typeOK = true;
	int size = 0;

	if (vertex.getExploreStatus() == UNVISITED_PLACE) {
		vertices.push_back(&vertex);
	}
	// need to use arrival/departure times for directed graph, just cuz.
	if (graphType == DIRECTED_GRAPH) {
		time++;
		vertex.setArriveTime(time);
	}

	/* Set vertex VISITED */
	vertex.setStatus(VISITED_PLACE);

	/* NEEDS THIS FOR directed graph */
	incidentEdges(*vertex, listOfEdges);


	//see new size
	size = listOfEdges.getNumElements();

	/* iterate throughout list -- by removing the front */
	for (int i = 0; i < size; i++) {

		/* remove top from list and have edgePtr point to the item */
		edgePtr = listOfEdges.removeTop().getData();

		if (graphType == DIRECTED_GRAPH) {
			if (&vertex != edgePtr->getmyVertex1()) {
				typeOK = false;
			}
		}

		if (edgePtr->getExploreStatus() == UNVISITED && typeOK) {
			oppositeVertex = edgePtr->getOpposite(vertex);
			if (oppositeVertex->getExploreStatus() == UNVISITED_PLACE) {
				//discovery edge
				edgePtr->setStatus(DISCOVERY_EDGE);
				DepthFirstSearch(*oppositeVertex, vertices);
			} else //back edge
			{
				if (vertex.getArriveTime() < oppositeVertex->getArriveTime()
						&& vertex.getDepartTime()
								> oppositeVertex->getDepartTime()) {
					edgePtr->setStatus(FORWARD_EDGE);
				} else if (vertex.getArriveTime()
						> oppositeVertex->getArriveTime()
						&& vertex.getDepartTime()
								== oppositeVertex->getDepartTime()) {
					edgePtr->setStatus(BACK_EDGE);
				} else {
					edgePtr->setStatus(CROSS_EDGE);
				}
			}
		}
	}
	if (graphType == DIRECTED_GRAPH) {
		time++;
		vertex.setDepartTime(time);
	}
}

#endif
