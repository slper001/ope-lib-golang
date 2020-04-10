#ifndef __CWRAP_H__
#define __CWRAP_H__
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
void NewOPE(const char *key);
uint64_t EncryptInt(int a);
int DecryptInt(uint64_t a);
#ifdef __cplusplus
}
#endif

#endif