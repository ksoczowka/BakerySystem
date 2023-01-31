#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include "password.hpp"

#include <memory>

class User {
public:
    User();
    User(const std::string& username, const std::string& password);
    bool validateUser(const std::string& encryptedPassword);

    void operator=(const User& other);
private :
    std::shared_ptr<std::string> username_;
    std::shared_ptr<Password> password_;
};

User::User() : username_(nullptr), password_(nullptr) {}

User::User(const std::string& username, const std::string& password) {
    username_ = std::shared_ptr<std::string>(new std::string(username));
    password_ = std::shared_ptr<Password>(new Password(password));
}

void User::operator=(const User& other) {
    username_ = other.username_;
    password_ = other.password_;
}

bool User::validateUser(const std::string& encryptedPassword) {
    if(username_ == nullptr || password_ == nullptr) {
        return false;
    }
    auto decrypted = password_->decryptPassword(encryptedPassword);
    if(decrypted == password_->getPassword()) {
        return true;
    }
    return false;
}

#endif // LOGIN_HPP_