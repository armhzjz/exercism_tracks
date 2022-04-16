#include <stdio.h>
#include "difference_of_squares.h"


unsigned int sum_of_squares(unsigned int number) {
    unsigned int res = 0;
    for(; number-- > 0;) {
        res += (number + 1) * (number + 1);
    }
    /*
    res = number * (number + 1) >> 1;
    */
    return res;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int res = 0;
    for(; number-- > 0;) {
        res += number + 1;
    }
    /*
    res = number * (number + 1) * (2 * number + 1) / 6;
    */
    return res * res;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}
