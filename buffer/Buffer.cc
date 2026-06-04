#include "Buffer.h"

#include <cassert>

void Buffer::copyToBack(const std::string& msg) {
    std::copy(msg.begin(), msg.end(), store_.data() + writerIndex_);
    writerIndex_ += msg.size();
}

void Buffer::copyToBack(const char* buf, size_t len) {
    std::copy(buf, buf + len, store_.data() + writerIndex_);
    writerIndex_ += len;
}

void Buffer::copyToFront() {
    std::copy(store_.data() + readerIndex_, store_.data() + writerIndex_, store_.begin());
    writerIndex_ = readableBytes();
    readerIndex_ = 0;
}


Buffer::Buffer(size_t store_size) : readerIndex_(0), writerIndex_(0), store_(store_size) {
}


// 将prepareable_和readable光标向前移动
void Buffer::retrieve(size_t len) {
    assert(readerIndex_ + len <= writerIndex_);
    readerIndex_ += len;
}

// 移动并将长度为len的字符串返回
std::string Buffer::retrieveAsString(size_t len) {
    std::string bytes(store_.data() + readerIndex_, len);
    retrieve(len);
    return bytes;
}

void Buffer::retrieveAll() {
    readerIndex_ = 0;
    writerIndex_ = 0;
}

std::string Buffer::retrieveAllAsString() {
    std::string bytes = retrieveAsString(readableBytes());
    retrieveAll();
    return bytes;
}

// 将数据
void Buffer::append(const std::string& msg) {
    append(msg.c_str(), msg.size());
}

void Buffer::append(const char* buf, size_t len) {
    if (len == 0) return;

    // 1. 剩余空间足够写入
    if (store_.size() - writerIndex_ >= len) {
        copyToBack(buf, len);
    } else if(writableBytes() >= len) { // 2. 空间足够，需要前移prepareable
        copyToFront();
        copyToBack(buf, len);
    } else { // 3. 空间不足，前移后，先扩容继续将后半部分数据写入
        copyToFront();
        // 扩容
        store_.resize(readableBytes() + len);
        copyToBack(buf, len);
    }
}

size_t Buffer::readableBytes() const {
    return writerIndex_ - readerIndex_;
}

// 这里返回的是，writerIndex_ 右侧剩余可写空间
size_t Buffer::writableBytes() const {
    return store_.size() - readableBytes();
}

size_t Buffer::prependableBytes() const {
    return readerIndex_;
}