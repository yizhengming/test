/* This work is licensed under the terms of the GNU GPL, version 2.  See
 * the GPL-COPYING file in the top-level directory.
 *
 * Copyright (c) 2010-2011 University of Utah and the Flux Group.
 * All rights reserved.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include "../../../kgpu/kgpu.h"
#include "../../../kgpu/gputils.h"
#include "../gaesu.h"

#define BYTES_PER_BLOCK  1024
#define BYTES_PER_THREAD 4
#define BYTES_PER_GROUP  16
#define THREAD_PER_BLOCK (BYTES_PER_BLOCK/BYTES_PER_THREAD)
#define WORDS_PER_BLOCK (BYTES_PER_BLOCK/4)

#define BPT_BYTES_PER_BLOCK 4096

struct kgpu_service gaes_ecb_enc_srv;
struct kgpu_service gaes_ecb_dec_srv;

struct kgpu_service gaes_ctr_srv;
struct kgpu_service gaes_lctr_srv;

struct kgpu_service bp4t_gaes_ecb_enc_srv;
struct kgpu_service bp4t_gaes_ecb_dec_srv;

struct kgpu_service gaes_xts_enc_srv;
struct kgpu_service gaes_xts_dec_srv;

struct gaes_ecb_data {
    u32 *d_key;
    u32 *h_key;
    int nrounds;
    int nr_dblks_per_tblk;
};

struct gaes_ctr_data {
    u32 *d_key;
    u32 *h_key;
    u8 *d_ctr;
    u8 *h_ctr;
    int nrounds;
    int nr_dblks_per_tblk;
};

#if 0
static void dump_hex(u8* p, int rs, int cs)
{
    int r,c;
    printf("\n");
    for (r=0; r<rs; r++) {
	for (c=0; c<cs; c++) {
	    printf("%02x ", p[r*cs+c]);
	}
	printf("\n");
    }
}
#endif /* test only */

/*
 * Include device code
 */
#include "dev.cu"
#include "aes.cu"
#include "setupAES.cpp"

int gaes_ecb_compute_size_bpt(struct kgpu_service_request *sr)
{
    sr->block_x =
	sr->outsize>=BPT_BYTES_PER_BLOCK?
	BPT_BYTES_PER_BLOCK/16: sr->outsize/16;
    sr->grid_x =
	sr->outsize/BPT_BYTES_PER_BLOCK?
	sr->outsize/BPT_BYTES_PER_BLOCK:1;
    sr->block_y = 1;
    sr->grid_y = 1;

    return 0;
}

int gaes_ecb_compute_size_bp4t(struct kgpu_service_request *sr)
{
    sr->block_y =
	sr->outsize>=BYTES_PER_BLOCK?
	BYTES_PER_BLOCK/BYTES_PER_GROUP: (sr->outsize/BYTES_PER_GROUP);
    sr->grid_x =
	sr->outsize/BYTES_PER_BLOCK?
	sr->outsize/BYTES_PER_BLOCK:1;
    sr->block_x = BYTES_PER_GROUP/BYTES_PER_THREAD;
    sr->grid_y = 1;

    return 0;
}

