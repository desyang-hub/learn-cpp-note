#pragma once

#include <memory>
#include <iostream>

namespace prototype
{

const size_t PROTORYPE_SIZE = 10;

enum ImageType {
    PNG_IMAGE,
    JPG_IMAGE
};

class Image
{
private:
    static Image* protoType_[PROTORYPE_SIZE];
    static int protoSlot_;

public:
    virtual Image* clone() = 0;
    virtual int getProtoType() const = 0;
    
public:
    Image() = default;
    virtual ~Image() = default;

    static void AddProtoType(Image* instance) {
        protoType_[protoSlot_++] = instance;
    }

    static Image* GetProtoTypeInstancePtr(int imgType) {
        for (int i = 0; i < protoSlot_; ++i) {
            if (protoType_[i]->getProtoType() == imgType) {
                return protoType_[i]->clone();
            }
        }

        return nullptr;
    }
};

    
} // namespace prototype
