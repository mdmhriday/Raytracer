#ifndef COLOR_H
#define COLOR_H

#include "utils.h"
#include "vec3.h"


using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();


    // translate the [0, 1] component values to the byte range [0, 255]
    int r_byte = int(255.999 * r);
    int g_byte = int(255.999 * g);
    int b_byte = int(255.999 * b);

    // write out pixel color components.
    out << r_byte << ' ' << g_byte << ' ' << b_byte << '\n';

}

#endif