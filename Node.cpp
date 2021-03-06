#include "Node.h"
#include <string>

// constructor
Node::Node(unsigned id, std::pair<int,int> coord): id(id), coordinates(coord){
	edges = new std::map<Node, double>();
}

// destructor
Node::~Node(){}

// operator overloading
bool Node::operator <(Node n2) const{
	return this->getId() < n2.getId();
}

// getters
unsigned Node::getId() const{
	return id;
}

std::pair<int, int> Node::getCoordinates() {
	return coordinates;
}

std::map<Node, double>* Node::getEdges() {
	return edges;
}


void Node::addEdge(Node neighbour, double weight) {
	edges->insert(std::pair<Node, double>(neighbour, weight));
}