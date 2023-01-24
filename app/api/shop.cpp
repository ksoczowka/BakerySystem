#include "shop.hpp"

std::shared_ptr<Session> Session::instance_ = nullptr;

std::shared_ptr<Session> Session::getInstance() {
    if(instance_== nullptr) {
        instance_ = std::shared_ptr<Session>(new Session());
    }
    return instance_;
}
