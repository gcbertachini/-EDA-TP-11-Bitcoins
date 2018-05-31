#pragma once
#include "MinerNode.h"

class Network
{
public:

	Network(unsigned int num_miners, unsigned int num_full_s);
	~Network();

private:
	/*******************************************
	*************member variables***************
	********************************************/
	std::vector<FullServiceNode*> *network;

	/*******************************************
	*********************methods****************
	********************************************/
	int mark_and_number_loops();
	void stop_search();
	//void search_for(callback, void * search_data);		callback function!!
};

