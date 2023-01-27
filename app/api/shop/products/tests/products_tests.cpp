#include <gtest/gtest.h>

#include "../bakers.hpp"

struct CookiesBakerTest : public testing::Test {
    CookiesBaker baker;
};
struct CakeBakerTest : public testing::Test {
    CakeBaker baker;
};

// Cookie
TEST_F(CookiesBakerTest, setQuantityThrowsExeceptionWhenZero) {
    
    ASSERT_ANY_THROW(baker.setQuantity(0));
}
TEST_F(CookiesBakerTest, setQuantityNotThrowsExceptionWhenOneOrBigger) {
    
    ASSERT_NO_THROW(baker.setQuantity(1));
    ASSERT_NO_THROW(baker.setQuantity(12));
}

// Cake
TEST_F(CakeBakerTest, setFloorsThrowsExeceptionWhenZero) {
    ASSERT_ANY_THROW(baker.setFloors(0));
}
TEST_F(CakeBakerTest, setFloorsNotThrowsExceptionWhenOneOrBigger) {
    ASSERT_NO_THROW(baker.setFloors(1));
    ASSERT_NO_THROW(baker.setFloors(12));
}
