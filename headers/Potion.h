//
// Created by horeanga on 02/11/2025.
//



#ifndef OOP_POTION_H
#define OOP_POTION_H

#include <string>
#include <iostream>
#include <vector>

class Potion {
private:
    std::string name;
    int potency; // how strong
    static int totalPotionsLoaded;

public:
    explicit Potion(const std::string& name = "Basic", int potency = 1);
    Potion(const Potion& other);
    Potion& operator=(Potion other);
    const std::string& getName() const { return name; }
    int getPotency() const { return potency; }
    friend std::ostream& operator<<(std::ostream& os, const Potion& p);
    static std::vector<Potion> loadFromFile(const std::string& filename); // may throw FileReadException/DataFormatException
    static int getTotalPotionsLoaded() { return totalPotionsLoaded; }
};

#endif // OOP_POTION_H