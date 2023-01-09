#include <stdlib.h>
#include <math.h>
#include "darts.h"

unsigned char score(coordinate_t landing_position)  {
    float radio = sqrt((landing_position.x*landing_position.x) + (landing_position.y*landing_position.y));

    if (radio > 10)
        return 0;
    if (radio <= 1)
        return 10;
    else if (radio <= 5)
        return 5;
    else
        return 1;
}
