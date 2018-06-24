#pragma once
#include "FullServiceNode.h"

#include "cryptlib.h"	//LIbrerias Crypto
#include "osrng.h"
#include "eccrypto.h"
#include "oids.h"
#include "hex.h"
#include "sha3.h"


#include<string>


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

	 string getPOW();

	 void setPOW(string newPOW);
	

private:

	vector<int>previousNONCE;	//por si estoy repitiendo nonces(son aleatorios)
	Block* BlockToMine;	//tengo un bloque con mis transacciones que estoy minando.
	bool isNewNonce(int nonce);

	bool blockIncoming();	//Chequeo si tengo un bloque entrante (ya se mino, no tengo que seguir minando)
	
	bool checkChallenge(string hash);	//Chequeo 
	int POW_number;	//cantidad de ceros para el challenge

	bool killBlock();

	string POW; //el POW en si
	
};

//FALTA  HASHEO, Chequeo dificultad, Send Block to all, block_incoming (HACER LOGICA DE MINADO DE TODOS LOS NODOS), cuando se recibe un bloque eliminar al que se estaba minando.