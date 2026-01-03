#ifndef __IMAGE__
#define __IMAGE__

enum ImageType {
    Ldst,
    Spot
};

class Image {
public:
    virtual Image* clone() = 0;
    static void addPrototype(Image* imgType) {
        _prototypes[_next_slot++] = imgType;
    }

    virtual ImageType getPrototype() = 0;

    static Image* findAndClone(ImageType type) {
        for (int i = 0; i < _next_slot; i++) {
            if (_prototypes[i]->getPrototype() == type) {
                return _prototypes[i]->clone();
            }
        }
    }

private:
    static Image* _prototypes[10];
    static int _next_slot;
};

Image* Image::_prototypes[];
int Image::_next_slot;

#endif