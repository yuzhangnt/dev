#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

#include <linux/fs.h>

static int mymajor = 245;
static int myminor = 0;
static int number_of_devices = 1;

static int hello_init(void){
	int ret;
	dev_t  devnu = 0;

	devnu = MKDEV(mymajor, myminor);
	ret = register_chrdev_region(devnu, number_of_devices, "hello");
	if(ret < 0){
		printk("Hello: can't get major number %d\n", mymajor);
		return ret;
	}

	printk("Registered character driver \'hello\'!\n");
	return 0;
}

static void hello_exit(void){
	dev_t devnu = 0;
	devnu = MKDEV(mymajor, myminor);
	unregister_chrdev_region(devnu, number_of_devices);
	printk("Bye driver \'hello\'!\n");

}

MODULE_AUTHOR("Richard.Wang");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("The hello example");
module_init(hello_init);
module_exit(hello_exit);

