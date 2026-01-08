#include "../my_top.h"

int count_users(void)
{
    int count = 0;
    struct utmp *users;

    setutent();
    users = getutent();
    while((users = getutent())!= NULL) {
        if (users->ut_type == USER_PROCESS) {
            count++;
        }    }
    endutent();
    return count;
}
