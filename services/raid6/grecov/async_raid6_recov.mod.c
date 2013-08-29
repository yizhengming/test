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
	{ 0xca4cdc3c, "kmem_cache_destroy" },
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0xb85f3bbe, "pv_lock_ops" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0xb0d904b7, "raid6_empty_zero_page" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x9e7238f2, "kthread_create_on_node" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xb68aeaa, "kgpu_vfree" },
	{ 0x83636ee3, "wait_for_completion" },
	{ 0x24935f26, "raid6_call" },
	{ 0x964de881, "current_task" },
	{ 0x27e1a049, "printk" },
	{ 0xddf94339, "kthread_stop" },
	{ 0xb4390f9a, "mcount" },
	{ 0x57d5f277, "kmem_cache_free" },
	{ 0x90da2bb8, "kgpu_generic_log" },
	{ 0x7e1183c9, "async_schedule" },
	{ 0xa77f3071, "kmem_cache_alloc" },
	{ 0x78764f4e, "pv_irq_ops" },
	{ 0x1687d523, "async_tx_quiesce" },
	{ 0x93fca811, "__get_free_pages" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0xf333a2fb, "_raw_spin_lock_irq" },
	{ 0xdbab0c01, "raid6_datap_recov" },
	{ 0x2aea68d3, "kgpu_call_sync" },
	{ 0xcbaf25da, "wake_up_process" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0x98984d1c, "kgpu_free_request" },
	{ 0x22e3ec57, "kgpu_alloc_request" },
	{ 0x47e05f19, "kmem_cache_create" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xf09c7f68, "__wake_up" },
	{ 0xd2965f6f, "kthread_should_stop" },
	{ 0x15fe0cd3, "raid6_gfexp" },
	{ 0x5ba93f9d, "raid6_gfinv" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0xe419b12, "kgpu_vmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xbd662f6, "raid6_gfmul" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0xce45a6f1, "raid6_gfexi" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0xcdc24ab5, "raid6_2data_recov" },
	{ 0x5e09ca75, "complete" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=raid6_pq,kgpu,async_tx";


MODULE_INFO(srcversion, "EDBCC09A56D7DEE26477476");
