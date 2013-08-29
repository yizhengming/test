#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x52211446, "module_layout" },
	{ 0xd1e71fb8, "crypto_attr_alg2" },
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0xc897c382, "sg_init_table" },
	{ 0xd16712f3, "crypto_check_attr_type" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0x1ca35bf0, "crypto_mod_put" },
	{ 0xda185d2a, "kgpu_call_async" },
	{ 0xbf5d0684, "crypto_unregister_template" },
	{ 0x3fec048f, "sg_next" },
	{ 0x1aa799e4, "crypto_blkcipher_type" },
	{ 0x3aa2e1bd, "crypto_spawn_tfm" },
	{ 0x485523f6, "kgpu_alloc_mmap_area" },
	{ 0x689a6ba, "kgpu_unmap_area" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0x24aac4d9, "crypto_aes_expand_key" },
	{ 0xd423085e, "kgpu_free_mmap_area" },
	{ 0xb68aeaa, "kgpu_vfree" },
	{ 0xa46f1221, "crypto_register_template" },
	{ 0xb10ec686, "wait_for_completion_interruptible" },
	{ 0xb4390f9a, "mcount" },
	{ 0x90da2bb8, "kgpu_generic_log" },
	{ 0x8058583e, "crypto_drop_spawn" },
	{ 0x93fca811, "__get_free_pages" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x9a79cdab, "crypto_alloc_instance" },
	{ 0xa4e40938, "crypto_destroy_tfm" },
	{ 0x2aea68d3, "kgpu_call_sync" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0xe52947e7, "__phys_addr" },
	{ 0x98984d1c, "kgpu_free_request" },
	{ 0x22e3ec57, "kgpu_alloc_request" },
	{ 0x80184f2f, "kgpu_map_page" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0xe419b12, "kgpu_vmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0x236c8c64, "memcpy" },
	{ 0x3c44f434, "blkcipher_walk_virt" },
	{ 0x5e09ca75, "complete" },
	{ 0x8546e0d4, "blkcipher_walk_done" },
	{ 0x96feb6a4, "crypto_alloc_base" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kgpu,aes_generic";


MODULE_INFO(srcversion, "7CBDF8AA29F670C6D371B2A");
