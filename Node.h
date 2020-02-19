#ifndef Node_h
#define Node_h

#include <utility>
#include <map>

/*
* Class name: Node
* Node that is present in a Graph. It contains all info about this node in the graph
*/

class Node {
private:
	unsigned id; // ID of the node
	std::pair<int, int> coordinates; // coordinates of the node in the graph
	std::map<Node, double>* edges; // List of all neighbours with the weight of the edge
public:
	// constructor
	Node(unsigned id, std::pair<int,int> coord);

	// destructor
	~Node();

	// operator overloading
	bool operator < (Node n2) const; // important either a making a map is not possible

	// getters
	unsigned getId() const;
	std::pair<int, int> getCoordinates();
	std::map<Node, double>* getEdges();

	void addEdge(Node neighbour, double weight); // To add an neighbour
};

#endif
