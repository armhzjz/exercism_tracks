#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum {
   PLANET_MIN = 0,
   MERCURY  = 0,
   VENUS    = 1,
   EARTH    = 2,
   MARS     = 3,
   JUPITER  = 4,
   SATURN   = 5,
   URANUS   = 6,
   NEPTUNE  = 7,
   PLANET_MAX = 7
} planet_t;

static const double orbital_period_planet[] = {
   0.2408467,
   0.61519726,
   1.0,
   1.8808158,
   11.862615,
   29.447498,
   84.016846,
   164.79132
};

static const double earth_year_seconds = 31557600;

double age(planet_t planet, int64_t seconds);

#endif
