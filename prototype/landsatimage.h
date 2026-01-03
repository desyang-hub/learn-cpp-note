#ifndef __LANDSATIMAGE__
#define __LANDSATIMAGE__

#include "image.h"

class LandsatImage : public Image {
public:
    Image* clone() override {
        return new LandsatImage(1);
    }

    ImageType getPrototype() override {
        return ImageType::Ldst;
    }

private:
    static LandsatImage landsatImage;

    LandsatImage() {
        addPrototype(this);
    }

protected:
    LandsatImage(int dummy) {

    }
};

LandsatImage LandsatImage::landsatImage;

#endif