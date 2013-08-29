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
	{ 0xdc360e7f, "__alloc_workqueue_key" },
	{ 0x499fab1c, "dm_get_device" },
	{ 0x3de59ccc, "dm_table_get_mode" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x12cafe25, "bioset_create" },
	{ 0x53326531, "mempool_alloc_pages" },
	{ 0xd985dc99, "mempool_free_pages" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0xa05c03df, "mempool_kmalloc" },
	{ 0x26d6c0b6, "mempool_create" },
	{ 0x183fa88b, "mempool_alloc_slab" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x50354760, "crypto_alloc_ablkcipher" },
	{ 0x9edbecae, "snprintf" },
	{ 0x55f2580b, "__alloc_percpu" },
	{ 0x42224298, "sscanf" },
	{ 0x85df9b6c, "strsep" },
	{ 0xc499ae1e, "kstrdup" },
	{ 0x349cba85, "strchr" },
	{ 0x96feb6a4, "crypto_alloc_base" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0x94c2a080, "crypto_alloc_shash" },
	{ 0xb8c736d2, "dm_register_target" },
	{ 0x47e05f19, "kmem_cache_create" },
	{ 0xb6244511, "sg_init_one" },
	{ 0x8810ad5e, "crypto_xor" },
	{ 0x4c4fef19, "kernel_stack" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x6d21c016, "crypto_shash_update" },
	{ 0x7a4497db, "kzfree" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0xd3599249, "dm_put_device" },
	{ 0xe74cf0a7, "mempool_destroy" },
	{ 0xff537907, "bioset_free" },
	{ 0xa4e40938, "crypto_destroy_tfm" },
	{ 0x3bf04d57, "destroy_workqueue" },
	{ 0x64999478, "congestion_wait" },
	{ 0xcf97d78d, "bio_add_page" },
	{ 0x83636ee3, "wait_for_completion" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x37a0cba, "kfree" },
	{ 0xc897c382, "sg_init_table" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x5e09ca75, "complete" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xef62e85f, "mempool_alloc" },
	{ 0xd768e0ea, "bio_put" },
	{ 0x319c8584, "queue_work" },
	{ 0x4688f4d6, "bio_endio" },
	{ 0xceecfd70, "mempool_free" },
	{ 0x88d3dfa4, "bio_free" },
	{ 0x3791ecb4, "generic_make_request" },
	{ 0xe4e84db5, "bio_alloc_bioset" },
	{ 0x236c8c64, "memcpy" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xe24050c7, "scnprintf" },
	{ 0xde0bdcff, "memset" },
	{ 0x756e6992, "strnicmp" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x25ec1b28, "strlen" },
	{ 0xc5844fb8, "__per_cpu_offset" },
	{ 0xfe7c4287, "nr_cpu_ids" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xb2e55898, "cpu_possible_mask" },
	{ 0x7628f3c7, "this_cpu_off" },
	{ 0x27e1a049, "printk" },
	{ 0xca4cdc3c, "kmem_cache_destroy" },
	{ 0x1a1d1baa, "dm_unregister_target" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "CEA54C10496664DDADC2F6D");
