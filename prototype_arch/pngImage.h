#pragma once

#include "image.h"

namespace prototype
{

class PNGImage : public Image
{
private:
    static PNGImage pngImage;
public:
    Image* clone() override;
    int getProtoType() const override;

public:
    PNGImage() {
        AddProtoType(this);
    }
    ~PNGImage() = default;


    // 一般需要实现拷贝构造实现clone
    PNGImage(const PNGImage&);
};
    
} // namespace protorype
