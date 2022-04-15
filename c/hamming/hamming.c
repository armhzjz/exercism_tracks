#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    /* counter or hamming distance */
    unsigned int distance = 0;

    for(; *lhs && *rhs; lhs++, rhs++) {
            if(*lhs != *rhs) {
                ++ distance;
            }
        }

    return (*lhs || *rhs) ? (unsigned int) -1 : distance;
}