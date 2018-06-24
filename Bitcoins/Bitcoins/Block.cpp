#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

void Block::setNonce(int nonce)
{
	this->nonce = nonce;
}

Transaction Block::getTransaction(int i)
{
	return transactionList[i];
}

size_t Block::getlistSize()
{
	return transactionList.size();
}