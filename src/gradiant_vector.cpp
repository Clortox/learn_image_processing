///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Gradiant Vector implementation
//

#include "gradiant_vector.hpp"

png::image<png::gray_pixel> simple_gradiant(png::image<png::rgb_pixel>& source) {
    png::image<png::gray_pixel> ret(source.get_width(), source.get_height());
    for(size_t y = 0; y < source.get_height(); ++y){
        for(size_t x = 0; x < source.get_width(); ++x){
            png::rgb_pixel pixel = source.get_pixel(x, y);

            unsigned char gray = (pixel.red + pixel.green + pixel.blue) / 3;
            ret.set_pixel(x, y, gray);
        }
    }

    return ret;
}
