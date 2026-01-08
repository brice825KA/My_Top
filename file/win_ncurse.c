#include "../my_top.h"

int my_win_ncurse()
{
    initscr();
    int i = 0;
    noecho();
    timeout(1000);
    curs_set(0);
    struct timeval tv;
    double load[3];

    while (1) {
        i = getch();
        my_getloadavg(load, 3);
        char time_str[9];
        clear();
        mvprintw(0, 0, "Load: %.2f %.2f %.2f",  load[0], load[1], load[2]);
        gettimeofday(&tv, NULL);
        struct tm *tm_info = localtime(&tv.tv_sec);
        strftime(time_str, sizeof(time_str), "%H:%M:%S", tm_info);
        mvprintw(1, 0, "my_top: %s", time_str);
        refresh();
        if (i == 81 || i == 113)
            break;
    }
    endwin();
    return 0;
}
