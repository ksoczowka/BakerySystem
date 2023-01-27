#include <gtest/gtest.h>

#include "../bakers.hpp"

TEST(CookiesBakerTest, setQuantityThrowsExeceptionWhenSmallerThanOne) {
    CookiesBaker baker;
    
    ASSERT_ANY_THROW(baker.setQuantity(0));
    ASSERT_ANY_THROW(baker.setQuantity(-1));
}
TEST(CookiesBakerTest, setQuantityNotThrowsExceptionWhenOneOrBigger) {
    CookiesBaker baker;
    
    ASSERT_NO_THROW(baker.setQuantity(1));
    ASSERT_NO_THROW(baker.setQuantity(12));
}