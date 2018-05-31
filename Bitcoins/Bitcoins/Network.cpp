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

/*******************************************
***************mark_and_number_loops********
********************************************
*mark_and_number_loops tells the user the number of loops in a graph 
*and leaves all the nodes in the graph marked with a visited group mark.
*IMPORTANT : should call stop_search after calling this function if you want
*to have all the nodes left unmarked!
*INPUT:
*	1) void.
*
*OUTPUT:
*	an int with the number of loops in the graph.
*/
int Network::mark_and_number_loops() {
	std::vector<FullServiceNode*>::iterator it;
	int group_mark = 1;

	for (it = network->begin(); it != network->end(); ++it) {
		FullServiceNode* current_node = *it;
		if (!(current_node->is_marked_visited())) {
			current_node->mark_visited(group_mark);
			current_node->mark_connected_nodes();
			group_mark++;
		}
	}
	
	return group_mark;
}