

#ifndef SHA1_H
#define SHA1_H

#include <stddef.h>

#define SHA1_BLOCK_SIZE 20              
typedef unsigned char BYTE;             
typedef unsigned int  WORD;          

typedef struct {
	BYTE data[64];
	WORD datalen;
	unsigned long long bitlen;
	WORD state[5];
	WORD k[4];
} SHA1_CTX;

void sha1_init(SHA1_CTX *ctx);
void sha1_update(SHA1_CTX *ctx, const BYTE data[], size_t len);
void sha1_final(SHA1_CTX *ctx, BYTE hash[]);

#endif   // SHA1_H
