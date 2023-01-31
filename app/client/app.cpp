#include <iostream>
#include "../BakerySystem/BakerySystem.hpp"

int main() {
    std::cout << "I like trains\n";

    auto session = Session::getInstance();
    session->openDatabase("./db.txt");
    session->login("user", "12345");

    

    return 0;
}