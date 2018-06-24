#pragma once
#include "Observable.h"
#include "Node.h"
#include "BlockChain.h"
#include "UTXO.h"
#include "Block.h"
class FullServiceNode: public Node, public Observable
{
public:

	/*******************************************
	*************member variables***************
	********************************************/
	int public_key;
	/*******************************************
	*********************methods****************
	********************************************/

	//constructor and destructor.
	FullServiceNode();
	~FullServiceNode();
	virtual bool is_miner();

	bool addToBlockchain();


private:

	//methods:
	////////////////

	void create_transaction();
	void send_transaction();

	bool verifyRecievedBlock();
	bool insertBlockIntoBlockchain();

	//properties:
	///////////////

	uint32_t private_key;
	BlockChain * block_chain;

	Block* block2check;	 //Espacio para confirmar bloque entrante

	vector<Transaction>listaTransacciones;

	vector<UTXO> UTXOS;

};

/*
El Nodo est� compuesto por: 
a. Public Key (un valor de 32 bytes). 
b. Private Key (un valor de tama�o variable generado aleatoriamente).
c. Lista de todos los UTXOs (Transacciones de Salida �Unspent�) que debe ser actualizada cada vez que se recibe un bloque. 
d. Blockchain (una lista de Bloques). 
e. Una lista de transacciones que todav�a no se incluyeron en la Blockchain. 
f. Tipo de Nodo (si es �Minero� o �Full Service�). 
g. Un stack para recibir el bloque minado que luego ser� procesado. 
h. Un stack para almacenar transacciones a procesar y enviar si son v�lidas.
*/