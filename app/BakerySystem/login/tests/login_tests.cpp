#include <gtest/gtest.h>

#include "../login.hpp"

#include <memory>

struct PasswordTest : public ::testing::Test {
    std::shared_ptr<Password> password = std::shared_ptr<Password>(new Password());
};
TEST_F(PasswordTest, IsValidPasswordShouldReturnTrue) {
    EXPECT_TRUE(password->isValidPassword("12345"));
    EXPECT_TRUE(password->isValidPassword("qwert"));
    EXPECT_TRUE(password->isValidPassword("qwe12"));
    EXPECT_TRUE(password->isValidPassword("Q1w2E"));
}
TEST_F(PasswordTest, IsValidPasswordShouldReturnFalse) {
    EXPECT_FALSE(password->isValidPassword("1245"));
    EXPECT_FALSE(password->isValidPassword("qw3ert"));
    EXPECT_FALSE(password->isValidPassword("qwe@12"));
    EXPECT_FALSE(password->isValidPassword("Q12 E"));
}