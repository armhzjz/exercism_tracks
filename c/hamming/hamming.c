#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    /* counter or hamming distance */
    unsigned int distance = 0;

    if(strlen(lhs) != strlen(rhs)) {
        /* length of strands are not equal */
        return -1;
    } else {
        for(unsigned int i = 0; i < strlen(lhs); i++) {
            if(lhs[i] != rhs[i]) {
                ++ distance;
            }
        }
    }

    return distance;
}