#define RKLENGTH(keybits) ((keybits)/8+28) 
static int count = 0;
int gaes_ecb_launch_bpt(struct kgpu_service_request *sr)
{
    //struct crypto_aes_ctx *hctx = (struct crypto_aes_ctx*)sr->hdata;
    //struct crypto_aes_ctx *dctx = (struct crypto_aes_ctx*)sr->ddata;
	u8 *hkey;
	u8 *dkey;
	int blockDimX = 256+256;
	int gridDimX = (sr->outsize/16+blockDimX)/blockDimX;
	int keybits = 256;
    int i;
	//u32 *hencrypt_rk;
	//u32 *hdecrypt_rk;
	//u32 htd0[256];
	//u32 *dtd0;

	//hencrypt_rk = (u32 *)malloc(RKLENGTH(keybits)*sizeof(u32));
	//hdecrypt_rk = (u32 *)malloc(RKLENGTH(keybits)*sizeof(u32));

    //cudaMalloc(&dtd0, 256*sizeof(u32));
    //cudaMemcpy(dtd0, htd0, 256*sizeof(u32), cudaMemcpyHostToDevice);

	dkey = (u8 *)sr->ddata;
	hkey = (u8 *)sr->hdata;
    //memcpy(hkey,"01234567890123456789012345678912",32);
    //printf("hkey= %s \n",hkey);



    u32 *rk = new u32[RKLENGTH(keybits)];

    nrounds_en = rijndaelSetupEncrypt(rk, hkey, keybits);

	/*
    printf("call setpAES_cuda--en--rk_len: %d\n", RKLENGTH(keybits));
    for (i=0; i<60; i++) {
        //rk[i] = entmp[i];
        printf("%lu\n", rk[i]);
    }    
	*/

    cudaMalloc(&encrypt_rk_dev, RKLENGTH(keybits)*sizeof(u32));
    cudaMemcpy(encrypt_rk_dev, rk, RKLENGTH(keybits)*sizeof(u32), cudaMemcpyHostToDevice);

    nrounds_de = rijndaelSetupDecrypt(rk, hkey, keybits);
	/*
    printf("call setpAES_cuda--de--rk_len: %d\n", RKLENGTH(keybits));
    for (i=0; i<60; i++) {
        //rk[i] = detmp[i];
        printf("%lu\n", rk[i]);
    }
	*/
    cudaMalloc(&decrypt_rk_dev, RKLENGTH(keybits)*sizeof(u32));
    cudaMemcpy(decrypt_rk_dev, rk, RKLENGTH(keybits)*sizeof(u32), cudaMemcpyHostToDevice);


    if (sr->s == &gaes_ecb_dec_srv) {
    decryptKernel
		<<<gridDimX,blockDimX,
	    0, (cudaStream_t)(sr->stream)>>>
	    (
		decrypt_rk_dev,
		nrounds_de,
		(u8*)sr->dout,
		(u8*)sr->dout,
		(int)sr->outsize/16
		);
		/*
    	cudaMemcpy(htd0, dtd0, 256*sizeof(u32), cudaMemcpyDeviceToHost);
		printf("debug:=============htd0=====:\n");
    	for (i=0; i<256; i++) {
        	printf("%lu\n", htd0[i]);
    	}
		*/
	}
    else {
	encryptKernel
		<<<gridDimX,blockDimX,
	    0, (cudaStream_t)(sr->stream)>>>
	    (
		encrypt_rk_dev,
		nrounds_en,
		(u8*)sr->dout,
		(u8*)sr->dout,
		(int)sr->outsize/16
		);
		/*
    	cudaMemcpy(hencrypt_rk, encrypt_rk_dev, RKLENGTH(keybits)*sizeof(u32), cudaMemcpyDeviceToHost);
		printf("hencrypt_rk:\n");
    	for (i=0; i<60; i++) {
        	printf("%lu\n", hencrypt_rk[i]);
    	}    
		*/
	}
	cudaFree(decrypt_rk_dev);
	cudaFree(encrypt_rk_dev);
    return 0;
}

int gaes_ecb_launch_bp4t(struct kgpu_service_request *sr)
{
    struct crypto_aes_ctx *hctx = (struct crypto_aes_ctx*)sr->hdata;
    struct crypto_aes_ctx *dctx = (struct crypto_aes_ctx*)sr->ddata;
    
    if (sr->s == &gaes_ecb_dec_srv)        
	aes_decrypt_bp4t<<<
	    dim3(sr->grid_x, sr->grid_y),
	    dim3(sr->block_x, sr->block_y),
	    0, (cudaStream_t)(sr->stream)>>>
	    ((u32*)dctx->key_dec,
	     hctx->key_length/4+6,
	     (u8*)sr->dout);
    else
	aes_encrypt_bp4t<<<
	    dim3(sr->grid_x, sr->grid_y),
	    dim3(sr->block_x, sr->block_y),
	    0, (cudaStream_t)(sr->stream)>>>
	    ((u32*)dctx->key_enc,
	     hctx->key_length/4+6,
	     (u8*)sr->dout);
   
    return 0;
}

int gaes_ecb_prepare(struct kgpu_service_request *sr)
{
    cudaStream_t s = (cudaStream_t)(sr->stream);//gpu_get_stream(sr->stream_id);
    
    csc( ah2dcpy( sr->din, sr->hin, sr->insize, s) );
    
    return 0;
}

