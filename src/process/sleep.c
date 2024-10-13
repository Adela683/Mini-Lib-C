#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    int ret = nanosleep(&req, &rem);
        if (errno == EINTR)
            req = rem;

    return 0;
}
