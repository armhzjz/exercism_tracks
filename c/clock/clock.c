#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "clock.h"


clock_t clock_create(int hour, int minute) {
    clock_t clock;
    int roll_over_hours = minute / 60;
    int premilinary_hour_l = ((24 + (hour%24) + roll_over_hours) % 24);
    premilinary_hour_l = premilinary_hour_l < 0 ? 24 + premilinary_hour_l : premilinary_hour_l;
    int hour_l = (minute % 60) < 0 ? (24 + premilinary_hour_l -1) % 24 : premilinary_hour_l;
    int minute_l = (minute < 0) && (minute % 60) ? 60 + (minute % 60) : minute % 60;
    sprintf(clock.text, "%02d:%02d", hour_l, minute_l);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {  
    char *endptr;
    int minutes_l = (int) strtoimax((const char *) &clock.text[3], &endptr, 10);
    int hours_l =   (int) strtoimax((const char *) &clock.text, &endptr, 10);

    minutes_l += minute_add;
    return clock_create(hours_l, minutes_l);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {    
    return clock_add(clock, -minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return !strcmp(a.text, b.text);
}
