#include "Network.h"


/*******************************************
***************create_network***************
********************************************
*create_network
*INPUT:
*	1) num_miners : amount of miners in the network
*	2) num_full_s : amount of FullServiceNodes on the network.
*
*OUTPUT:
*	void.
*/
Network::Network(unsigned int num_miners, unsigned int num_full_s){

	network = new std::vector<FullServiceNode*>;
	network->reserve(num_full_s + num_miners);

	for (size_t i = 0; i < num_miners; i++) 
		network->push_back(new MinerNode());
	for (size_t i = 0; i < num_full_s; i++) 
		network->push_back(new FullServiceNode());

	//we have to start connecting the nodes!!!!
	
	//connect!!

	std::vector<FullServiceNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) {
		if ((it + 1) != network->end()) 
			(*it)->connect_to_node(*(it + 1));		//Connects the current node to the next node whenever it's possible to do so.
		if ((it + 2) != network->end()) 
			(*it)->connect_to_node(*(it + 2));		//Connects the current node to the next-next node whenever it's possible to do so.

	}
	
	stop_search();			//marks everything as unvisited!
}


Network::~Network(){
	delete network;
}

/*******************************************
***************is_fully_connected***********
********************************************
*is_fully_connected checks if every single node on the network is
*directly or indirectly connected to every other node on the network. 
*INPUT:
*	1) void.
*
*OUTPUT:
*	boolean that is true if every single node on the network is
*	directly or indirectly connected to every other node on the network. 
*	false if not.
*/
bool Network::is_fully_connected() {

	bool fully_connected = true;
	std::vector<FullServiceNode*>::iterator it;

	it = network->begin();						//first node of the network.
	int group_mark = (*it)->is_marked_visited();	//get the mark of the first node

	while (it != network->end()) {
		if (group_mark != ((*it)->is_marked_visited())) {		//compare the mark of the first node to every other node.
			fully_connected = false;							//if i find different marks, the network is not fully connected!
			break;
		}
		++it;
	}
	
	return fully_connected;
}

/*******************************************
***************stop_search******************
********************************************
*stop_search is called when a search involving nodes and marking
*on a network is over. It removes the visited marks for all nodes 
*on the network.
*INPUT:
*	1) void.
*
*OUTPUT:
*	void.
*/
void Network::stop_search() {
	std::vector<FullServiceNode*>::iterator it;
	for ( it = network->begin(); it != network->end(); ++it)
		(*it)->unmark_visited();
}


