#ifndef CRYPTONIGHT_H
#define CRYPTONIGHT_H

#include <stdbool.h>
#include <stdint.h>

void cryptonight_hash(void* output, const void* input, const int aes_ni_supported);
int scanhash_cryptonight(char* pdata, uint32_t target, uint32_t max_nonce, uint64_t* hashes_done);

void cryptolight_hash(void* output, const void* input, const int aes_ni_supported);
int scanhash_cryptolight(char* pdata, uint32_t target, uint32_t max_nonce, uint64_t* hashes_done);

bool has_aes_ni(void);
void bestcpu_feature(char *outbuf, int maxsz);
float cpu_temp(int core);

#endif /* CRYPTONIGHT_H */