#pragma once
#include <string>		//necesito incluir algo del estilo para que me reconozca NULL!

class Node
{
public:
	Node();
	~Node();

	//connection related methods.
	bool connect_to_node(Node * node);
	bool is_fully_connected();

	//visited related methods.
	void mark_visited(int group);
	void unmark_visited();
	int is_marked_visited();
	void mark_connected_nodes();

	//getters and atribute related methods.

private:

	/*******************************************
	*************member variables***************
	********************************************/
	Node* connection1;
	Node* connection2;

	int mark;			//visited mark. 0 if not visited.

	/*******************************************
	*********************methods****************
	********************************************/
};

