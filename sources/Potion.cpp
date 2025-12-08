//
// Created by horeanga on 02/11/2025.


#include "Potion.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

int Potion::totalPotionsLoaded = 0;
Potion::Potion(const std::string& name_, int potency_) : name(name_), potency(potency_) {
    // no throw here
}

Potion::Potion(const Potion& other) : name(other.name), potency(other.potency) {}
Potion& Potion::operator=(Potion other) {
    std::swap(name, other.name);
    std::swap(potency, other.potency);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Potion& p) {
    os << p.name << " (potency=" << p.potency << ")";
    return os;
}
// file format: name potency (space separated, potency integer)
std::vector<Potion> Potion::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) throw FileReadException(filename);
    std::vector<Potion> potions;
    std::string line;
    int lineno = 0;
    while (std::getline(fin, line)) {
        ++lineno;
        std::istringstream iss(line);
        std::string name;
        int pot;
        if (!(iss >> name >> pot)) throw DataFormatException("Malformed potion line " + std::to_string(lineno));
        potions.emplace_back(name, pot);
        ++totalPotionsLoaded;
    }
    return potions;
}