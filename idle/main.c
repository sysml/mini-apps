#include <mini-os/os.h>
#include <mini-os/sched.h>
#include <mini-os/shutdown.h>

static int _shutdown;
static int _reason;

int main(int argc, char **argv)
{
    _shutdown = 0;

    for ( ;; ) {
        while (!_shutdown) { schedule(); };

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
    _shutdown = 1;
    _reason = reason;
}

