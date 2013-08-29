/*******************************************************************************************************
 *文件名: AES.h
 *作者名: 姚玉成
 *Copyright (C) T??T
 *
********************************************************************************************************/

#pragma once
//typedef unsigned int u32;
//typedef unsigned char u8;

/**
 *	crypt_txt_size(int): 加密（解密）的数据长度，以字节为单位；
 *	password(const char *)： 秘钥的字节串表示，如果该字节串长度不够，则秘钥后面补零，过长则截取前面部分；
 *	keybits(int)： 秘钥位长；
 */
void initAES_cuda(int crypt_txt_size, const char *password, int keybits);
/**
 *	plaintext: 明文
 *	size(int): 加密的数据长度，以字节为单位
 *	ciphertext: 密文
**/
//__global__ void decryptKernel(u32 *rk, u8 *key, int keylen,  u8 ciphertext[],  int nstates);
//__global__ void encryptKernel(u32 *rk, u8 *key, int keylen,  u8 ciphertext[],  int nstates);
void releaseAES_cuda();
