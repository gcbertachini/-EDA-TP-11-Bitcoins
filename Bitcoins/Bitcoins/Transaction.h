#pragma once
#include "Input.h"
#include "Output.h"
#include "crypto.h"

class Transaction
{
public:
	Transaction();
	~Transaction();
	//Necesito una funcion que me devuelva el hash (muchas gracias)

	SHA256 hashID;

private:
	vector<Input> inputs;
	vector<Output> outputs;
};



/*
Una Transaction está compuesta de: 
a. Un HashID (un hash SHA256 de los componentes b, c d y e). 
b. Un arreglo de Inputs. 
c. La cantidad de Inputs. 
d. Un arreglo de Outputs. 
e. La cantidad de Outputs.
*/