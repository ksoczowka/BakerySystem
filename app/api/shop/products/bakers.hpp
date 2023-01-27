#ifndef BAKERS_HPP_
#define BAKERS_HPP_

#include "products.hpp"

#include <memory>
#include <optional>
#include <stdexcept>

class Baker {
public:
    virtual ~Baker(){}
    virtual void addChocolate() const = 0;
    virtual void addNuts() const = 0;
    virtual void addRaspberries() const = 0;
    virtual void addCarmel() const = 0;
};

class CookiesBaker : public Baker {
public: 
    CookiesBaker() {
        reset();
    }
    ~CookiesBaker(){}

    void reset() {
        cookies_ = std::shared_ptr<Cookies>(new Cookies());
        cookies_->quantity_ = 0;
    }

    void setQuantity(size_t quantity) {
        if(quantity == 0) {
            auto e = std::range_error("Quantity can't be lower that 1!\n");
            throw(e);
        } else {
            cookies_->quantity_ = quantity;
        }
    }

    void addChocolate() const override {
        cookies_->ingredients_.push_back("Chocolate");
    }
    void addNuts() const override {
        cookies_->ingredients_.push_back("Hazelnuts");
    }
    void addRaspberries() const override {
        cookies_->ingredients_.push_back("Raspberries");
    }
    void addCarmel() const override {
        cookies_->ingredients_.push_back("Carmel");
    }

    std::optional<std::shared_ptr<Cookies>> getCookies() {
        if(cookies_->quantity_ != 0) {
            auto result = cookies_;
            reset();
            return result;
        }
        return std::nullopt;
    }
private:
    std::shared_ptr<Cookies> cookies_;
};

class CakeBaker : public Baker {
public:
    CakeBaker() {
        reset();
    }
    ~CakeBaker(){}

    void reset() {
        cake_ = std::shared_ptr<Cake>(new Cake());
        cake_->floors_ = 0;
    }

    void setFloors(size_t floors) {
        if(floors < 1) {
            auto e = std::range_error("Floors can't be less that 1!\n");
            throw(e);
        } else {
            cake_->floors_ = floors;
        }
    }
    
    void addChocolate() const override {
        cake_->ingredients_.push_back("Chocolate");
    }
    void addNuts() const override {
        cake_->ingredients_.push_back("Hazelnuts");
    }
    void addRaspberries() const override {
        cake_->ingredients_.push_back("Raspberry");
    }
    void addCarmel() const override {
        cake_->ingredients_.push_back("Carmel");
    }

    std::optional<std::shared_ptr<Cake>> getCake() {
        if(cake_->floors_ != 0) {
            auto result = cake_;
            reset();
            return result;
        }
        return std::nullopt;
    }
private:
    std::shared_ptr<Cake> cake_;
};

#endif // BAKERS_HPP_