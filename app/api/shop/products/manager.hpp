#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "bakers.hpp"

class BakersManager {
public:
    void setBaker(std::shared_ptr<Baker> baker);

    // no ingredients
    void makePlainCookies(size_t quantity);
    void makeChocoleteCookies(size_t quantity);
    void makeHazelnutsCookies(size_t quantity);
    void makeChocoleteAndHazelnutsCookies(size_t quantity);
    void makeRaspberryCookies(size_t quantity);
    void makeCarmelCookies(size_t quantity);
    // all ingredients
    void makeDeluxeCookies(size_t quantity);

    // no ingredients
    void makePlainCake(size_t floors);
    void makeChocoleteCake(size_t floors);
    void makeHazelnutsCake(size_t floors);
    void makeChocoleteAndHazelnutsCake(size_t floors);
    void makeRaspberryCake(size_t floors);
    void makeCarmelCake(size_t floors);
    // all ingredients
    void makeDeluxeCake(size_t floors);
private:
    std::shared_ptr<Baker> baker_;
};

#endif // MANAGER_HPP_