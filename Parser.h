#ifndef Parser_h
#define Parser_h

#include <fstream>
#include <string>
#include <iostream>
#include "Graph.h"

class Parser {
private:
	std::string fileName;
public:
	Parser(std::string fileName);
	~Parser();
	Graph loadFile();
};

#endif