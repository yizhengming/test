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
	{ 0xa90c928a, "param_ops_int" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xa4e40938, "crypto_destroy_tfm" },
	{ 0x37a0cba, "kfree" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0xe52947e7, "__phys_addr" },
	{ 0x93fca811, "__get_free_pages" },
	{ 0xc897c382, "sg_init_table" },
	{ 0x96feb6a4, "crypto_alloc_base" },
	{ 0x4b5814ef, "kmalloc_order_trace" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "198C6A662BE71B4B9D99C24");
