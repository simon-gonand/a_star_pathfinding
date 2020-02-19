#ifndef Graph_h
#define Graph_h

#include <vector>
#include "Node.h"

/*
* Class name: Graph
* Graph composed of Nodes. It contains the pathfinidng funcction.
*/
class Graph {
private:
	std::vector<Node>* nodeList; // List of all nodes in the graph
	int heuristicCalculation(Node n, Node goal); // heuristic calculation use in the pathfinding function to know which is the pritority node
	std::vector<Node> insertionSortPriority(std::vector<Node> vec, Node goal); // sorting algorithm to know which is the priority node by using the heuristic calculation

public:
	// constructor
	Graph(); 

	// destructor
	~Graph();

	// getter
	std::vector<Node>* getNodeList();

	//pathfinding function
	std::vector<Node> searchPath(Node start, Node goal);
};

#endif
