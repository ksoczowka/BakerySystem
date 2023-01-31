#ifndef PASSWORD_HPP_
#define PASSWORD_HPP_

#include <array>
#include <optional>
#include <regex>
#include <string>

class Password {
public:
    Password() {}
    Password(const std::string& decrypted) : password_(decrypted) {}

    std::string getPassword() { return password_; }

    bool isValidPassword(const std::string& password);
    std::optional<std::string> decryptPassword(const std::string& password);
private:
    std::string password_{};
    const static size_t size_ = 5;
    const std::regex passwordValidationRegex_ = std::regex("[a-zA-Z0-9]{5}");

    std::array<short, size_> encryptedToAsciiCodes(const std::string& password);
};

bool Password::isValidPassword(const std::string& password) {
    if(password.size() != size_) {
        return false;
    }
    if(!std::regex_match(password, passwordValidationRegex_)) {
        return false;
    }
    return true;
}

std::optional<std::string> Password::decryptPassword(const std::string& password) {
    auto asciiCodes = encryptedToAsciiCodes(password);
    std::string result = "";

    for(const auto& code : asciiCodes) {
        result += (char)code;
    }
    if(isValidPassword(result)) {
        return result;
    }
    return std::nullopt;
}

std::array<short, Password::size_> Password::encryptedToAsciiCodes(const std::string& password) {
    std::array<short, size_> result;
    std::string buff = "";
    auto it = 0;
    for(const auto& el : password) {
        if(el == '-' || el == '/') {
            result.at(it) = std::stoi(buff);
            it++;
            buff = "";
            if(el == '/') {
                break;
            }   
            continue;
        }
        buff += el;
    }
    return result;
}

#endif //PASSWORD_HPP_