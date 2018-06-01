#pragma once
#include "MinerNode.h"
class GraphicalNode: public FullServiceNode
{
public:
	GraphicalNode(FullServiceNode * node);
	~GraphicalNode();
	int get_colour();
	bool is_selected();
private:
	bool selected;

};

