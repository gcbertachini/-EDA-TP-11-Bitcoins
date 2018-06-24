#pragma once
#include"Block.h"
#include<string>
using namespace std;

class BlockChain
{
public:
	BlockChain();
	~BlockChain();

	bool addBlock(Block newblock);
	Block getBlock(int blockindex);

private:
	vector<Block> CadenaDeBloques;
};

