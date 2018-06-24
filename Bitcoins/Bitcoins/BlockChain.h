#pragma once
#include"Block.h"
using namespace std;

class BlockChain
{
public:
	BlockChain();
	~BlockChain();

	bool addBlock();
	Block getBlock(int blockid);

private:
	vector<Block>CadenaDeBloques;
};

