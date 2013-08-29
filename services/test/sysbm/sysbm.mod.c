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
	{ 0x5e09ca75, "complete" },
	{ 0xb68aeaa, "kgpu_vfree" },
	{ 0x98984d1c, "kgpu_free_request" },
	{ 0x27e1a049, "printk" },
	{ 0x83636ee3, "wait_for_completion" },
	{ 0xda185d2a, "kgpu_call_async" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0xa1f67123, "kgpu_next_request_id" },
	{ 0x2aea68d3, "kgpu_call_sync" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xe419b12, "kgpu_vmalloc" },
	{ 0x22e3ec57, "kgpu_alloc_request" },
	{ 0x90da2bb8, "kgpu_generic_log" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kgpu";


MODULE_INFO(srcversion, "FCA305E818C470F280CDE1D");
