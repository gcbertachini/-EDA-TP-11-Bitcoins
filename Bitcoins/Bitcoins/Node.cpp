#include "Node.h"
#include <algorithm>

#define NOT_VISITED 0		//logical false!! always!

Node::Node()
{
	mark = NOT_VISITED;
	name = count;
	count++;
}

Node::~Node()
{
}

/*******************************************
***************connect_to_node**************
********************************************
*connect_to_node connects the node to a given node bidireccionally.
*INPUT:
*	1) node : node to be connected to.
*
*OUTPUT:
*	a boolean that is true if the connection was made.
*	false if not.
*
*/
bool Node::connect_to_node(Node * node) {

	bool connection_made = false;
	// https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
	//cant connect to the same node in this type of graph! cant connect if the node is already connected!
	if (!(std::find(connections.begin(), connections.end(), node) != connections.end()) && (node != this) ){		
		connections.push_back(node);
		node->connect_to_node(this);
		connection_made = true;
	}	
	return connection_made;
}
/*******************************************
***************is_fully_connected***********
********************************************
*is_fully_connected tells if the node has 2 or more connections.
*
*INPUT:
*	1) void
*
*OUTPUT:
*	a boolean that is true if all possible connections were made for this node.
*	false if not.
*
*/
bool Node::is_fully_connected() {
	return(connections.size() >= 2);
}


/*******************************************
************is_marked_visited****************
********************************************
*is_marked_visited tells if the node has been marked as visited
*and tells its group identifier.
*the function returns logical false (0)
*if the node has not been marked as visited.
*
*INPUT:
*	1) void
*
*OUTPUT:
*	an int that represents the group mark.
*	logical false (0) if not marked.
*	!=0 if marked
*/
int Node::is_marked_visited() {
	return mark;
}

/*******************************************
*******************unmark_visited***********
********************************************
*unmark_visited removes the visited mark from the node.
*INPUT:
*	1) void
*
*OUTPUT:
*	void.
*/
void Node::unmark_visited() {
	mark = NOT_VISITED;
}

/*******************************************
*****************mark_visited***************
********************************************
*mark_visited marks the node as visited with the group mark identifier.
*this mark lets the user know the unconnected regions of a network,
*as different regions will have different marks.
*INPUT:
*	1) group : group marked
*
*OUTPUT:
*	void.
*/
void Node::mark_visited(int group) {
	mark = group;
}

/*******************************************
*****************mark_connected_nodes***************
********************************************
*mark_connected_nodes marks recursively every single node this node has direct 
*and indirect access to.
*INPUT:
*	1) void.
*
*OUTPUT:
*	void.
*/
void Node::mark_connected_nodes() {
	std::vector<Node*>::iterator it;
	for (it = connections.begin(); it != connections.end(); ++it) 
		if ((*it)->is_marked_visited() != mark) {
			(*it)->mark_visited(mark);
			(*it)->mark_connected_nodes();
		}
	
}

/*******************************************
*****************disconnect*****************
********************************************
*disconnects a node from this.
*INPUT:
*	1) to_disconnect :	node that should be disconnected. 
*						NULL if no data about the node to disconnect.
*OUTPUT:
*	pointer to the disconnected node if the disconnection was made. NULL if not.
*/
/*
Node* Node::disconnect(Node * to_disconnect) {

	bool disconnected = true;
	if (to_disconnect == NULL)
		if (connection1 != NULL)
			to_disconnect = connection1;
		else if (connection2 != NULL)
			to_disconnect = connection2;
		else
			disconnected = false;

	if (disconnected)
		if (connection1 == to_disconnect){
			if(disconnected = to_disconnect->disconnect(this))
				connection1 = NULL;
		}
		else if (connection2 == to_disconnect) {
			if(disconnected = to_disconnect->disconnect(this))
				connection2 = NULL;
		}
		else
			disconnected = false;
	
	return (disconnected ? to_disconnect : NULL)
	
}
*/

Node * Node::get_connection(int i) {

	return (((i < 0) || (i >= connections.size()) ) ? NULL : connections[i]);
}

int Node::count = 0;
