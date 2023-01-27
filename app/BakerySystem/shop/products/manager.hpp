#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "bakers.hpp"

class BakersManager {
public:
    void setBaker(std::shared_ptr<Baker> baker) {
        baker_ = baker;
    }

    void makeChocolete() {
        baker_->addChocolate();
    }
    void makeHazelnuts() {
        baker_->addNuts();
    }
    void makeChocoleteAndHazelnuts() {
        baker_->addChocolate();
        baker_->addNuts();
    }
    void makeRaspberry() {
        baker_->addRaspberries();
    }
    void makeCarmel() {
        baker_->addCarmel();
    }
    // all ingredients
    void makeDeluxe() {
        baker_->addChocolate();
        baker_->addNuts();
        baker_->addRaspberries();
        baker_->addCarmel();
    }
private:
    std::shared_ptr<Baker> baker_;
};

#endif // MANAGER_HPP_