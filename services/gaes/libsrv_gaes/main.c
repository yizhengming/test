#include <stdio.h>

void main()
{
	u8 key[32] = "12345678901234567890123456789012"; 
	
	u32 *decrypt_rk_dev;
    u32 *encrypt_rk_dev;
    cudaMalloc(&decrypt_rk_dev, RKLENGTH(256)*sizeof(u32));
    cudaMalloc(&encrypt_rk_dev, RKLENGTH(256)*sizeof(u32));
	cudaMalloc();

}
