#include <mini-os/os.h>
#include <mini-os/sched.h>
#include <mini-os/shutdown.h>
#include <mini-os/wait.h>

static int _shutdown;
static int _reason;

/* Defined in daytime.c */
extern void run_server(void *p);
extern void stop_server(void);

static struct wait_queue_head main_waitq;

int main(int argc, char **argv)
{
    DEFINE_WAIT(w);

    _shutdown = 0;
    init_waitqueue_head(&main_waitq);

    create_thread("server", run_server, NULL);

    for ( ;; ) {
        while (!_shutdown) { add_waiter(w, main_waitq); schedule(); };

        if (_reason == SHUTDOWN_suspend) {
            _shutdown = 0;
            kernel_suspend();
        } else {
            break;
        }
    }

    return _reason;
}

void app_shutdown(int reason)
{
    printk("Shutdown requested: %d\n", reason);
    _shutdown = 1;
    _reason = reason;
    wake_up(&main_waitq);
    //stop_server();
}

