#ifndef SHOP_HPP_
#define SHOP_HPP_

#include <memory>

// note: singleton
class Session {
public:
    static std::shared_ptr<Session> getInstance();

    // Disables copy constructor and assign operator to prevent cloning of this object
    Session(Session& other) = delete;
    void operator=(const Session& other) = delete;
private:
    Session(){}
    static std::shared_ptr<Session> instance_;
};

#endif // SHOP_HPP_