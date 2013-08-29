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
	{ 0x187aea08, "cdev_del" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0xc7e90fc0, "cdev_init" },
	{ 0x8260686f, "bitmap_find_next_zero_area" },
	{ 0x4c4fef19, "kernel_stack" },
	{ 0xb85f3bbe, "pv_lock_ops" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xb9219c42, "device_destroy" },
	{ 0xf803fe39, "bitmap_set" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xde0bdcff, "memset" },
	{ 0x964de881, "current_task" },
	{ 0x27e1a049, "printk" },
	{ 0xedbd8d84, "vmap" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb4390f9a, "mcount" },
	{ 0xbf8ba54a, "vprintk" },
	{ 0x57d5f277, "kmem_cache_free" },
	{ 0xb8b14e73, "device_create" },
	{ 0xd2bfe70a, "up_write" },
	{ 0xa7da6ded, "down_write" },
	{ 0x2d7999e2, "vm_insert_page" },
	{ 0xb3850451, "cdev_add" },
	{ 0xa77f3071, "kmem_cache_alloc" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x1000e51, "schedule" },
	{ 0x6443d74d, "_raw_spin_lock" },
	{ 0x47e05f19, "kmem_cache_create" },
	{ 0xf09c7f68, "__wake_up" },
	{ 0xf1f1fb77, "zap_vma_ptes" },
	{ 0x37a0cba, "kfree" },
	{ 0x94961283, "vunmap" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0xbf7f2003, "pv_mmu_ops" },
	{ 0x576052fc, "class_destroy" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xe9869369, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xd92afabe, "bitmap_clear" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4F91B7CE3F0C3D7E2865968");
