#ifndef Node_h
#define Node_h

#include <utility>
#include <map>

class Node {
private:
	unsigned id;
	std::pair<int, int> coordinates;
	std::map<Node, double>* edges;
public:
	Node(unsigned id, std::pair<int,int> coord);
	~Node();
	unsigned getId() const;
	std::pair<int, int> getCoordinates();
	std::map<Node, double>* getEdges();
	void addEdge(Node neighbour, double weight);
};

#endif