int gaes_ecb_post(struct kgpu_service_request *sr)
{
    cudaStream_t s = (cudaStream_t)(sr->stream);//gpu_get_stream(sr->stream_id);

    csc( ad2hcpy( sr->hout, sr->dout, sr->outsize, s) );
    
    return 0;
}

#define gaes_xts_post gaes_ecb_post
#define gaes_xts_prepare gaes_ecb_prepare

int gaes_xts_compute_size(struct kgpu_service_request *sr)
{
    sr->block_x = XTS_SECTOR_SIZE/AES_BLOCK_SIZE;
    sr->grid_x = sr->outsize/XTS_SECTOR_SIZE;
    sr->block_y = 1;
    sr->grid_y = 1;

    return 0;
}

int gaes_xts_launch(struct kgpu_service_request *sr)
{
    struct crypto_xts_info *hinfo =
	(struct crypto_xts_info*)(sr->hdata);
    struct crypto_xts_info *dinfo =
	(struct crypto_xts_info*)(sr->ddata);

    if (sr->s == &gaes_xts_dec_srv) 
        xts_decrypt<<<
	dim3(sr->grid_x, sr->grid_y),
	dim3(sr->block_x, sr->block_y),
	0, (cudaStream_t)(sr->stream)>>>
	    ((u32*)dinfo->key_dec,
	     hinfo->key_length/4+6,
	     (u8*)sr->dout,
	     dinfo->ivs);
    else
        xts_encrypt<<<
	dim3(sr->grid_x, sr->grid_y),
	dim3(sr->block_x, sr->block_y),
	0, (cudaStream_t)(sr->stream)>>>
	    ((u32*)dinfo->key_enc,
	     hinfo->key_length/4+6,
	     (u8*)sr->dout,
	     dinfo->ivs);
    return 0;
}

#define gaes_ctr_compute_size gaes_ecb_compute_size_bpt
#define gaes_ctr_post gaes_ecb_post
#define gaes_ctr_prepare gaes_ecb_prepare

int gaes_lctr_compute_size(struct kgpu_service_request *sr)
{
    struct crypto_gaes_ctr_info *info
	= (struct crypto_gaes_ctr_info*)(sr->hdata);
    sr->block_x = info->ctr_range/16;
    sr->grid_x = sr->outsize/sr->block_x;
    sr->block_y = 1;
    sr->grid_y = 1;

    return 0;
}

int gaes_ctr_launch(struct kgpu_service_request *sr)
{
    struct crypto_gaes_ctr_info *hinfo =
	(struct crypto_gaes_ctr_info*)(sr->hdata);
    struct crypto_gaes_ctr_info *dinfo =
	(struct crypto_gaes_ctr_info*)(sr->ddata);

    aes_ctr_crypt<<<
	dim3(sr->grid_x, sr->grid_y),
	dim3(sr->block_x, sr->block_y),
	0, (cudaStream_t)(sr->stream)>>>
	((u32*)dinfo->key_enc,
	 hinfo->key_length/4+6,
	 (u8*)sr->dout,
	 dinfo->ctrblk);
    return 0;
}

int gaes_lctr_launch(struct kgpu_service_request *sr)
{
    struct crypto_gaes_ctr_info *hinfo =
	(struct crypto_gaes_ctr_info*)(sr->hdata);
    struct crypto_gaes_ctr_info *dinfo =
	(struct crypto_gaes_ctr_info*)(sr->ddata);
    
    aes_lctr_crypt<<<
	dim3(sr->grid_x, sr->grid_y),
	dim3(sr->block_x, sr->block_y),
	0, (cudaStream_t)(sr->stream)>>>
	((u32*)dinfo->key_enc,
	 hinfo->key_length/4+6,
	 (u8*)sr->dout,
	 dinfo->ctrblk);
    return 0;
}

/*
 * Naming convention of ciphers:
 * g{algorithm}_{mode}[-({enc}|{dev})]
 *
 * {}  : var value
 * []  : optional
 * (|) : or
 */
