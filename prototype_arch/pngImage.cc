#include "pngImage.h"

#include <iostream>

namespace prototype
{
PNGImage PNGImage::pngImage = PNGImage();

Image* PNGImage::clone() {
    std::cout << "PNGImage::" << __FUNCTION__ << std::endl;
    return new PNGImage(*this);
}
int PNGImage::getProtoType() const {
    return PNG_IMAGE;
}

PNGImage::PNGImage(const PNGImage& img) {
    // unimplement any behavery
}

}