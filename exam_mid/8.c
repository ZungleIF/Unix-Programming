#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main()
{
    time_t tt;          // A struct for time().
    struct tm *tm;      // A struct for localtime().
    // An array for representing day of week.
    char day[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    time(&tt);             // Get the time from system.
    tm = localtime(&tt);   // Converts the time to localtime.

    /*
        time() or localtime() returns the current time based on
        how much time has elapsed since 1900.1.1. 00:00:00 UTC.
        This means tm_year has to be added by 1900.
        tm_mon starts from 0 somehow, so I should add 1.
    */
    printf("%d. %d. %d. (%s) %d:%d:%d %s\n", 
                1900 + tm->tm_year, 1 + tm->tm_mon, tm->tm_mday, day[tm->tm_wday],
                       tm->tm_hour,     tm->tm_min, tm->tm_sec ,     tm->tm_zone);
    return 0;
}