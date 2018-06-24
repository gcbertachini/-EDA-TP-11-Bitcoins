#pragma once
#include<string>
#include"Transaction.h"

using namespace std;

class Block
{
public:
	Block();
	~Block();
	void setNonce(int nonce);

	Transaction getTransaction(int i);

	size_t getlistSize();

private:
	string previousBlockHash;
	int block_id;
	int timestamp;
	int nonce;
	int transactionCount;
	vector<Transaction> transactionList;

};

