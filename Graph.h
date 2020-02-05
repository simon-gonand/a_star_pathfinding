#ifndef Graph_h
#define Graph_h

#include <vector>
#include "Node.h"

class Graph {
private:
	std::vector<Node>* nodeList;

public:
	Graph();
	~Graph();
	std::vector<Node>* getNodeList();
	std::vector<Node> searchPath(Node start, Node goal);
};

#endif
