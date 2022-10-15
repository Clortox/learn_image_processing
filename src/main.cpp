///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Entry point
//

#include <iostream>
#include <string>
#include <png++/png.hpp>
#include "gradiant_vector.hpp"

void help(char** argv){
    std::cout << "Usage: " << argv[0] << " [processing-flags] [INPUT_FILE.png]\n";
    std::cout << "Flags:\n";
    std::cout << " -s       Simple Gradiant\n";
    std::cout << " -g       Grayscale\n";
    std::cout << " -p       Prewitt Gradiant Smoothing\n";
    std::cout << "\nNote: only one flag can be choosen at a time. Result goes to output.png\n";
    std::cout << std::endl;
    exit(-1);
}

int main(int argc, char** argv){
    if(argc != 3)
        help(argv);

    png::image<png::rgb_pixel> input(argv[2]);
    png::image<png::gray_pixel> result;
    std::string flag(argv[1]);

    if(flag == "-s")
        result = simple_gradiant(input);
    else if(flag == "-g")
        result = rgb_to_grayscale(input);
    else if (flag == "-p")
        result = prewitt_gradiant(input);
    else
        help(argv);

    result.write("output.png");
    std::cout << "wrote to output.png!\n";

    return 0;
}
