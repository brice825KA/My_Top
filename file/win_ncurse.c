cp #include <ncurses.h>

int my_win_ncurse()
{
    initscr();
    int i = 0;
    timeout(3000);
    double load[3];

    while (1) {
        i = getch();
        my_getloadavg(load, 3);
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "Load: %.2f %.2f %.2f",  load[0], load[1], load[2]);
        refresh();
        if (i == 81 || i == 113)
            break;
    }
    endwin();
    return 0;
}
