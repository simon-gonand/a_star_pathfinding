#ifndef Parser_h
#define Parser_h

#include <fstream>
#include <string>
#include <iostream>
#include "Graph.h"

/*
* Class name : Parser
* Reading a get the information of a file
*/

class Parser {
private:
	std::string fileName;
public:
	// constructor
	Parser(std::string fileName);

	// destructor
	~Parser();

	Graph loadFile(); // read the file and build a graph
};

#endif