#include <iostream>
#include <stdio.h>
#include<io.h>
#include <vector>

#include "general.h"
#include "Network.h"



std::vector<FullServiceNode*> * create_network(unsigned int num_miners, unsigned int num_full_s);

int main(int argc, char *argv[]) {

	unsigned int num_miners = 0, num_full_s =0 ;			//get the values from command line!! (parser!!)
	//call to parser 
	std::vector<FullServiceNode*> *network = create_network(num_miners, num_full_s);	//if any other stuff should be added to network, 
																						//we should stop using a vector to represent it and 
																						//start using a class!!
	

}


/*******************************************
***************create_network***************
********************************************
*creates and returns a data structures containing FullServiceNodes.
*This data structure represents the whole EDAcoin network.
*if the data structure is ordered, then the first num_miners
*amount of FullServiceNodes will be miners and the rest will be 
*FullServiceNodes
*
*INPUT:
*	1) num_miners : amount of miners in the network
*	2) num_full_s : amount of FullServiceNodes on the network.
*
*OUTPUT:
*	a pointer to the data structure that represents the network
*
*/
std::vector<FullServiceNode*> * create_network(unsigned int num_miners, unsigned int num_full_s) {

	std::vector<FullServiceNode*> *network = new std::vector<FullServiceNode*>;
	network->reserve(num_full_s + num_miners);
	for (size_t i = 0; i < num_miners; i++) {
		MinerNode * miner = new MinerNode();
		network->push_back(miner);
	}
	for (size_t i = 0; i < num_full_s; i++) {
		FullServiceNode * full_s = new FullServiceNode();
		network->push_back(full_s);
	}
	//we have to start connecting the nodes!!!!
	return network;
}