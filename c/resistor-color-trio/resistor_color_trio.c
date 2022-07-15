#include <stdio.h>
#include <math.h>
#include "resistor_color_trio.h"


resistor_value_t color_code(resistor_band_t *bands) {
    resistor_value_t ret_val = { OHMS, 0 };
    ret_val.value = ((int)bands[0] * 10 + (int)bands[1]) * pow(10, (int)bands[2]);
    if(ret_val.value / 1000) {
        ret_val.value /= 1000;
        ret_val.unit = KILOOHMS;
    }
    return ret_val;
}
