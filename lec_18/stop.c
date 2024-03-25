/*
 * stop.c - Illustration of multi filed modules
 */

#include <linux/kernel.h> /* We are doing kernel work */
#include <linux/module.h> /* Specifically, a module */

void cleanup_module(void)
{
    pr_info("Stop kernel\n");
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Stop module");
