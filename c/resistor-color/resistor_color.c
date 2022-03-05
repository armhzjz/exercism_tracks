#include "resistor_color.h"
#include <stdlib.h>
#include <string.h>


unsigned int color_code(resistor_band_t color) {
    return (unsigned int) color;
}

const resistor_band_t* colors(void) {
    resistor_band_t *colors = malloc(sizeof(resistor_band_t) * (WHITE - BLACK + 1));
    for(int i=0; i<= (WHITE - BLACK); i++) {
        colors[i] = (resistor_band_t) i;
    }

    return colors;
}