#pragma once
#include "Observable.h"
#include "Node.h"
class FullServiceNode: public Node, public Observable
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
	virtual bool is_miner();

private:

};

