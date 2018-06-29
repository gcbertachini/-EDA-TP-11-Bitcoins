#pragma once

#include "cryptlib.h"
#include "osrng.h"
#include "eccrypto.h"
#include "oids.h"
#include "hex.h"
#include "sha3.h"

using namespace std;
using namespace CryptoPP;

#define PRIVATE_KEY_CHARS 20
#define PUBLIC_KEY_CHARS 40

ECDSA<ECP, SHA256>::PrivateKey generatePrivKey();
vector<byte> getSignature(ECDSA<ECP, SHA256>::PrivateKey &privKey, string &data);
bool verifySignature(ECDSA<ECP, SHA256>::PublicKey &pubKey, string &data, vector<byte> &signature);
void showData(ECDSA<ECP, SHA256>::PrivateKey &pubKey, ECDSA<ECP, SHA256>::PublicKey &privKey, vector<byte> &signature);
void hexPrint(vector<byte> &dataToPrint);