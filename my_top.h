/*
** EPITECH PROJECT, 2026
** my_top.h
** File description:
** my_top.h
*/

#ifndef _MY_TOP_H_
    #define _MY_TOP_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/select.h>
    #include <ncurses.h>
    #include <sys/time.h>
    #include <time.h>
    #include <curses.h>
    #include <utmp.h>
    #include <sys/types.h>
    #include <dirent.h>

typedef struct up_time{
    int days;
    int hours;
    int minutes;
} up_time_t;

typedef struct process {
    int pid;
    int tot_proc;
    int run_proc;
    int sleep_proc;
    int stop_proc;
    int zombie_proc;
} process_t;

int my_getloadavg(double loadavg[], int nelem);
int my_win_ncurse();
up_time_t uptime(void);
int count_users(void);
process_t *task_run(void);

#endif
