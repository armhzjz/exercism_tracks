#include <string.h>
#include <ctype.h>
#include "binary.h"


int convert(const char *input) {
    if(!input)
        return INVALID;

    size_t input_size = strlen(input);
    static char l;
    int ret_val = 0;

    if(input_size == 0)
        return INVALID;

    for(size_t exp = 0; input_size > 0; exp++) {
        l = input[--input_size];  // put the value into a var name 'l' just for 
                                  // better readability in the following lines
        if( isdigit(l) && ( (l - '0') < 2 ) )
            ret_val += (int)(l - '0') << exp;
        else
            return INVALID;
    }

    return ret_val;    
}
