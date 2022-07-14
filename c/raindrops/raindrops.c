#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raindrops.h"


char *convert(char result[], int drops) {
    char *p = malloc(sizeof(char) * 16);
    const int factors[] = {3,5,7};
    char *rain_sounds[] = {
        "Pling",
        "Plang",
        "Plong"
    };
    for(int idx = 0; idx < 3; idx++) {
        p = ( 0 == (drops % factors[idx])) ? rain_sounds[idx] : "\0";
        if(0 != strcmp(p, "\0"))
            strcat(result, p);
    }
    if(*result == 0)
        sprintf(result, "%d", drops);

    return result;   
}