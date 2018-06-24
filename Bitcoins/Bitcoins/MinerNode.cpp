#include "MinerNode.h"



MinerNode::MinerNode()
{
}


MinerNode::~MinerNode()
{
}

bool MinerNode::mine()
{
	bool answer;
	int newnonce = rand();
	while (!isNewNonce(newnonce))	// Chequeo que no haya usado previamente el nonce
	{
		newnonce = rand();
	}
	BlockToMine->setNonce(newnonce);

	string hash;
	//hash = hash();

	if (checkChallenge(hash))	//Chequeo que se cumpla el challenge
	{
		setPOW(hash);	//GUardo el nuevo POW
		checkDifficulty();	//Veo si tengo que modificaar la dificultad
		sendBlockToAll();	//FALTA HACER (enviar bloque minado a los demas nodos)
		killBlock();	//Mato el bloque para luego crear otro
		previousNONCE.clear();	//Borro los nonces ya que cambio de bloque
		createBlockFromStack();	//Creo Bloque con las transacciones nuevas
		answer = true;
	}

	else
	{
		answer = false;
	}

	return answer;
	
}

bool MinerNode::isNewNonce(int nonce)	//Chequeo que el nonce no se haya usado antes
{
	bool answer = true;
	for (int i = 0; i < previousNONCE.size(); i++)
	{
		if (previousNONCE[i] == nonce)
		{
			answer = false;
			break;
		}
	}
	return answer;
}

bool MinerNode::checkChallenge(string hash)
{
	
	for (int i = 0; i < POW_number; i++)
	{
		if (hash[i] != '0')
			return false;
	}
	return true;
}

string MinerNode::getPOW()
{
	return POW;
}

void MinerNode::setPOW(string newPOW)
{
	this->POW = newPOW;
}

bool MinerNode::killBlock()
{
	delete this->BlockToMine;
}

bool MinerNode::createBlockFromStack()	//Falta que pasa si no hay transacciones	(SE PUEDE HACER MAS LINDO CON CONSTRUCTOR DE BLOQUE)
{
	BlockToMine = new Block;
	BlockToMine->transactioncountSet(listaTransacciones.size());
	for (int i = 0; i < listaTransacciones.size(); i++)
	{
		BlockToMine->addTransaction(listaTransacciones[i]);	//Paso transaciones de lista del nodo, a bloque
	}

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

