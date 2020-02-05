#include "Parser.h"
#include "Graph.h"
#include <map>

int main() {
	std::string str = "a_star_pathfinding/random64_4_1485816605.dot";
	Parser* p = new Parser(str);
	Graph g = p->loadFile();

	std::cout << "---------------- ALL NEIGHBOURS ----------------" << std::endl;
	for (unsigned i = 0; i < g.getNodeList()->size(); ++i) {
		std::cout << "NODE " << g.getNodeList()->at(i).getId() << ": ";
		for (std::map<Node, double>::iterator iter(g.getNodeList()->at(i).getEdges()->begin());
			iter != g.getNodeList()->at(i).getEdges()->end();
			++iter) {
			std::cout << iter->first.getId() << " weight : " << iter->second << std::endl;
		}
		std::cout << std::endl;
	}

	delete p;

	return 0;
}