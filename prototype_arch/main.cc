#include "image.h"
#include "pngImage.h"

#include <iostream>

using namespace std;
using namespace prototype;

int main() {

    Image* pngImage = Image::GetProtoTypeInstancePtr(PNG_IMAGE);

    if (pngImage) {
        delete pngImage;
    }
    else {
        cout << "Image type not support." << endl;
    }

    pngImage = Image::GetProtoTypeInstancePtr(JPG_IMAGE);

    if (pngImage) {
        delete pngImage;
    }
    else {
        cout << "Image type not support." << endl;
    }

    return 0;
}