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
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0xda185d2a, "kgpu_call_async" },
	{ 0x999e8297, "vfree" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xb68aeaa, "kgpu_vfree" },
	{ 0x24935f26, "raid6_call" },
	{ 0xb10ec686, "wait_for_completion_interruptible" },
	{ 0xb4390f9a, "mcount" },
	{ 0x90da2bb8, "kgpu_generic_log" },
	{ 0x2aea68d3, "kgpu_call_sync" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0x98984d1c, "kgpu_free_request" },
	{ 0x22e3ec57, "kgpu_alloc_request" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0xe419b12, "kgpu_vmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0x236c8c64, "memcpy" },
	{ 0x5e09ca75, "complete" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kgpu,raid6_pq";


MODULE_INFO(srcversion, "EB3FA7875E9AB1204A0FF65");
