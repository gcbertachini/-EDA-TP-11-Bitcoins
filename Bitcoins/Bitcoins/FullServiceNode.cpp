#include "FullServiceNode.h"


FullServiceNode::FullServiceNode()
{
	block_chain = new BlockChain();
}

FullServiceNode::~FullServiceNode()
{
}

/*******************************************
******************is_miner******************
********************************************
*is_miner tells the user whether the FullServiceNode is 
*also acting as a miner. 
*INPUT:
*	1) void
*
*OUTPUT:
*	a boolean that is true if the FullServiceNode is a miner.
*	false if not.
*By default this method returns false. It should be overriden for the child class.
*
*/
bool FullServiceNode::is_miner() {
	return false;
}