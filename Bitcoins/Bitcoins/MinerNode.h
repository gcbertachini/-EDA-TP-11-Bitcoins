#pragma once
#include "FullServiceNode.h"

#include "cryptlib.h"	//LIbrerias Crypto
#include "osrng.h"
#include "eccrypto.h"
#include "oids.h"
#include "hex.h"
#include "sha3.h"
#include "Timer.h"



#include<string>


using namespace std;
using namespace CryptoPP;

class MinerNode : public FullServiceNode
{
public:
	MinerNode(int Node_number);
	~MinerNode();

	Timer * Ptimer; //puntero a funciones de timer

	bool is_miner();

	 bool mine();

	 bool createBlockFromStack();

	 bool sendBlockToAll();	//tambien envia dificultad

	 string getPOW();

	 void setPOW(string newPOW);

	 string hasheame();

	 string blockString;

	 void fillString();

	 void maliciousTransaction(Transaction mali_trans); //Me llega una transaccion maliciosa y la saco del blockchain

private:

	vector<int>previousNONCE;	//por si estoy repitiendo nonces(son aleatorios)

	Block* BlockToMine;	//tengo un bloque con mis transacciones que estoy minando.

	bool isNewNonce(int nonce);

	int checkDifficulty();

	void setDifficulty(int dif_indicator);

	bool verifyRecievedBlock();	//Tacho las transacciones minadas por otro nodo, y agrego las nuevas
	
	bool checkChallenge(string hash);	//Chequeo si se completoel challenge

	static int POW_number;	//cantidad de ceros para el challenge

	float success_time;	//Goal de tiempo para minar, depende de cantidad de nodos

	bool killBlock();

	string POW; //el POW en si

	int Node_ammount;	//Cantidad de nodos

	float time_mined; //Tiempo acumulativo que tarda el nodo individual en minar
	
};

int MinerNode::POW_number = 6;		// Inicio en 6 por que me gusta ese numero




//FALTA Send Block to all, block_incoming (HACER LOGICA DE MINADO DE TODOS LOS NODOS), cuando se recibe un bloque eliminar al que se estaba minando.