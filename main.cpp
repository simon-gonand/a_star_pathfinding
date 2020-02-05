#include "Parser.h"
#include "Graph.h"
#include <map>

int main() {
	std::string str = "a_star_pathfinding/random64_4_1485816605.dot";
	Parser* p = new Parser(str);
	Graph g = p->loadFile();

	std::vector<Node> path = g.searchPath(g.getNodeList()->at(0), g.getNodeList()->at(60));

	for (unsigned i = 0; i < path.size(); ++i)
		std::cout << "Pass through: " << path[i].getId() << std::endl;


	delete p;

	return 0;
}