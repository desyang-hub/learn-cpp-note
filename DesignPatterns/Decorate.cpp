#include "Decorator.h"

void decorator_demo() {
    auto dec = std::make_shared<HttpInterceptor>(nullptr);
    auto pass_dec = std::make_shared<PasswordInterceptor>(dec);
    pass_dec->verify();
}