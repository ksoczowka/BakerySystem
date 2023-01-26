#ifndef BAKERS_HPP_
#define BAKERS_HPP_

#include "products.hpp"

#include <memory>

class Baker {
public:
    virtual ~Baker(){}
    virtual void reset() = 0;
    virtual void addChocolate() const = 0;
    virtual void addNuts() const = 0;
    virtual void addRaspberries() const = 0;
    virtual void addCarmel() const = 0;
};

class CookiesBaker : public Baker {
public: 
    CookiesBaker();
    ~CookiesBaker(){}

    void reset() override;

    void setQuantity(size_t quantity);

    void addChocolate() const override;
    void addNuts() const override;
    void addRaspberries() const override;
    void addCarmel() const override;

    std::shared_ptr<Cookies> getCookies();
private:
    std::shared_ptr<Cookies> cookies_;
};

class CakeBaker : public Baker {
public:
    CakeBaker();
    ~CakeBaker(){}

    void reset() override;

    void setFloors(size_t floors);
    
    void addChocolate() const override;
    void addNuts() const override;
    void addRaspberries() const override;
    void addCarmel() const override;

    std::shared_ptr<Cake> getCake();
private:
    std::shared_ptr<Cake> cake_;
};

#endif // BAKERS_HPP_