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
	{ 0xf11355ab, "blk_queue_merge_bvec" },
	{ 0x9b49eb33, "alloc_pages_current" },
	{ 0xca4cdc3c, "kmem_cache_destroy" },
	{ 0x6e9927b0, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x14afe381, "async_raid6_datap_recov" },
	{ 0xaeb1aba2, "blk_queue_io_opt" },
	{ 0xd6dc4efc, "mddev_congested" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xb85f3bbe, "pv_lock_ops" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0xd0ee38b8, "schedule_timeout_uninterruptible" },
	{ 0xb960cea7, "bio_clone_mddev" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xb89e62ec, "remove_wait_queue" },
	{ 0x77814942, "md_check_recovery" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xbf7418bc, "blk_queue_io_min" },
	{ 0xf4ce1386, "md_write_end" },
	{ 0x9410e935, "seq_printf" },
	{ 0xacf7679, "dma_issue_pending_all" },
	{ 0xbc329074, "bitmap_endwrite" },
	{ 0x24fa1e05, "bitmap_unplug" },
	{ 0x55f2580b, "__alloc_percpu" },
	{ 0xe44c04b4, "async_syndrome_val" },
	{ 0xb8617f94, "md_new_event" },
	{ 0x999e8297, "vfree" },
	{ 0x1aa8c966, "unregister_md_personality" },
	{ 0x47c7b0d2, "cpu_number" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xfcb885d3, "revalidate_disk" },
	{ 0x7d11c268, "jiffies" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xffd5a395, "default_wake_function" },
	{ 0xfe7c4287, "nr_cpu_ids" },
	{ 0x75d87cbb, "bitmap_start_sync" },
	{ 0x3c80c06c, "kstrtoull" },
	{ 0xde0bdcff, "memset" },
	{ 0x9049dcc7, "md_register_thread" },
	{ 0x19335e03, "bio_init" },
	{ 0x3a27bf08, "md_flush_request" },
	{ 0x88941a06, "_raw_spin_unlock_irqrestore" },
	{ 0x964de881, "current_task" },
	{ 0x27e1a049, "printk" },
	{ 0x421c9cd4, "sysfs_create_group" },
	{ 0x765eefa9, "md_do_sync" },
	{ 0x787629b2, "async_raid6_2data_recov" },
	{ 0x8ce109d8, "async_trigger_callback" },
	{ 0xfa44d2e3, "disk_stack_limits" },
	{ 0x6cdf8e5f, "bitmap_close_sync" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb4390f9a, "mcount" },
	{ 0x57d5f277, "kmem_cache_free" },
	{ 0x2e06111d, "cpu_present_mask" },
	{ 0xc2cdbf1, "synchronize_sched" },
	{ 0x78175304, "async_memcpy" },
	{ 0x5fd4f4c5, "blk_recount_segments" },
	{ 0x3791ecb4, "generic_make_request" },
	{ 0xa11a493a, "sysfs_remove_link" },
	{ 0x609024ae, "md_wait_for_blocked_rdev" },
	{ 0x4688f4d6, "bio_endio" },
	{ 0x7e1183c9, "async_schedule" },
	{ 0xd768e0ea, "bio_put" },
	{ 0xb4b824f1, "md_done_sync" },
	{ 0x21c26244, "flush_signals" },
	{ 0x74cc1cbe, "unregister_cpu_notifier" },
	{ 0x5699b3d9, "sysfs_create_link" },
	{ 0xdd1c65f6, "blk_finish_plug" },
	{ 0xad743255, "async_xor_val" },
	{ 0xa77f3071, "kmem_cache_alloc" },
	{ 0x78764f4e, "pv_irq_ops" },
	{ 0x168fb048, "bitmap_cond_end_sync" },
	{ 0xe5c9a0cc, "async_xor" },
	{ 0x57dfdcc4, "md_write_start" },
	{ 0x4550ba8a, "register_cpu_notifier" },
	{ 0xd4d46ab5, "bdevname" },
	{ 0x5a7ef035, "sysfs_notify_dirent" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xb2e55898, "cpu_possible_mask" },
	{ 0xbb55cc56, "md_allow_write" },
	{ 0x1000e51, "schedule" },
	{ 0xd7d79132, "put_online_cpus" },
	{ 0xb4e9fc94, "md_set_array_sectors" },
	{ 0xf333a2fb, "_raw_spin_lock_irq" },
	{ 0x77049e27, "sysfs_notify" },
	{ 0x1eec3771, "md_wakeup_thread" },
	{ 0x88163a64, "mddev_check_plugged" },
	{ 0x3efb35c9, "get_online_cpus" },
	{ 0x5f8b11e0, "kmem_cache_alloc_trace" },
	{ 0x6443d74d, "_raw_spin_lock" },
	{ 0xc5844fb8, "__per_cpu_offset" },
	{ 0x587c70d8, "_raw_spin_lock_irqsave" },
	{ 0x47e05f19, "kmem_cache_create" },
	{ 0xf09c7f68, "__wake_up" },
	{ 0xd2965f6f, "kthread_should_stop" },
	{ 0x2d339ed2, "md_unregister_thread" },
	{ 0xda5661a3, "add_wait_queue" },
	{ 0xb616195c, "async_gen_syndrome" },
	{ 0x37a0cba, "kfree" },
	{ 0x8265d7d, "bitmap_startwrite" },
	{ 0xc1362db6, "dma_wait_for_async_tx" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0xe845acee, "md_error" },
	{ 0x36317105, "put_page" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0x43a0458b, "blk_start_plug" },
	{ 0x649f3f3d, "register_md_personality" },
	{ 0xda609f7f, "bitmap_end_sync" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=async_raid6_recov,async_pq,async_tx,async_memcpy,async_xor";


MODULE_INFO(srcversion, "BB04130317B94C3E13F87F0");