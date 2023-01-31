#include <iostream>
#include "../BakerySystem/BakerySystem.hpp"

int main() {
    std::cout << "I like trains\n";

    auto session = Session::getInstance();

    session->openDatabase("db.txt");
    if(session->login("user", "12345")) {
        std::cout << "Logged in...\n";
    }

    return 0;
}