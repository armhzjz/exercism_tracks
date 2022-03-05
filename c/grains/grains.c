#include "grains.h"
//#include <math.h>

uint64_t square(uint8_t index) {
    /* solution 1 */
    /* return (uint64_t) pow(2, index - 1); */

    /* solution 2 - fastest */
    if (index > SQUARE_MAX || index < SQUARE_MIN)
        return 0;
    return (uint64_t) 1 << (index-1);
}

uint64_t total(void) {
    /* solution 1 */
    /* return (uint64_t) pow(2, 63); */

    /* solution 2 - fastest */
    uint64_t total_grain = 0;
    for (uint8_t TOTAL_SQUARES_NUMBER = SQUARE_MIN; TOTAL_SQUARES_NUMBER <= SQUARE_MAX; TOTAL_SQUARES_NUMBER++)
        total_grain |= square(TOTAL_SQUARES_NUMBER);
    return total_grain;
}
