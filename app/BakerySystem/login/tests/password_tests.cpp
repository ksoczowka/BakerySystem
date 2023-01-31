#include <gtest/gtest.h>

#include "../password.hpp"


struct PasswordTest : public ::testing::Test {
    std::shared_ptr<Password> password = std::shared_ptr<Password>(new Password());
};

// isValidPassword()
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

// decryptPassword()
TEST_F(PasswordTest, decryptPasswordShouldReturn12345asString) {
    std::string toDecrypt = "49-50-51-52-53/";

    std::string expected = "12345";
    // Checks if EXPECTED value is valid password
    ASSERT_TRUE(password->isValidPassword(expected));

    EXPECT_EQ(password->decryptPassword(toDecrypt), expected);
}
