#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// c++ Std using

using std::make_shared;
using std::shared_ptr;

// constant

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utilities functions
inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

// common headers

#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"

#endif