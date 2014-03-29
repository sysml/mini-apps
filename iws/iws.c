#include <stdlib.h>
#include <mini-os/sched.h>
#include <mini-os/shutdown.h>

int main(int argc, char **argv) 
{
    int reason;
    unsigned long sleep;

    if (argc < 2) {
        reason = SHUTDOWN_poweroff;
    } else if (strcmp(argv[1], "poweroff") == 0) {
        reason = SHUTDOWN_poweroff;
    } else if (strcmp(argv[1], "reboot") == 0) {
        reason = SHUTDOWN_reboot;
    } else if (strcmp(argv[1], "suspend") == 0) {
        reason = SHUTDOWN_suspend;
    } else if (strcmp(argv[1], "crash") == 0) {
        reason = SHUTDOWN_crash;
    } else {
        printk("Invalid shutdown reason: %s\n", argv[1]);
        reason = SHUTDOWN_crash;
    }

    if (argc < 3) {
        sleep = 1000;
    } else {
        sleep = atol(argv[2]);
    }

    if (sleep) {
        printk("Waiting %lu msec!\n", sleep);
        msleep(sleep);
    }

    if (reason != SHUTDOWN_suspend) {
        kernel_shutdown(reason);
    } else {
        kernel_suspend();
    }

    return 0;
}
