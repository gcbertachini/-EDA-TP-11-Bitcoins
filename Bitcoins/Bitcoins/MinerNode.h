#pragma once
#include "FullServiceNode.h"
class MinerNode : public FullServiceNode
{
public:
	MinerNode();
	~MinerNode();
	
	virtual bool is_miner();

};

