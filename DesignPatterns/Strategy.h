#pragma once

#include <memory>
#include <string>
#include <iostream>

class Payment {
public:
    virtual void pay(float) = 0;
};

class PaymentContext {
private:
    std::unique_ptr<Payment> payment_;
public:
    PaymentContext(std::unique_ptr<Payment> payment) : payment_(std::move(payment)) {

    }

    void setPayment(std::unique_ptr<Payment> payment) {
        payment_ = std::move(payment);
    }

    void executePay(float p) {
        payment_->pay(p);
    }
};

class AliPayment : public Payment {
private:
    std::string account_;
public:
    void pay(float p) {
        std::cout << "Alipay Account: " << account_ << " pay " << p << std::endl;
    }

    AliPayment(const std::string& account) : account_(account) {

    }
};

class CreditPayment : public Payment {
private:
    std::string account_;

public:
    void pay(float p) {
        std::cout << "CreditPay Account: " << account_ << " pay " << p << std::endl;
    }

    CreditPayment(const std::string& account) : account_(account) {

    }
};

void strategy_demo();