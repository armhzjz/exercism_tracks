#include <math.h>
#include "all_your_base.h"


unsigned long convert_input_to_base_10(signed char*, unsigned long, signed short);
unsigned long DecToBase(signed short, signed long, signed char*);


unsigned long rebase(
        signed char* digits,
        signed short input_base,
        signed short output_base,
        unsigned long input_length) {
    if(!digits)
        return -1;
    if(input_length == 0 || input_base <= 1 || output_base <= 1)
        return 0;

    return DecToBase(output_base, convert_input_to_base_10(digits, input_length, input_base), digits);
}

unsigned long convert_input_to_base_10(signed char* digits, unsigned long input_length, signed short input_base) {
    signed long accumulative = 0;
    for(signed long digit_position = input_length -1; 0 <= digit_position; digit_position--) {
        /* if the digit is a negative number or its value happens to be greater than the input base */
        if(digits[input_length - digit_position - 1] < 0 || digits[input_length - digit_position - 1] >= input_base)
            return -1;
        accumulative += (pow(input_base, digit_position) * digits[input_length - digit_position - 1]);
    }
    return accumulative;
}

unsigned long DecToBase(signed short output_base, signed long decnum, signed char* digits) {
    // unsigned long num = 0, remainder = 0, exp = 0;
    unsigned long remainder = 0;
    unsigned int digit_counter = 0;
    unsigned int quotient = decnum;
    signed char reverse_digits[DIGITS_ARRAY_SIZE];

    if(decnum == 0)
        return 1;

    /*  if a negative digit was found during the converstion to base 10 
        or a digit was found to be greater than its input base */
    if(decnum < 0)
        return 0;

    while(quotient != 0) {
        remainder = quotient % output_base;
        reverse_digits[digit_counter++] = remainder;
        quotient = (unsigned int) (quotient / output_base);
    }

    for(signed int idx = digit_counter - 1; idx + 1 != 0; idx --)
        digits[idx] = reverse_digits[digit_counter - idx - 1];
    
    return digit_counter;
}
