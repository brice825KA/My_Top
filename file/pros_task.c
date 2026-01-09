#include "../my_top.h"
#include <complex.h>

process_t *task_run(void)
{
    process_t *res_prosse = calloc(1, sizeof(process_t));
    char path[256];
    char state;
    char name[25];
    FILE *file;
    struct dirent *entry;
    DIR *directory;

    directory = opendir("/proc");
    if (directory == NULL) {
        printf("Directory empty");
        exit (84);
    }
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] >= '0' && entry->d_name[0] <= '9') {
            res_prosse->tot_proc += 1;
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            file = fopen(path, "r");
            fscanf(file, "%d %s %c",&res_prosse->pid, name, &state);
            if (state == 'R') res_prosse->run_proc++;
            else if (state == 'S' || state == 'D') res_prosse->sleep_proc++;
            else if (state == 'T') res_prosse->stop_proc++;
            else if (state == 'Z') res_prosse->zombie_proc++;
            fclose(file);
        }
    }
    closedir(directory);
    return res_prosse;
}
