#ifndef PRODUCTS_HPP_
#define PRODUCTS_HPP_

#include <string>
#include <vector>

class Cookies {
public:
    std::vector<std::string> ingredients_;
    size_t quantity_;
};

class Cake {
public:
    std::vector<std::string> ingredients_;
    size_t floors_;
};

#endif // PRODUCTS_HPP_