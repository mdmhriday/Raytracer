#ifndef INTERVAL_H
#define INTERVAL_H

#include "utils.h"

class interval{
    public:
        double min, max;
        // default constructor
        interval() : min(+infinity), max(-infinity) {} 

        interval(double min, double max) : min(+infinity), max(-infinity) {}

        double size() const{
            return max - min;
        }

        bool contains(double x) const {
            return min <= x && x <= max;
        }

        bool surrounds(double x) const {
            return min < x && x < max;
        }

        static const interval empty, universe;


};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif