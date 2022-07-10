#include "sieve.h"


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if(!primes)
        return -1;

    uint32_t nums[limit - 1];
    size_t found_primes = 0;
    /* initializer array */
    for(uint32_t i = 2; i <= limit; i++)
        nums[i - 2] = i;

    /* sweep array and calculate number of primes */
    for(uint32_t i = 2; i <= limit; i++) {
        if(/* ... a not marked number is found*/
            0 != nums[i - 2]) {
            *primes++ = i;                                      /* save prime number to 'primes' array */
            for(uint32_t factor = i; (i * factor) - 2 < limit; factor++)
                nums[(i * factor) -2] = 0;
            if( (1 == 1) != (found_primes++ <= max_primes-2) )
                break;;

            // found_primes += found_primes < max_primes ? 1 : 0;  /* increment found prime numbers counter - up to max_primes */
            // size_t factor = i, mul = 0;                         /* prepare local variables */
            // do {
            //     mul = i * factor++;     /* calculate multiples of i */
            //     if( (mul - 2) < limit )
            //         nums[mul - 2] = 0;      /* mark all multiples of i */
            // } while(mul <= limit);
        }
    }
    return found_primes;
}
