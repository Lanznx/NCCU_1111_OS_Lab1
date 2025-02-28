#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/param.h> // 定義了HZ
#include <linux/jiffies.h> // 裡裡面宣告了jiffies變數

// 當模組被載入會觸發這個函式 返回0代表成功 其他值代表失敗
static int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "init_jiffies: %lu \n", jiffies);
    printk(KERN_INFO "HZ: %d\n", HZ);
       return 0;
}

// 當模組被移除會觸發這個函式 無返回值
static void simple_exit(void) {
    printk(KERN_INFO "exit_jiffies: %lu \n", jiffies);
    printk(KERN_INFO "Removing Module\n");
}

//這兩個巨集指令是註冊模組的入口與出口
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("NOBODY");
