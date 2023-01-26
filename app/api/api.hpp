#pragma once

#include "shop/shop.hpp"
#include "shop/products/bakers.hpp"

#include <memory>

// note: singleton
class Session {
public:
    static std::shared_ptr<Session> getInstance();

    // Disables copy constructor and assign operator to prevent cloning of this object
    Session(Session& other) = delete;
    void operator=(const Session& other) = delete;
private:
    Session(){}
    static std::shared_ptr<Session> instance_;
};

std::shared_ptr<Session> Session::instance_ = nullptr;

std::shared_ptr<Session> Session::getInstance() {
    if(instance_== nullptr) {
        instance_ = std::shared_ptr<Session>(new Session());
    }
    return instance_;
}

