#include <linux/cdev.h>


int hello_init(void){
	printk("Hello Linux device!\n");
	return 0;
}
void hello_exit(void){
	printk("Bye Linux device!\n");

}

module_init(hello_init);
module_exit(hello_exit);

