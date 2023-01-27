#include <iostream>
#include "../BakerySystem/BakerySystem.hpp"

int main() {
    std::cout << "I like trains\n";
    auto session = Session::getInstance();

    std::shared_ptr<CookiesBaker> baker = std::shared_ptr<CookiesBaker>(new CookiesBaker());

    baker->addChocolate();
    baker->addCarmel();
    baker->setQuantity(4);
    auto cookies = baker->getCookies().value();

    std::cout << "Cookies: " << cookies->quantity_ << ":\n";
    for(const auto& ing : cookies->ingredients_) {
        std::cout << "- " << ing << '\n';
    }

    return 0;
}