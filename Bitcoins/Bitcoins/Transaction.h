#pragma once
class Transaction
{
public:
	Transaction();
	~Transaction();


private:

};



/*
Una Transaction está compuesta de: 
a. Un HashID (un hash SHA256 de los componentes b, c d y e). 
b. Un arreglo de Inputs. 
c. La cantidad de Inputs. 
d. Un arreglo de Outputs. 
e. La cantidad de Outputs.
*/