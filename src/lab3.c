#include <linux/init.h> // Required for __init and __exit macros
#include <linux/module.h>  // Needed for all kernel modules
#include <linux/jiffies.h> // Provides access to jiffies (system tick counter)
#include <linux/timekeeping.h>// Provides ktime_get_boottime() for precise timing
MODULE_LICENSE("Dual BSD/GPL");

static unsigned long j_starttime;
static ktime_t start_time;
unsigned int ms_ticktime;

unsigned long j_endtime; //stores jiffies count at module removal.
static ktime_t end_time;
unsigned long j_difference;
unsigned long ms_runtime;

static int hello_init(void){
    j_starttime = jiffies;
    start_time = ktime_get_boottime();

    printk(KERN_ALERT "Hello, world\n"); //urgent meassages

    ms_ticktime = 1000/HZ; // calculate jiffy in millisecond
    printk(KERN_INFO "Tick time in ms: %u\n" , ms_ticktime); //gen info
    return 0;
}


static void hello_exit(void){
    j_endtime = jiffies; // Store jiffies at module removal
    end_time = ktime_get_boottime(); // Capture precise boot time

    j_difference = j_endtime - j_starttime; // Compute difference in jiffies
    ms_runtime = ((j_endtime - j_starttime) * 1000) / HZ; // Convert jiffies to ms

    printk(KERN_ALERT "Goodbye, cruel world\nJiffies difference: %lu\nTime difference (ms): %lu\n", j_difference, ms_runtime);
}
module_init(hello_init);
module_exit(hello_exit);