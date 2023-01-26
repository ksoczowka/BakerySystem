#include <iostream>
#include "../api/api.hpp"

int main() {
    std::cout << "I like trains\n";
    auto session = Session::getInstance();

    std::shared_ptr<CookiesBaker> baker = std::shared_ptr<CookiesBaker>(new CookiesBaker());

    baker->addChocolate();
    baker->setQuantity(4);
    auto cookies = baker->getCookies();

    return 0;
}