extern "C" int init_service(void *lh, int (*reg_srv)(struct kgpu_service*, void*))
{
    int err;
    printf("[libsrv_gaes] Info: init gaes services\n");

    cudaFuncSetCacheConfig(decryptKernel, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(encryptKernel, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(aes_decrypt_bp4t, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(aes_encrypt_bp4t, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(aes_ctr_crypt, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(aes_lctr_crypt, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(xts_decrypt, cudaFuncCachePreferL1);
    cudaFuncSetCacheConfig(xts_encrypt, cudaFuncCachePreferL1);
    
    sprintf(gaes_ecb_enc_srv.name, "gaes_ecb-enc");
    gaes_ecb_enc_srv.sid = 0;
    gaes_ecb_enc_srv.compute_size = gaes_ecb_compute_size_bpt;
    gaes_ecb_enc_srv.launch = gaes_ecb_launch_bpt;
    gaes_ecb_enc_srv.prepare = gaes_ecb_prepare;
    gaes_ecb_enc_srv.post = gaes_ecb_post;
    
    sprintf(gaes_ecb_dec_srv.name, "gaes_ecb-dec");
    gaes_ecb_dec_srv.sid = 0;
    gaes_ecb_dec_srv.compute_size = gaes_ecb_compute_size_bpt;
    gaes_ecb_dec_srv.launch = gaes_ecb_launch_bpt;
    gaes_ecb_dec_srv.prepare = gaes_ecb_prepare;
    gaes_ecb_dec_srv.post = gaes_ecb_post;

    sprintf(gaes_ctr_srv.name, "gaes_ctr");
    gaes_ctr_srv.sid = 0;
    gaes_ctr_srv.compute_size = gaes_ctr_compute_size;
    gaes_ctr_srv.launch = gaes_ctr_launch;
    gaes_ctr_srv.prepare = gaes_ctr_prepare;
    gaes_ctr_srv.post = gaes_ctr_post;

    sprintf(gaes_lctr_srv.name, "gaes_lctr");
    gaes_lctr_srv.sid = 0;
    gaes_lctr_srv.compute_size = gaes_lctr_compute_size;
    gaes_lctr_srv.launch = gaes_lctr_launch;
    gaes_lctr_srv.prepare = gaes_ctr_prepare;
    gaes_lctr_srv.post = gaes_ctr_post;
    
    sprintf(gaes_xts_enc_srv.name, "gaes_xts-enc");
    gaes_xts_enc_srv.sid = 0;
    gaes_xts_enc_srv.compute_size = gaes_xts_compute_size;
    gaes_xts_enc_srv.launch = gaes_xts_launch;
    gaes_xts_enc_srv.prepare = gaes_xts_prepare;
    gaes_xts_enc_srv.post = gaes_xts_post;
    
    sprintf(gaes_xts_dec_srv.name, "gaes_xts-dec");
    gaes_xts_dec_srv.sid = 0;
    gaes_xts_dec_srv.compute_size = gaes_xts_compute_size;
    gaes_xts_dec_srv.launch = gaes_xts_launch;
    gaes_xts_dec_srv.prepare = gaes_xts_prepare;
    gaes_xts_dec_srv.post = gaes_xts_post;

    err = reg_srv(&gaes_ecb_enc_srv, lh);
    err |= reg_srv(&gaes_ecb_dec_srv, lh);
    err |= reg_srv(&gaes_ctr_srv, lh);
    err |= reg_srv(&gaes_lctr_srv, lh);
    err |= reg_srv(&gaes_xts_enc_srv, lh);
    err |= reg_srv(&gaes_xts_dec_srv, lh);
    if (err) {
    	fprintf(stderr,
		"[libsrv_gaes] Error: failed to register gaes services\n");
    } 
    
    return err;
}

extern "C" int finit_service(void *lh, int (*unreg_srv)(const char*))
{
    int err;
    printf("[libsrv_gaes] Info: finit gaes services\n");
    
    err = unreg_srv(gaes_ecb_enc_srv.name);
    err |= unreg_srv(gaes_ecb_dec_srv.name);
    err |= unreg_srv(gaes_ctr_srv.name);
    err |= unreg_srv(gaes_lctr_srv.name);
    err |= unreg_srv(gaes_xts_enc_srv.name);
    err |= unreg_srv(gaes_xts_dec_srv.name);
    if (err) {
    	fprintf(stderr,
		"[libsrv_gaes] Error: failed to unregister gaes services\n");
    }
    
    return err;
}


