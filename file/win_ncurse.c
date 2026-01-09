#include "../my_top.h"

int my_win_ncurse()
{
    initscr();
    int i = 0;
    noecho();
    timeout(1000);
    curs_set(0);
    struct timeval tv;
    process_t *proc;
    int user_count = 0;
    double load[3];

    while (1) {
        i = getch();
        char time_str[9];
        user_count = count_users();
        up_time_t up = uptime();
        my_getloadavg(load, 3);
        proc = task_run();
        clear();
        gettimeofday(&tv, NULL);
        struct tm *tm_info = localtime(&tv.tv_sec);
        strftime(time_str, sizeof(time_str), "%H:%M:%S", tm_info);
        mvprintw(0, 0, "my_top: %s, Load: %.2f %.2f %.2f, Uptime: %d days %d hours %d minutes, Users: %d",  time_str, load[0], load[1], load[2], up.days, up.hours, up.minutes, user_count);
        mvprintw(1, 0, "Tasks: %d total, %d running, %d sleeping, %d stopped, %d zombie", proc->tot_proc, proc->run_proc, proc->sleep_proc, proc->stop_proc, proc->zombie_proc);
        refresh();
        if (i == 81 || i == 113)
            break;
    }
    endwin();
    return 0;
}
