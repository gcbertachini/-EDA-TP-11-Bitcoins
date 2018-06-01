#include "GraphicalNode.h"

GraphicalNode::GraphicalNode(FullServiceNode * node)
{
	selected = false;
}


GraphicalNode::~GraphicalNode(){
}


int GraphicalNode::get_colour() {
	return(this->is_miner() ? 1 : 0);
}

bool GraphicalNode::is_selected() {
	return this->selected
}