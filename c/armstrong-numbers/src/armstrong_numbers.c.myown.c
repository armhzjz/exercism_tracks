#include "armstrong_numbers.h"
#include "armstrong_numbers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    unsigned int num_digits = 0, digit = 0, a = 0;
    unsigned int auxiliar_i = (unsigned int) candidate, candidate_copy = (unsigned int) candidate;
    
    /* find out how many digits are in the candidate integer argument
       the manual way */
    //  while(auxiliar_i >= 10) {
    //     auxiliar_i /= 10;
    //     num_digits++;
    // };
    // num_digits++;

    /* find out how many digits are in the candidate integer argument
    using abs, log10 and floor. This is a different, more expensive way of
    calculating the number of digits on an integer, but it might be more scalable
    when it comes to long integers (being in such cases faster than the
    approach lines above). */
    num_digits = (unsigned int) floor(log10(abs(candidate))) + 1;

    auxiliar_i = 0;
    for(int i=(int) num_digits; i>=0; i--) {
        a = (unsigned int) pow(10, (double) i);
        digit = (double) (candidate_copy / a);
        auxiliar_i += (unsigned int) pow(digit, (double) num_digits);
        candidate_copy -= (unsigned int) digit * a;
    };

    return auxiliar_i == (unsigned int) candidate;
}


int main(void) {
    is_armstrong_number(153);
    return 0;
}
