#include "Strategy.h"

// 
void strategy_demo() {
    PaymentContext context(std::make_unique<AliPayment>("tb2014"));
    context.executePay(12);

    context.setPayment(std::make_unique<CreditPayment>("3607312000"));
    context.executePay(13);
}