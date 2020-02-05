#include "Graph.h"
#include <map>

Graph::Graph(){
	nodeList = new std::vector<Node>();
}

Graph::~Graph(){}

std::vector<Node>* Graph::getNodeList() {
	return nodeList;
}

int Graph::heuristicCalculation(Node n, Node goal) {
	return std::abs(n.getCoordinates().first - goal.getCoordinates().first) + std::abs(n.getCoordinates().second - goal.getCoordinates().second);
}

std::vector<Node> Graph::insertionSortPriority(std::vector<Node> vec, Node goal) {
	if (vec.size() == 1 || vec.empty()) return vec;
	for (unsigned i = 1; i < vec.size(); ++i) {
		int tmp = heuristicCalculation(vec[i], goal);
		int j = i;
		while (j > 0 && heuristicCalculation(vec[j - 1], goal) > tmp) {
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = vec[i];
	}
}

std::vector<Node> Graph::searchPath(Node start, Node goal) {
	std::vector<Node> path = std::vector<Node>();
	std::map<Node, double> cost = std::map<Node, double>();

	std::vector<Node> frontier;
	frontier.push_back(start);

	path.push_back(start);
	cost.insert(std::pair<Node, double>(start, 0));

	while (!frontier.empty()) {
		Node current = frontier.at(0);
		frontier.erase(frontier.begin());

		if (current.getId() == goal.getId())
			break;

		std::map<Node, double>::iterator iter (current.getEdges()->begin());

		while(iter != current.getEdges()->end()){
			double new_cost = cost[current] + iter->second;
			if (cost.find(iter->first) == cost.end()
				|| new_cost < cost[iter->first]) {
				cost.insert(std::pair<Node, double>(iter->first, new_cost));
				frontier.push_back(iter->first);
				path.push_back(current);
			}
			frontier = insertionSortPriority(frontier, goal);
			++iter;
		}
	}
	return path;
}