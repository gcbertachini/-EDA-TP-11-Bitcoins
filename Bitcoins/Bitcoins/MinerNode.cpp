#include "MinerNode.h"



MinerNode::MinerNode()
{
}


MinerNode::~MinerNode()
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
*	true by default. 
*	the child class should change this if not.
*
*/
bool MinerNode::is_miner() {
	return true;
}

