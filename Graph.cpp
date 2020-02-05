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
		int toCompare = heuristicCalculation(vec[i], goal);
		Node tmp = vec[i];
		int j = i;
		while (j > 0 && heuristicCalculation(vec[j - 1], goal) > toCompare) {
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = tmp;
	}
	return vec;
}

std::vector<Node> Graph::searchPath(Node start, Node goal) {
	std::map<Node, Node>* pathThrough = new std::map<Node, Node>();
	std::map<Node, double> cost = std::map<Node, double>();

	std::vector<Node> frontier;
	frontier.push_back(start);

	pathThrough->insert(std::pair<Node, Node>(start, start));
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
				if (pathThrough->find(iter->first) != pathThrough->end())
					pathThrough->at(iter->first) = current;
				else
					pathThrough->insert(std::pair<Node, Node>(iter->first, current));
			}
			frontier = insertionSortPriority(frontier, goal);
			++iter;
		}
	}
	std::vector<Node> path;
	Node current = goal;

	while (current.getId() != start.getId()) {
		path.push_back(current);
		current = pathThrough->at(current);
	}
	path.push_back(start);
	std::reverse(path.begin(), path.end());
	return path;
}