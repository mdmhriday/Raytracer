#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"
#include "hittable.h"

class camera{
    public:
        // public camera parameters

        // images
        double aspect_ratio = 1.0;
        double image_width = 100;

        void render(const hittable& world){
            initialize();

            std::cout << "P3\n" << image_width << ' ' << image_height <<"\n255\n";

            for(int j = 0; j < image_width; j++){
                for(int i = 0; i < image_height; i++){
                    auto pixel_center = pixel_100_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                    auto ray_direction = pixel_center - center;
                    ray r(center, ray_direction);
                    color pixel_color = ray_color(r, world);
                    write_color(std::cout, pixel_color);
                }
            }
        }

    private:
        // private camera variables
        int image_height; // rendered image height
        point3 center; // camera center
        point3 pixel_100_loc; // location of pixel 0, 0
        vec3 pixel_delta_u; // offset of pixel to the right
        vec3 pixel_delta_v; // offset of pixel to the below

        void initialize(){
            image_height = int(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;

            center = point3(0, 0, 0);


            // viewport dimensions
            auto focal_length = 1.0;
            auto viewport_height = 2.0;
            auto viewport_width = viewport_height * (double(image_width/image_height));

            // calculate vectors across horizontal and vertical viewport edges
            auto viewport_u = vec3(viewport_width, 0, 0);
            auto viewport_v = vec3(0, -viewport_height, 0);

            // calculate the horizontal and vertical delta vectors form pixel to pixel
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            // calculate the location of the upper left pixel
            auto viewport_upper_left = center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
            pixel_100_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v);

        }

        color ray_color(const ray& r, const hittable& world) const {
            hit_record rec;

           if (world.hit(r, interval(0, infinity), rec)){
                return 0.5*(rec.normal + color(1, 1, 1));
            }

            vec3 unit_direction = unit_vector(r.direction());
            auto a = 0.5*(unit_direction.y() + 1.0);
            return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
        }

};

#endif