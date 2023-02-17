#include <math.h>
#include <stdio.h>
#include "space_age.h"

double age(planet_t planet, int64_t seconds) {
    if(planet < PLANET_MIN || planet > PLANET_MAX)
        return -1;
    double earth_age = (double) (seconds / earth_year_seconds);
    return (double) (earth_age / orbital_period_planet[planet]);
}
