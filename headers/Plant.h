//
// Created by horeanga on 02/11/2025.
//

#ifndef OOP_PLANT_H
#define OOP_PLANT_H

#include <string>
#include <iostream>
#include "Item.h"
#include "Potion.h"


enum class GrowthStage {
    Seed = 1,
    Sprout = 2,
    Young = 3,
    Budding = 4,
    Flowering = 5,
    Mature = 6
    };


class Plant {
private:
    std::string type;
    GrowthStage growthStage;
    int waterLevel;
    bool sick;

public:

   explicit Plant(const std::string& type = "Unknown");

    Plant(const std::string& type, bool sick);


    Plant(const Plant& other);
    Plant& operator=(const Plant& other);
    ~Plant();


    void water();
    void grow();
    Item harvest();
    void heal(const Potion& p);


    [[nodiscard]] bool isMature() const;
    [[nodiscard]] bool isDead() const;
    void setSick(bool state) {sick = state; }


    friend std::ostream& operator<<(std::ostream& os, const Plant& pl);
};


std::string growthStageToString(GrowthStage gs);
#endif //OOP_PLANT_H