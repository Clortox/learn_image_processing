///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 3-10-22
// Gradiant Vector defintions
//

#pragma once

#include <png++/png.hpp>

/**
 * Find the simple gradiant of the image. Only gets the gradiant based on the
 * neighboring vertical/horizontal pixels
 */
png::image<png::gray_pixel> simple_gradiant(png::image<png::rgb_pixel>&);

