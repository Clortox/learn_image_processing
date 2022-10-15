///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Gradiant Vector defintions
//

#pragma once

#include <png++/png.hpp>
#include "math.h"

/**
 * Find the simple gradiant of the image. Only gets the gradiant based on the
 * neighboring vertical/horizontal pixels
 */
png::image<png::gray_pixel> simple_gradiant(png::image<png::rgb_pixel>&);
png::image<png::gray_pixel> rgb_to_grayscale(png::image<png::rgb_pixel>&);
png::image<png::gray_pixel> prewitt_gradiant(png::image<png::rgb_pixel>&);
png::image<png::gray_pixel> prewitt_gradiant(png::image<png::gray_pixel>&);

