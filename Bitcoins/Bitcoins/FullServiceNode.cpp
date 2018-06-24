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

void FullServiceNode::recieveBlock(Block newblock)
{
	this->block2check = new Block(newblock);
}

bool FullServiceNode::addToBlockchain()
{
	if (verifyRecievedBlock())
	{
		insertBlockIntoBlockchain();
	}
}

bool FullServiceNode::verifyRecievedBlock()	//me quedan en mi lista de transacciones solo aquellas que no esten en el bloque minado
{
	for (int i = 0; i < listaTransacciones.size(); i++)
	{
		Transaction transactioni = listaTransacciones[i];
		for (int j = 0; j < (block2check->getlistSize()); j++)
		{
			if (transactioni.gethash() == ((block2check->getTransaction(j)).gethash()))	//verifico que son iguales
				listaTransacciones.erase(listaTransacciones.begin()+i);	//Borro transaccion del nodo, ya que va a entrar en el blockchain
			break;
		}
	}
	return true;
}

bool FullServiceNode::insertBlockIntoBlockchain()
{
	block_chain->addBlock(*block2check);
}
