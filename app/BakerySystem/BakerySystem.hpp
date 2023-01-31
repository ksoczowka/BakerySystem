#ifndef BAKERY_SYSTEM_HPP_
#define BAKERY_SYSTEM_HPP_

#include "./shop/shop.hpp"
#include "./login/user.hpp"

#include <fstream>

class Session {
public:
    static std::shared_ptr<Session> getInstance();

    bool login(const std::string& username, const std::string& password);
    bool openDatabase(const std::string& path);

    // Disables copy constructor and assign operator to prevent cloning this object
    Session(Session& other) = delete;
    void operator=(const Session& other) = delete;
private:
    Session() {}
    static std::shared_ptr<Session> instance_;

    std::shared_ptr<User> user_;
    std::ifstream db_;

    std::optional<std::string> findPasswordInDatabase_(const std::string& username);
};

std::shared_ptr<Session> Session::instance_ = nullptr;

std::shared_ptr<Session> Session::getInstance() {
    if(instance_== nullptr) {
        instance_ = std::shared_ptr<Session>(new Session());
    }
    return instance_;
}

bool Session::login(const std::string& username, const std::string& password) {
    if(!db_.is_open()) {
        return false;
    }
    user_ = std::shared_ptr<User>(new User(username, password));

    auto encrypted = findPasswordInDatabase_(username).value_or("");
    db_.close();
    if(user_->validateUser(encrypted)) {
        return true;
    }
    return false;
}

bool Session::openDatabase(const std::string& path) {
    db_.open(path);
    return db_.is_open();
}

std::optional<std::string> Session::findPasswordInDatabase_(const std::string& username) {
    auto separatorIterator = 0;
    std::string line = "";
    while(std::getline(db_, line)) {
        separatorIterator = line.find_first_of('@');
        if(line.substr(0, separatorIterator - 1) == username) {
            auto pswd = line.substr(separatorIterator + 1, line.size() - (separatorIterator + 1));
            return pswd;
        }
    }
    return std::nullopt;
}

#endif // BAKERY_SYSTEM_HPP_