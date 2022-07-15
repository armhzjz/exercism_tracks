#include "resistor_color_duo.h"


int color_code(resistor_band_t *bands) {
    return ((int)bands[0] * 10) + (int)bands[1];
}