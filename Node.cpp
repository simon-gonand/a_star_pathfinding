#include "Node.h"

Node::Node(unsigned id, std::pair<int,int> coord): id(id), coordinates(coord){
	edges = new std::map<Node, double>();
}

Node::~Node(){}

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
	edges->at(neighbour) = weight;
}