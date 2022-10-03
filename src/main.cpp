///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Entry point
//

#include <iostream>
#include <string>
#include <png++/png.hpp>
#include "gradiant_vector.hpp"

int main(int argc, char** argv){
    //png::image<png::rgb_pixel> myimage("img/input.png");
    png::image<png::rgb_pixel> myimage("img/amogus.png");

    png::image<png::gray_pixel> grayscale = simple_gradiant(myimage);
    grayscale.write("img/output.png");

    std::cout << "wrote!\n";
    return 0;
}
