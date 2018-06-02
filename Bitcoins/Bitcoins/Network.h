#pragma once
#include "MinerNode.h"

class Network
{
public:

	Network(unsigned int num_miners, unsigned int num_full_s);
	~Network();

	std::vector<FullServiceNode*> * get_nodes();
private:
	/*******************************************
	*************member variables***************
	********************************************/
	std::vector<FullServiceNode*> *network;

	/*******************************************
	*********************methods****************
	********************************************/
	unsigned int mark_and_number_loops();
	void stop_search();
	Node * search_for_mark(int group_mark);

	void printf_network();
};

