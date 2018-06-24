#pragma once
#include "FullServiceNode.h"

#include "cryptlib.h"	//LIbrerias Crypto
#include "osrng.h"
#include "eccrypto.h"
#include "oids.h"
#include "hex.h"
#include "sha3.h"

using namespace std;
class MinerNode : public FullServiceNode
{
public:
	MinerNode();
	~MinerNode();
	
	virtual bool is_miner();

	 bool mine();

	 bool createBlockFromStack();

	 bool sendBlockToAll();	//tambien envia dificultad
	

private:

	vector<int>previousNONCE;	//por si estoy repitiendo nonces(son aleatorios)
	Block* BlockToMine;	//tengo un bloque con mis transacciones que estoy minando.
	bool isNewNonce(int nonce);

	bool blockIncoming();	//Chequeo si tengo un bloque entrante (ya se mino, no tengo que seguir minando)

	int POW; 
	
};

