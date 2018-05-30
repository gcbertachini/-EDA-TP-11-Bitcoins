/*
un bloque()= conjunto de transacciones

cada bloque tiene un ID hash

hashing:
Dichas funciones son rapidas de hacer(+-*).
f(x)=x´ 
a partir de un numero te manda a un espacio x´ perteneciente a|N.  No se puede volver para atras f^-1(x´)=inf .Hay infinitos valores para llegar 
a x´. 
Si además se cumple que f^-1(x´)=inf da realmente infinitos, numeros muy grandes, no se llega nunca a calcular como se hizo realmente.
La probalidad de(colision)f(x)=f(y)=x´ es casi nula. Distinto input igual output


Los ID hashs estan anidados, lo ID hash depende de los ID de los bloques de abajo. Por eso, cambiar un ID es casi imposible.

Meter el bloque en el blockchain es el proceso de minado

Cada adrress tiene una cantidad determinada de BTC, con un hash ID propio
para poder gastarlos debo proveer un numero tal que al aplicarle una función hash me de el lockingscript
lockingscript: resultado de haber aplicado una función hash, osea un ID hash

Para hacer una transaccion
Tengo 50BTC en addrees de Satoshi Nakamoto

InputTx -> ID unlockscript

OutputTx -> 25 Address amigo lockscript1  ->UTXO no se gastaron tdv
	-> 25 address satoshi lockscript2


	Proceso de minado: un bloque se mete en la blockchain


	main()
	{
	
	createNodes();
	while(checkConncetion)  //Hacer el DFS o BFS hasta que el árbol sea conexo
		made_conncetions;

	for(Nodes in Graph)  //Recorros todos los nodos del grafo a ver si tienen una transacción para mandar
	{
			if(Node.hasTxtosend())
				N.sendTx();     //Se la manda a los veciones
			
			if(Node.llegaronTx())
				N.verifyTxqueue();


			Idem anteriores if pero para bloques

			if(N.isminer())
				N.mine(); //pruebo un solo valor

	}
	
	}
	------
	User Interface(Allegro)
	------


	Funciones de un nodo:
	-Recibir una transacción     receiveTx(Tx,Pubkey);
	-Recibir un bloque			 receiveBlock(B,Pubkey);
	inputqueue
	outputqueue
	checkedTx(bool,Tx)
	cheackedBlock(bool,Bl)


	Un nodo ignora una Tx que ya le llego, ni se la mando a quuien me la mando
	
	Orden:
	Hacer las comunicaciones
	procesar
	minar

	Librería, bajar y buildear

	createTx(Ns,Ne,7){  //Se crea al llegar el evento de allegro
	//Miro las TXos(unspend transactions) del Ns
	//tengo 3 transsacciones de 3 BTC en Ns

	Uso las 3, va a ver una transacción con dos output
	1 de 7 BTC para Ne, y otra de 2BTC para Ns

	//Tengo que poner como gastadas a las transacciones ya hechas

	}
*/