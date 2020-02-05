#include "Graph.h"
#include <map>

Graph::Graph(){
	nodeList = new std::vector<Node>();
}

Graph::~Graph(){}

std::vector<Node>* Graph::getNodeList() {
	return nodeList;
}

std::vector<Node> Graph::searchPath(Node start, Node goal) {
	std::vector<Node> path = std::vector<Node>();
	std::map<Node, double> cost = std::map<Node, double>();

	path.push_back(start);
	cost[start] = 0;

	while (path.back().getId() != goal.getId()) {
		for (unsigned i = 0; i < path.back().getEdges()->size(); ++i) {
			double new_cost = cost[path.back()];
		}
	}
}