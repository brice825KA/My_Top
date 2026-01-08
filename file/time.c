#include "../my_top.h"
#include <stdio.h>

up_time_t uptime(void)
{
    up_time_t uptime = {0, 0, 0};
    double up = 0.0;
    FILE *file_uptime = fopen("/proc/uptime", "r");

    if(file_uptime) {
        fscanf(file_uptime, "%lf", &up);
        uptime.days = (int)up / 86400;
        uptime.hours = (int)up % 86400 / 3600;
        uptime.minutes = (int)up % 3600 / 60;
    }
    fclose(file_uptime);
    return uptime;
}
