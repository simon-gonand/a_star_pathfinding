#include "Parser.h"
#include "Node.h"
#include "Graph.h"

// constructor
Parser::Parser(std::string fileName): fileName(fileName){}

// destructor
Parser::~Parser(){}

Graph Parser::loadFile() {
	std::ifstream ifs(fileName);
	std::string line;
	Graph g = Graph();

	while (std::getline(ifs, line)) {
		// reading nodes
		int id, x, y; // node id + coordinate x and coordinate y

		int nread =
			sscanf(line.c_str(),
				"%d[fontsize=\"8\",pos=\"%d,%d\"];",
				&id, &x, &y);

		if (3 == nread) {
			Node n = Node(id, std::pair<int, int>(x, y));
			g.getNodeList()->push_back(n);
		}

		// reading edges
		else {
			int id2, w; // node id of the neighbour + weight of the edge

			nread = 
				sscanf(line.c_str(),
				"%d--%d [fontsize=\"8\",label=\"%d\"];",
				&id, &id2, &w);

			if (3 == nread) {
				Node n1 = g.getNodeList()->at(id);
				Node n2 = g.getNodeList()->at(id2);

				// add the neighbours
				n1.addEdge(n2, w);
				n2.addEdge(n1, w);
			}
		}
	}
	return g; // return the graph
}