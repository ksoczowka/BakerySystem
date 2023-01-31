#include "../BakerySystem/BakerySystem.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

enum class ScreenEnum {
    Main = 0,
    AddProduct = 1,
    ListProduct = 2,
    RemoveProduct = 3,

    AddCookie = 11,
    AddCake = 12,

    Exit = 999
};
void mainScreen();
void addProductScreen();
void removeProductScreen();

ScreenEnum changeScreen(const short& n);

void listCookies(const std::vector<Cookies>& cookies);
void listCakes(const std::vector<Cake>& cakes);

void makeProducts(BakersManager& manager, short choise);

int main() {
    using SE = ScreenEnum;
    SE screen = SE::Main;

    auto session = Session::getInstance();
    // static login todo: login screen
    session->openDatabase("./db.txt");
    session->login("user", "12345");
    std::cout << "Logged in...\n";

    std::vector<Cookies> cookies;
    std::vector<Cake> cakes;

    std::shared_ptr<CookiesBaker> cookiesBaker = std::shared_ptr<CookiesBaker>(new CookiesBaker());
    std::shared_ptr<CakeBaker> cakeBaker = std::shared_ptr<CakeBaker>(new CakeBaker());

    BakersManager manager;

    while(screen != SE::Exit) {
        switch(screen) {
            short choise;
            case SE::Main:
                system("clear");
                mainScreen();
                std::cin >> choise;
                screen = changeScreen(choise);
            break;

            case SE::AddProduct:
                system("clear");
                addProductScreen();
                std::cin >> choise;
                choise += 10;
                screen = changeScreen(choise);
            break;

            case SE::AddCookie:
                system("clear");
                manager.setBaker(cookiesBaker);
                std::cout << "Which cookies do you wanna make:\n";
                std::cout << "1. Chocolate\n"
                          << "2. Hazelnuts\n"
                          << "3. Chocolate and hazelnuts\n"
                          << "4. Raspberries\n"
                          << "5. Carmel\n"
                          << "6. Deluxe\n";
                std::cout << "Your choise: ";
                std::cin >> choise;
                std::cout << "How many cookies do you want? ";
                size_t quantity;
                std::cin >> quantity;
                makeProducts(manager, choise);
                cookiesBaker->setQuantity(quantity);
                cookies.push_back(*cookiesBaker->getCookies().value());
                screen = SE::Main;
            break;

            case SE::AddCake:
                system("clear");
                manager.setBaker(cakeBaker);
                std::cout << "Which cake do you wanna make:\n";
                std::cout << "1. Chocolate\n"
                          << "2. Hazelnuts\n"
                          << "3. Chocolate and hazelnuts\n"
                          << "4. Raspberries\n"
                          << "5. Carmel\n"
                          << "6. Deluxe\n";
                std::cout << "Your choise: ";
                std::cin >> choise;
                std::cout << "How many floors you want? ";
                size_t floors;
                std::cin >> floors;
                makeProducts(manager, choise);
                cakeBaker->setFloors(floors);
                cakes.push_back(*cakeBaker->getCake().value());
                screen = SE::Main;
            break;

            case SE::ListProduct:
                system("clear");
                std::cout << "Cookies:\n";
                listCookies(cookies);
                std::cout << "Cakes:\n";
                listCakes(cakes);

                getchar(); getchar();
                screen = SE::Main;
            break;

            case SE::RemoveProduct:
                system("clear");
                screen = SE::Main;
            break;
        }
    }


    return 0;
}
void mainScreen() {
    std::cout << "What you want to do?\n";
    std::cout << "1 - Add product\n" 
              << "2 - List Products\n"
              << "3 - --Remove Product-- WIP\n"
              << "0 - Exit\n";
    std::cout << "Your choise: ";
}

void addProductScreen() {
    std::cout << "Which product do you want to add?\n";
    std::cout << "1 - Cookies\n"
              << "2 - Cake\n";
    std::cout << "Your choise: ";
}

ScreenEnum changeScreen(const short& n) {
    using SE = ScreenEnum;
    switch(n) {
        case 1:
            return SE::AddProduct;
        break;

            case 11:
                return SE::AddCookie;
            break;

            case 12:
                return SE::AddCake;
            break;

        case 2:
            return SE::ListProduct;
        break;

        case 3:
            return SE::RemoveProduct;
        break;

        case 0:
            return SE::Exit;
        break;

        default:
            return SE::Main;
        break;
    }
}

void listCookies(const std::vector<Cookies>& cookies) {
    int i = 1;
    for(const auto& cookie : cookies) {
        std::cout << i << " - Quantity: " << cookie.quantity_ << "\nIngredients:\n"; 
        for(const auto& ing : cookie.ingredients_) {
            std::cout << "- " << ing << '\n';
        }
        i++;
    }
}
void listCakes(const std::vector<Cake>& cakes) {
    int i = 1;
    for(const auto& cake : cakes) {
        std::cout << i << " - Floors: " << cake.floors_ << "\nIngredients:\n"; 
        for(const auto& ing : cake.ingredients_) {
            std::cout << "- " << ing << '\n';
        }
        i++;
    }
}

void makeProducts(BakersManager& manager, short choise) {
    switch(choise) {
        case 1:
            manager.makeChocolete();
        break;
        
        case 2:
            manager.makeHazelnuts();
        break;
        
        case 3:
            manager.makeChocoleteAndHazelnuts();
        break;

        case 4:
            manager.makeRaspberry();
        break;

        case 5:
            manager.makeCarmel();
        break;

        case 6:
            manager.makeDeluxe();
        break;
    }    
}
