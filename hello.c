#include <linux/cdev.h>


int __init hello_init(void){
	printk("Hello Linux device!\n");
	return 0;
}
void __exit hello_exit(void){
	printk("Bye Linux device!\n");

}

