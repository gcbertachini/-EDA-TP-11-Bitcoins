#pragma once
#include <string>		//necesito incluir algo del estilo para que me reconozca NULL!
#include <vector>
 class Node abstract
{
public:
	Node();
	~Node();

	//connection related methods.
	///////////////////////////////

	bool connect_to_node(Node * node);
	bool is_fully_connected();

	//visited related methods.
	void mark_visited(int group);
	void unmark_visited();
	int is_marked_visited();
	void mark_connected_nodes();

	//getters and atribute related methods.
	///////////////////////////////
	int name;

	Node * get_connection(int i);
private:

	/*******************************************
	*************member variables***************
	********************************************/
	std::vector<Node*> connections;
	int mark;			//visited mark. 0 if not visited.
	static int count;

	/*******************************************
	*********************methods****************
	********************************************/
};


