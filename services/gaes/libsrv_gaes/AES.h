/*******************************************************************************************************
 *�ļ���: AES.h
 *������: Ҧ���
 *Copyright (C) T??T
 *
********************************************************************************************************/

#pragma once
//typedef unsigned int u32;
//typedef unsigned char u8;

/**
 *	crypt_txt_size(int): ���ܣ����ܣ������ݳ��ȣ����ֽ�Ϊ��λ��
 *	password(const char *)�� ��Կ���ֽڴ���ʾ��������ֽڴ����Ȳ���������Կ���油�㣬�������ȡǰ�沿�֣�
 *	keybits(int)�� ��Կλ����
 */
void initAES_cuda(int crypt_txt_size, const char *password, int keybits);
/**
 *	plaintext: ����
 *	size(int): ���ܵ����ݳ��ȣ����ֽ�Ϊ��λ
 *	ciphertext: ����
**/
//__global__ void decryptKernel(u32 *rk, u8 *key, int keylen,  u8 ciphertext[],  int nstates);
//__global__ void encryptKernel(u32 *rk, u8 *key, int keylen,  u8 ciphertext[],  int nstates);
void releaseAES_cuda();
