#include <mini-os/os.h>
#include <mini-os/sched.h>
#include <mini-os/sys/time.h>
#include <mini-os/time.h>

int main(int argc, char **argv) 
{
#ifdef USE_NOW
    s_time_t tv1;
    s_time_t tv2;

    for(;;)
    {
        tv1 = NOW();
        tv2 = NOW();
        printk("[ns1=%ld ns2=%ld]  diff = %ld\n",
                tv1, tv2,
                tv2 - tv1);
#else
    struct timeval tv1;
    struct timeval tv2;

    for(;;)
    {
        gettimeofday(&tv1, NULL);
        gettimeofday(&tv2, NULL);
        printk("[us1=%ld us2=%ld]  diff = %ld\n",
                tv1.tv_usec, tv2.tv_usec,
                tv2.tv_usec - tv1.tv_usec);
#endif
        msleep(100);
    }

    return 0;
}

