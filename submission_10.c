#include <unistd.h>
#include <sys/time.h>

useconds_t get_time(void) {
        struct timeval tv;

        gettimeofday(&tv, NULL);
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void Usleep(useconds_t microseconds) {
        useconds_t endtime, lefttime;

        endtime = get_time() + microseconds;
        while ((lefttime = endtime - get_time()) > 0) {
                usleep(lefttime / 2);
        }
}
