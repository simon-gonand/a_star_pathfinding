#include "Parser.h"
#include "Node.h"
#include "Graph.h"

Parser::Parser(std::string fileName): fileName(fileName){}

Parser::~Parser(){}

Graph Parser::loadFile() {
	std::ifstream ifs(fileName);
	std::string line;
	Graph g = Graph();

	while (std::getline(ifs, line)) {
		int id, x, y;
		int nread =
			sscanf(line.c_str(),
				"%d[fontsize=\"8\",pos=\"%d,%d\"];",
				&id, &x, &y);
		if (3 == nread) {
			Node n = Node(id, std::pair<int, int>(x, y));
			g.getNodeList()->push_back(n);
		}
		else {
			int id2, w;
			nread = 
				sscanf(line.c_str(),
				"%d--%d [fontsize=\"8\",label=\"%d\"];",
				&id, &id2, &w);
			if (3 == nread) {
				Node n1 = g.getNodeList()->at(id);
				Node n2 = g.getNodeList()->at(id2);
				n1.addEdge(n2, w);
				n2.addEdge(n1, w);
			}
		}
	}
	return g;
}