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
	unsigned int node_amount = num_full_s + num_miners;
	network->reserve(node_amount);

	//add the MinerNodes and FullServiceNodes to the network.
	for (size_t i = 0; i < num_miners; i++) 
		network->push_back(new MinerNode());
	for (size_t i = 0; i < num_full_s; i++) 
		network->push_back(new FullServiceNode());

	//we have to start connecting the nodes!!!!

	std::vector<FullServiceNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) {
			FullServiceNode* connect_to;
			while ((!(*it)->is_fully_connected()) && (!(*it)->connect_to_node(connect_to)) ) { //tries to connect a not fully connected node to the randomly selected one
				unsigned int connect_to_index = rand() % node_amount;		
				connect_to = (*network)[connect_to_index];					//randomly selects a node from the network
			} 				
	}

	unsigned int loop_number = mark_and_number_loops();			//checks the number of loops on the network after the connection try.

	Node * new_head = search_for_mark(1);
	
	for (it = network->begin(); it != network->end(); ++it) 
		if ((*it)->is_marked_visited() != 1) 
			(*it)->connect_to_node(new_head);					//connects node from diffent loops to the new head!!

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
*	an unsigned int with the number of loops in the graph.
*/
unsigned int Network::mark_and_number_loops() {
	unsigned int group_mark = 1;

	std::vector<FullServiceNode*>::iterator it;

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

/*******************************************
***************search_for_mark**************
********************************************
*search_for_mark returns a Node that belongs to the network and has the given group_mark/ loop mark.
*It returns a node that is preferably not fully connected.
*If no node that has the given group_mark belongs to the network, then the function returns NULL
*INPUT:
*	1) group_mark : loop identifier for the loop in which the wanted node is.
*
*OUTPUT:
*	A Node pointer that contains a Node that has the selected group_mark.
*	NULL if no such pointer exists.
*/
Node * Network::search_for_mark(int group_mark) {

	Node * node_to_return = NULL;

	std::vector<FullServiceNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) 
		if ((*it)->is_marked_visited() == group_mark) {
			node_to_return = *it;
			if (!node_to_return->is_fully_connected())
				break;
		}

	return node_to_return;
}


