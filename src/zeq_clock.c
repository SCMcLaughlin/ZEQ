
#include <stdint.h>
#include <time.h>
#include "zeq_clock.h"

int64_t clock_milliseconds()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1000 + t.tv_nsec / 1000000;
}

int64_t clock_microseconds()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1000000 + t.tv_nsec / 1000;
}

int64_t clock_unix_seconds()
{
    return time(NULL);
}

void clock_sleep(uint32_t ms)
{
    struct timespec t;
    t.tv_sec = ms / 1000;
    t.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&t, NULL);
}