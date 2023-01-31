#include <iostream>
#include "../BakerySystem/BakerySystem.hpp"

int main() {
    std::cout << "I like trains\n";
    auto session = Session::getInstance();

    User usr = User("db.txt");

    if(usr.getUserFromDatabase("user", "12345")) {
        
    }

    return 0;
}