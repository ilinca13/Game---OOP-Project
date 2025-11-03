//
// Created by horeanga on 02/11/2025.
//

#ifndef OOP_PLANT_H
#define OOP_PLANT_H

#include <string>
#include <iostream>
#include "Item.h"
#include "Potion.h"

// Enum class pentru stadiile de creștere ale plantei
enum class GrowthStage {
    Seed = 1, // sămânță
    Sprout = 2, // răsad
    Young = 3, // tânără
    Budding = 4, // înflorire inițială
    Flowering = 5, // înflorită
    Mature = 6 // matură
    };

// Clasa Plant reprezintă o plantă din grădină
class Plant {
private:
    std::string type; // ex: Carrot, Corn
    GrowthStage growthStage;
    int waterLevel;
    bool sick;

public:
    // Constructor cu parametri default
   explicit Plant(const std::string& type = "Unknown");
    // Constructor pentru planta bolnava
    Plant(const std::string& type, bool sick);

    // Copy constructor, operator= de copiere, destructor
    Plant(const Plant& other);
    Plant& operator=(const Plant& other);
    ~Plant();

    // Funcții netriviale
    void water(); // udă planta
    void grow(); // crește planta dacă are apă
    Item harvest(); // recoltează fructul dacă e matur
    void heal(const Potion& p);// vindecă planta dacă e bolnavă

    // Getters
    [[nodiscard]] bool isMature() const;
    [[nodiscard]] bool isDead() const;
    void setSick(bool state) {sick = state; }

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Plant& pl);
};

// Funcție pentru conversia GrowthStage în string (declarată aici, definită în cpp)
std::string growthStageToString(GrowthStage gs);
#endif //OOP_PLANT_H