#include <gtest/gtest.h>

#include "../bakers.hpp"

// struct CookiesBakerTest {
//     std::shared_ptr<CookiesBaker> baker;
// };
// TEST_F(CookiesBakerTest, setQuantityThrowsExeceptionWhenSmallerThanOne) {
//     ASSERT_ANY_THROW(baker->setQuantity(0));
//     ASSERT_ANY_THROW(baker->setQuantity(-1));
// }
// TEST_F(CookiesBakerTest, setQuantityNotThrowsExceptionWhenOneOrBigger) {
//     ASSERT_NO_THROW(baker->setQuantity(1));
//     ASSERT_NO_THROW(baker->setQuantity(12));
// }