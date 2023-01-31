#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include "password.hpp"

#include <fstream>
#include <map>
#include <memory>
#include <optional>


class User {
public:
    User(const std::string& databasePath) {
        db_.open(databasePath);
    }
    User getUserFromDatabase(const std::string& username, const std::string& password);
private :
    std::ifstream db_;
    std::shared_ptr<std::string> username_;
    std::shared_ptr<Password> password_;

    std::optional<std::string> getFromFile(const std::string& username);
};

User User::getUserFromDatabase(const std::string& username, const std::string& password) {
    *username_ = username;
    password_ = std::shared_ptr<Password>(new Password(password));
    auto pswd = getFromFile(username).value_or("");
    password_->pass(pswd);
}

std::optional<std::string> User::getFromFile(const std::string& username) {
    std::string line = "";
    while(std::getline(db_, line)) {
        if(line.substr(0, line.find_first_of('@') - 1) == username) {
            auto pswd = line.substr(line.find_first_of('@') + 1, line.size() - (line.find_first_of('@') + 1));
            return pswd;
        }
    }
    return std::nullopt;
}


#endif // LOGIN_HPP_