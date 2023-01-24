#ifndef PRODUCTS_HPP_
#define PRODUCTS_HPP_

#include <string>

class Price {
public:
    using u_sh = unsigned short;
    Price(u_sh beforeComma, u_sh afterComma) : beforeComma_(beforeComma), afterComma_(afterComma) {}
private:
    u_sh beforeComma_;
    u_sh afterComma_;
};

class Product {
public:
    std::string name_;
    Price price_;
    unsigned short quantity_;
};

#endif // PRODUCTS_HPP_