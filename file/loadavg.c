/*
** EPITECH PROJECT, 2026
** loadavg
** File description:
** loadavg
*/

#include "../my_top.h"

int my_getloadavg(double loadavg[], int nelem)
{
    FILE *fp = fopen("/proc/loadavg", "r");
    char *buffer = NULL;
    size_t len = 0;
    int i = 0;

    if (!fp)
        return -1;
    else {
        if (getline(&buffer, &len, fp) == -1)
            return -1;
        i = sscanf(buffer, "%lf %lf %lf", &loadavg[0], &loadavg[1], &loadavg[2]);
    }
    printf("%.2f %.2f %.2f\n", loadavg[0], loadavg[1], loadavg[2]);
    free(buffer);
    fclose(fp);
    if (i > nelem)
        i = nelem;
    return (i >= 0) ? i : -1;
}
