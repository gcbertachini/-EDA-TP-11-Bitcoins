#include "MinerNode.h"

enum{DIF_OK, MORE_DIF, LESS_DIF};

MinerNode::MinerNode(int Node_ammount)
{
	this->Node_ammount = Node_ammount;	//Nunca es 0
	success_time = 60 / Node_ammount;
	this->Ptimer = new Timer;
}


MinerNode::~MinerNode()
{
	delete Ptimer;
}

bool MinerNode::mine()
{
	Ptimer->start();
	bool answer;
	int newnonce = rand();
	while (!isNewNonce(newnonce))	// Chequeo que no haya usado previamente el nonce
	{
		newnonce = rand();
	}
	previousNONCE.push_back(newnonce);
	BlockToMine->setNonce(newnonce);

	string hash = hasheame();

	Ptimer->stop();
	time_mined += Ptimer->getTime();

	if (checkChallenge(hash))	//Chequeo que se cumpla el challenge
	{
		setPOW(hash);	//GUardo el nuevo POW
		setDifficulty(checkDifficulty());	//Setteo la nueva dificultad
		sendBlockToAll();	//FALTA HACER (enviar bloque minado a los demas nodos)
		killBlock();	//Mato el bloque para luego crear otro
		previousNONCE.clear();	//Borro los nonces ya que cambio de bloque
		createBlockFromStack();	//Creo Bloque con las transacciones nuevas
		answer = true;
		time_mined = 0;
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

bool MinerNode::verifyRecievedBlock()	//Falta que pasa si no hay transacciones	(SE PUEDE HACER MAS LINDO CON CONSTRUCTOR DE BLOQUE)
{
	for (int i = 0; i < listaTransacciones.size(); i++)
	{
		BlockToMine->addTransaction(listaTransacciones[i]);	//Paso transaciones de lista del nodo, a bloque a minar
	}

	
	for (int i = 0; i < BlockToMine->getlistSize(); i++)	// Saco del bloque a minar las transacciones que estan en el bloque ya minado
	{
		Transaction transactioni = BlockToMine->getTransaction(i);
		for (int j = 0; j < (block2check->getlistSize()); j++)
		{
			if (transactioni.gethash() == ((block2check->getTransaction(j)).gethash()))	//verifico que son iguales
				listaTransacciones.erase(listaTransacciones.begin() + i);	//Borro transaccion del nodo, ya que va a entrar en el blockchain
			break;
		}
	}

	BlockToMine->transactioncountSet(listaTransacciones.size());
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

string MinerNode::hasheame() {
	fillString();
	SHA256 hash;
	string digest;
	StringSource s(blockString, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
	return digest;
}

void MinerNode::fillString()
{
	blockString.clear();
	char * aux;
	for (int i = 0; i < sizeof(Block); i++, aux++)
	{
		blockString += *aux;
	}
}

int MinerNode::checkDifficulty()	//Evaluo cuanto tiempo tarda en resolver el challenge para adaptar la dificultad
{
	int respuesta;
	if (((abs(time_mined - success_time)) > 1) && (time_mined > success_time))	//Chequeo si estoy fuera del threshold y si me paso del tiempo esperado
		respuesta = LESS_DIF;
	else if (((abs(time_mined - success_time)) > 1) && (time_mined < success_time))
		respuesta = MORE_DIF;
	else		//Esta dentro del threshold
		respuesta = DIF_OK;

	return respuesta;
}

void MinerNode::setDifficulty(int dif_indicator)
{
	switch (dif_indicator)	//dependiendo de en cuanto tiempo se resolvio aumento, decremento o dejo la dificultad igual
	{
	case MORE_DIF:
		POW_number++;
	case LESS_DIF:
		POW_number--;
	default:
		break;
	}
}
