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

	void transactioncountSet(int i) { this->transactionCount = i; };
	void addTransaction(Transaction trans) { transactionList.push_back(trans); };


private:
	string previousBlockHash;
	int block_id;
	int nonce;
	int timestamp;
	int transactionCount;
	vector<Transaction> transactionList;

};

