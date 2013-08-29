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
	{ 0x36317105, "put_page" },
	{ 0x9b49eb33, "alloc_pages_current" },
	{ 0xb86e4ab9, "random32" },
	{ 0x5e09ca75, "complete" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x27e1a049, "printk" },
	{ 0x14afe381, "async_raid6_datap_recov" },
	{ 0xb616195c, "async_gen_syndrome" },
	{ 0xe5c9a0cc, "async_xor" },
	{ 0x8d4dcdc9, "wait_for_completion_timeout" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xe44c04b4, "async_syndrome_val" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0x787629b2, "async_raid6_2data_recov" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=async_raid6_recov,async_pq,async_xor";


MODULE_INFO(srcversion, "CA65B509202A824FC1041F0");
