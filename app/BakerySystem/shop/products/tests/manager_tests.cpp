#include <gtest/gtest.h>

#include "../manager.hpp"

TEST(BakersManagerTest, managerMakesChocolateThenDeluxeCookies) {
    // Create baker as shared pointer
    auto baker = std::shared_ptr<CookiesBaker>(new CookiesBaker());

    // Create and set up manager with baker to make cookies
    BakersManager manager;
    manager.setBaker(baker);

    // "Baking" process
    baker->setQuantity(1);
    manager.makeChocolete();

    // Chocolate cookies check
    auto cookiesIngredients = baker->getCookies().value()->ingredients_;
    std::vector<std::string> expected = { "Chocolate" };

    ASSERT_EQ(cookiesIngredients, expected);

    // note: CookieBaker is reseting after getCookies() method is called
    // "Baking" process
    baker->setQuantity(1);
    manager.makeDeluxe();

    // Deluxe cookies check
    expected = { "Chocolate", "Hazelnuts", "Raspberries", "Carmel"};
    cookiesIngredients = baker->getCookies().value()->ingredients_;

    ASSERT_EQ(cookiesIngredients, expected);
}

TEST(BakersManagerTest, managerMakesRaspberryThenCarmelCake) {
    // Create baker as shared pointer
    auto baker = std::shared_ptr<CakeBaker>(new CakeBaker());

    // Create and set up manager with baker to make cake
    BakersManager manager;
    manager.setBaker(baker);

    // "Baking" process
    baker->setFloors(1);
    manager.makeRaspberry();

    // Raspberry cake check
    auto cakeIngredients = baker->getCake().value()->ingredients_;
    std::vector<std::string> expected = { "Raspberry" };

    ASSERT_EQ(cakeIngredients, expected);

    // note: CakeBaker is reseting after getCake() method is called
    // "Baking" process
    baker->setFloors(1);
    manager.makeCarmel();

    // Carmel cake check
    expected = { "Carmel" };
    cakeIngredients = baker->getCake().value()->ingredients_;

    ASSERT_EQ(cakeIngredients, expected);
}