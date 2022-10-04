///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Gradiant Vector implementation
//

#include "gradiant_vector.hpp"

png::image<png::gray_pixel> simple_gradiant(png::image<png::rgb_pixel>& source) {
    png::image<png::gray_pixel> ret(source.get_width(), source.get_height());
    for(int y = 0; y < source.get_height(); ++y){
        for(int x = 0; x < source.get_width(); ++x){
            //png::rgb_pixel pixel = source.get_pixel(x, y);
            std::cout << "at " << x << " " << y << std::endl;

            int up_coordinate   = (y - 1 > 0                   ? y - 1 : y);
            int down_coordinate = (y + 1 < source.get_height() ? y + 1 : y);

            //find vertical gradiant
            png::rgb_pixel up = source.get_pixel(x, up_coordinate);
            png::rgb_pixel down = source.get_pixel(x, down_coordinate);
            int vertical_average =
                ((up.red + up.green + up.blue) / 3) -
                ((down.red + down.green + down.blue) / 3);
            std::cout << "vert " << vertical_average << std::endl;

            int left_coordinate  = (x - 1 > 0                  ? x - 1 : x);
            int right_coordinate = (x + 1 < source.get_width() ? x + 1 : x);

            png::rgb_pixel left = source.get_pixel(left_coordinate, y);
            png::rgb_pixel right = source.get_pixel(right_coordinate, y);
            int horizontal_average =
                ((left.red + left.green + left.blue) / 3) -
                ((right.red + right.green + right.blue) / 3);
            std::cout << "horz " << horizontal_average << std::endl;

            unsigned char current_pixel = pow((horizontal_average*horizontal_average) + (vertical_average*vertical_average), 0.5);
            std::cout << "pixel " << (int) current_pixel << std::endl;
            ret.set_pixel(x, y, current_pixel);
        }
    }

    return ret;
}
