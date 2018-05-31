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
	bool is_fully_connected();
	void stop_search();
	//void search_for(callback, void * search_data);		callback function!!

};

