#include <gtest/gtest.h>

#include "../bakers.hpp"

TEST(CookiesBakerTest, setQuantityThrowsExeceptionWhenZero) {
    CookiesBaker baker;
    
    ASSERT_ANY_THROW(baker.setQuantity(0));
}
TEST(CookiesBakerTest, setQuantityNotThrowsExceptionWhenOneOrBigger) {
    CookiesBaker baker;
    
    ASSERT_NO_THROW(baker.setQuantity(1));
    ASSERT_NO_THROW(baker.setQuantity(12));
}