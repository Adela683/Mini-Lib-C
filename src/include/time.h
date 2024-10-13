#ifndef _TIME_H_
#define _TIME_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

    struct timespec
    {
        int tv_sec;   /* seconds */
        long tv_nsec; /* nanoseconds */
    };

    unsigned int sleep(unsigned int seconds);
    int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
