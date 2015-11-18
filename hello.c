#include <linux/cdev.h>
#include <linux/module.h>


int hello_init(void){
	printk("Hello Linux device!\n");
	return 0;
}
void hello_exit(void){
	printk("Bye Linux device!\n");

}

MODULE_AUTHOR("Richard.Wang");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("The hello example");
module_init(hello_init);
module_exit(hello_exit);

