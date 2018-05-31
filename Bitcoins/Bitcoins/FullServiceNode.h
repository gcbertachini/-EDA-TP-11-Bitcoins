#pragma once
#include "Observable.h"
class FullServiceNode: public Observable
{
public:

	/*******************************************
	*************member variables***************
	********************************************/

	/*******************************************
	*********************methods****************
	********************************************/

	//constructor and destructor.
	FullServiceNode();
	~FullServiceNode();

	//connection related methods.
	bool connect_to_node(FullServiceNode * node);
	bool is_fully_connected();

	//visited related methods.
	void mark_visited(int group);
	void unmark_visited();
	int is_marked_visited();

	//getters and atribute related methods.
	virtual bool is_miner();



private:

	/*******************************************
	*************member variables***************
	********************************************/
	FullServiceNode * connection1;		
	FullServiceNode * connection2;

	int mark;			//visited mark. 0 if not visited.

	/*******************************************
	*********************methods****************
	********************************************/

};

