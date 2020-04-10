#include "ope.hh"
#include "cwrap.h"
#include <string>
using namespace std;

// plaintext range's length in bits (plaintexts are in [0, 2**P-1]
unsigned int P = 32;
	// ciphertext range's length in bits (ciphertexts are in [0, 2**C-1]
unsigned int C = 64;

OPE o("S0M3 $TR@NG Key", P, C);


void NewOPE(const char *key){
    string k = key;
    o = OPE(k, P, C);
}

// const char * Encrypt(int a){
//     NTL::ZZ m = o.encrypt(a);
//     string s = StringFromZZ(m);
//     const char *p = s.c_str();
//     return p;
// }

uint64_t EncryptInt(int a) {
    uint64_t k = a;
    NTL::ZZ m = ZZFromUint64(k);
    NTL::ZZ enc = o.encrypt(m);
    uint64_t i = uint64FromZZ(enc);
    return i;
}

// int Decrypt(const char *p){
//     string s = p;
//     NTL::ZZ z = ZZFromString(s);
//     NTL::ZZ dec = o.decrypt(z);
//     int res = NTL::to_int(dec);
//     return res;
// }

int DecryptInt(uint64_t a){
    NTL::ZZ z = ZZFromUint64(a);
    NTL::ZZ dec = o.decrypt(z);
    int res = NTL::to_int(dec);
    return res;
}


