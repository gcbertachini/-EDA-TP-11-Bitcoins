#include "Node.h"

#define NOT_VISITED 0		//logical false!! always!

Node::Node()
{
	connection1 = NULL;
	connection2 = NULL;
	mark = NOT_VISITED;
}


Node::~Node()
{
}

/*******************************************
***************connect_to_node**************
********************************************
*connect_to_node connects the node to a given node.
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

	if (connection1 == NULL) {
		connection1 = node;
		connection_made = true;
	}
	else if (connection2 == NULL) {
		connection2 = node;
		connection_made = true;
	}

	return connection_made;
}
/*******************************************
***************is_fully_connected***********
********************************************
*is_fully_connected tells if the node has made all its possible connections.
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
	return ((connection1 != NULL) && (connection2 != NULL));
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


void Node::mark_connected_nodes() {
	if (connection1->is_marked_visited() != mark) {
		connection1->mark_visited(mark);
		connection1->mark_connected_nodes();
	}
	if (connection2->is_marked_visited() != mark) {
		connection2->mark_visited(mark);
		connection2->mark_connected_nodes();
	}
}