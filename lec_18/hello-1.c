/*
 * hello-1.c - The simplest kernel module.
 */
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */
#include <linux/kernel.h>

int init_module(void)
{
    pr_alert("Hello world 1.\n");
    //pr_info, pr_debug, pr_alert
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

void cleanup_module(void)
{
    pr_alert("Goodbye world 1.\n");
}

MODULE_LICENSE("Eltex");
