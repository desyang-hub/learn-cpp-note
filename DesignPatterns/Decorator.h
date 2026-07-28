#pragma once

#include <iostream>
#include <memory>

class Decorator
{
public:   
    virtual ~Decorator() = default;
    virtual bool verify() = 0;
};

class HttpInterceptor : public Decorator
{
private:
    std::shared_ptr<Decorator> decorator_;
public:
    HttpInterceptor(std::shared_ptr<Decorator> decorator) : decorator_(decorator) {

    }

    bool verify() override {
        std::cout << "http verify success" << std::endl;

        if (decorator_) {
            return decorator_->verify();
        }
        return true;
    }
};

class PasswordInterceptor : public Decorator
{
private:
    std::shared_ptr<Decorator> decorator_;
public:
    PasswordInterceptor(std::shared_ptr<Decorator> decorator) : decorator_(decorator) {
    }

    bool verify() override {
        std::cout << "Password verify success" << std::endl;

        if (decorator_) {
            return decorator_->verify();
        }
        return true;
    }
};

void decorator_demo();