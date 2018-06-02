#pragma once
#include "Observable.h"
#include "Node.h"
#include "BlockChain.h"

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


private:

	uint32_t private_key;
	BlockChain * block_chain;
};

/*
El Nodo está compuesto por: 
a. Public Key (un valor de 32 bytes). 
b. Private Key (un valor de tamaño variable generado aleatoriamente).
c. Lista de todos los UTXOs (Transacciones de Salida “Unspent”) que debe ser actualizada cada vez que se recibe un bloque. 
d. Blockchain (una lista de Bloques). 
e. Una lista de transacciones que todavía no se incluyeron en la Blockchain. 
f. Tipo de Nodo (si es “Minero” o “Full Service”). 
g. Un stack para recibir el bloque minado que luego será procesado. 
h. Un stack para almacenar transacciones a procesar y enviar si son válidas.
*/