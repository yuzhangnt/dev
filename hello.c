#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

static int myint = 222;
static short int myshort = 111;
static long int mylog = 333;
static char * mystring = "My string";

module_param(myint, int, 0400);
MODULE_PARM_DESC(myint, "An integer");

module_param(myshort, short, 0400);
MODULE_PARM_DESC(myshort, "A short integer");

module_param(mylog, long, 0000);
MODULE_PARM_DESC(mylog, "A long integer");

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

static int hello_init(void){

	printk("Hello Linux device!\n");
	printk("### myint  = %d\n", myint);
	printk("### myshort = %hd\n", myshort);
	printk("### mylong = %ld\n", mylog);
	printk("### mystring = %s\n", mystring);
	return 0;
}

static void hello_exit(void){
	printk("Bye Linux device!\n");

}

MODULE_AUTHOR("Richard.Wang");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("The hello example");
module_init(hello_init);
module_exit(hello_exit);

