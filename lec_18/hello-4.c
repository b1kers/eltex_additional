/*
 * hello-4.c - Demonstrates module documentation.
 */
#include <linux/init.h> /* Needed for the macros */
#include <linux/module.h> /* Needed by all modules */
#include <linux/moduleparam.h>
//#include <linux>
#include <linux/printk.h> /* Needed for pr_info() */

MODULE_LICENSE("None");
MODULE_AUTHOR("Ilya");
MODULE_DESCRIPTION("None");

int a = 4;
module_param(a, int, 0);

static int __init init_hello_4(void)
{
    pr_info("Hello, world %d\n", a);
    return 0;
}

static void __exit cleanup_hello_4(void)
{
    pr_info("Goodbye, world 4\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);
