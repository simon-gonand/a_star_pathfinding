#include "Graph.h"
#include <map>

// constructor
Graph::Graph(){
	nodeList = new std::vector<Node>();
}

// destructor
Graph::~Graph(){}

// getter
std::vector<Node>* Graph::getNodeList() {
	return nodeList;
}

// functions use for the pathfinding

int Graph::heuristicCalculation(Node n, Node goal) {
	return std::abs(n.getCoordinates().first - goal.getCoordinates().first) + std::abs(n.getCoordinates().second - goal.getCoordinates().second);
}

std::vector<Node> Graph::insertionSortPriority(std::vector<Node> vec, Node goal) {
	if (vec.size() == 1 || vec.empty()) return vec;
	for (unsigned i = 1; i < vec.size(); ++i) {
		int toCompare = heuristicCalculation(vec[i], goal); // heuristic calculation of the current node
		Node tmp = vec[i];
		int j = i;
		while (j > 0 && heuristicCalculation(vec[j - 1], goal) > toCompare) { // compare to all nodes that are before the current one
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = tmp;
	}
	return vec;
}

std::vector<Node> Graph::searchPath(Node start, Node goal) {
	std::map<Node, Node>* pathThrough = new std::map<Node, Node>(); // all nodes that the algorithm is passing through
	std::map<Node, double> cost = std::map<Node, double>(); // what is costing so far

	std::vector<Node> frontier; // Node to visiting next
	frontier.push_back(start);

	pathThrough->insert(std::pair<Node, Node>(start, start));
	cost.insert(std::pair<Node, double>(start, 0));

	while (!frontier.empty()) {
		Node current = frontier.at(0);
		frontier.erase(frontier.begin());

		if (current.getId() == goal.getId()) // final goal
			break;

		std::map<Node, double>::iterator iter (current.getEdges()->begin());

		while(iter != current.getEdges()->end()){ // checking all neighbours
			double new_cost = cost[current] + iter->second;

			if (cost.find(iter->first) == cost.end() || new_cost < cost[iter->first]) { // if node isn't visited yet or if the cost is lower
				cost.insert(std::pair<Node, double>(iter->first, new_cost));
				frontier.push_back(iter->first);

				if (pathThrough->find(iter->first) != pathThrough->end())
					pathThrough->at(iter->first) = current;
				else
					pathThrough->insert(std::pair<Node, Node>(iter->first, current));
			}
			++iter;
		}
		frontier = insertionSortPriority(frontier, goal); // sort to see which one is the priority node
	}
	std::vector<Node> path; // current path
	Node current = goal;

	// building the path starting from the goal
	while (current.getId() != start.getId()) {
		path.push_back(current);
		current = pathThrough->at(current);
	} 

	path.push_back(start);
	std::reverse(path.begin(), path.end()); // reverse the path to have it in the right way
	return path;
}