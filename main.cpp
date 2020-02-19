#include "Parser.h"
#include "Graph.h"
#include <map>

/*
* Main function
*/
int main() {
	Parser* p = new Parser("a_star_pathfinding/random64_4_1485816605.dot");
	Graph g = p->loadFile(); // Parse the dot file and create a graph with it

	delete p;

	std::vector<Node> path = g.searchPath(g.getNodeList()->at(0), g.getNodeList()->at(60)); // pathfinding function

	for (unsigned i = 0; i < path.size(); ++i)
		std::cout << "Pass through: " << path[i].getId() << std::endl; // Display the result

	return 0;
}