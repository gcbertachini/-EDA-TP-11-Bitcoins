#include "BlockChain.h"



BlockChain::BlockChain()
{

}


BlockChain::~BlockChain()
{
}

bool BlockChain::addBlock(Block newblock)
{
	CadenadenaDeBloques.push_back(newblock);
	return true;
}


Block* BlockChain::getBlock(int blockindex)
{
	if (blockindex > CadenaDeBloques.size())
		return NULL;
	return &CadenaDeBloques[blockindex];
	
}