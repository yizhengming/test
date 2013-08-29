/*******************************************************************************************************
 *文件名: aes.cuh
 *原作者：Rijndael
 *作者名: 姚玉成
 *version:0.1
 *Copyright (C) T??T
 *
********************************************************************************************************/
#include "AES.h"


int rijndaelSetupEncrypt(unsigned int *rk, const unsigned char *key,
  int keybits);
int rijndaelSetupDecrypt(unsigned int *rk, const unsigned char *key,
  int keybits);

#define USE_SHARED_MEM
//#undef USE_SHARED_MEM
#define KEYBITS 256
#define KEYLENGTH(keybits) ((keybits)/8)
#define RKLENGTH(keybits)  ((keybits)/8+28)
#define NROUNDS(keybits)   ((keybits)/32+6)


#include <stdlib.h>
#include <stdio.h>
/**
 * This macro checks return value of the CUDA runtime call and exits
 * the application if the call failed.
 */
#define CUDA_CHECK_RETURN(value) {											\
	cudaError_t _m_cudaStat = value;										\
	if (_m_cudaStat != cudaSuccess) {										\
		fprintf(stderr, "Error %s at line %d in file %s\n",					\
				cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);		\
		exit(1);															\
	} }
