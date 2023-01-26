#include "bakers.hpp"

#include <stdexcept>

// Cookies

CookiesBaker::CookiesBaker() {
    reset();
}

void CookiesBaker::reset() {
    cookies_ = std::shared_ptr<Cookies>(new Cookies());
}


std::shared_ptr<Cookies> CookiesBaker::getCookies() {
    auto result = cookies_;
    reset();
    return result;
}

void CookiesBaker::setQuantity(size_t quantity) {
    if(quantity == 0) {
        auto e = std::range_error("Quantity can't be lower that 1!\n");
        throw(e);
    } else {
        cookies_->quantity_ = quantity;
    }
}

void CookiesBaker::addChocolate() const {
    cookies_->ingredients_.push_back("Chocolate");
}
void CookiesBaker::addNuts() const {
    cookies_->ingredients_.push_back("Hazelnuts");
}
void CookiesBaker::addRaspberries() const {
    cookies_->ingredients_.push_back("Raspberries");
}
void CookiesBaker::addCarmel() const {
    cookies_->ingredients_.push_back("Carmel");
}

// Cake

CakeBaker::CakeBaker() {
    reset();
}

void CakeBaker::reset() {
    cake_ = std::shared_ptr<Cake>(new Cake());
}

void CakeBaker::setFloors(size_t floors) {
    if(floors < 1) {
        auto e = std::range_error("Floors can't be less that 1!\n");
        throw(e);
    } else {
        cake_->floors_ = floors;
    }
}

void CakeBaker::addChocolate() const {
    cake_->ingredients_.push_back("Chocolate");
}

void CakeBaker::addNuts() const {
    cake_->ingredients_.push_back("Hazelnuts");
}

void CakeBaker::addRaspberries() const {
    cake_->ingredients_.push_back("Raspberries");
}

void CakeBaker::addCarmel() const {
    cake_->ingredients_.push_back("Carmel");
}
