#pragma once

#include <functional>
#include <vector>
#include <iostream>



class Observer
{
private:
    std::vector<std::function<void(Observer* observer)>> notifiers_;
public:
    // 通知所有的订阅者
    void Notify() {
        for (auto& item : notifiers_) {
            item(this);
        }
    }

    void subject(std::function<void(Observer* observer)> notify) {
        notifiers_.push_back(std::move(notify));
    }
};

using Notifier = std::function<void(Observer* observer)>;

void observer_demo();