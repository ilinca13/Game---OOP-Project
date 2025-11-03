//
// Created by horeanga on 02/11/2025.
#include "Plant.h"

// Funcție pentru conversia GrowthStage în string
std::string growthStageToString(GrowthStage gs) {
switch (gs) {
case GrowthStage::Seed: return "Seed";
case GrowthStage::Sprout: return "Sprout";
case GrowthStage::Young: return "Young";
case GrowthStage::Budding: return "Budding";
case GrowthStage::Flowering: return "Flowering";
case GrowthStage::Mature: return "Mature";
}
return "Unknown";
}

// Constructor
Plant::Plant(const std::string& type_)
: type{type_}, growthStage{GrowthStage::Seed}, waterLevel{0}, sick{false} {}
Plant::Plant(const std::string& type_, bool sick_)
    :type{type_}, growthStage{GrowthStage::Seed},  waterLevel{0}, sick{sick_} {}

// Copy constructor
Plant::Plant(const Plant& other)
: type{other.type}, growthStage{other.growthStage}, waterLevel{other.waterLevel}, sick{other.sick} {}

// Operator= de copiere
Plant& Plant::operator=(const Plant& other) {
if (this != &other) {
type = other.type;
growthStage = other.growthStage;
waterLevel = other.waterLevel;
sick = other.sick;
}
return *this;
}

// Destructor
Plant::~Plant() {
// Nu avem resurse dinamice aici, dar e pregătit pentru extensii viitoare
}

// Udă planta
void Plant::water() {
waterLevel += 1;
std::cout << type << " watered. Water level: " << waterLevel << "\n";
}

// Crește planta dacă are apă
void Plant::grow() {
if (sick) {
std::cout << type << " is sick and cannot grow.\n";
return;
}

if (waterLevel > 0 && growthStage != GrowthStage::Mature) {
growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
waterLevel -= 1;
std::cout << type << " grew to stage: " << growthStageToString(growthStage) << "\n";
} else if (growthStage == GrowthStage::Mature) {
std::cout << type << " is already mature.\n";
} else {
std::cout << type << " needs water to grow.\n";
}
}

// Recoltează fructul dacă planta e matură
Item Plant::harvest() {
if (growthStage == GrowthStage::Mature && !sick) {
std::cout << type << " harvested successfully!\n";
return Item(type + " Fruit", RarityLevel::Common);
} else {
std::cout << type << " is not ready for harvest.\n";
return Item();
}
}

// Vindecă planta cu o poțiune
void Plant::heal(const Potion& p) {
if (sick) {
sick = false;
std::cout << type << " has been healed using " << p.getName() << "\n";
} else {
std::cout << type << " is healthy, no need to heal.\n";
}
}

// Verifică dacă planta e matură
bool Plant::isMature() const {
return growthStage == GrowthStage::Mature;
}

// Verifică dacă planta e moartă
bool Plant::isDead() const {
return sick && waterLevel == 0; // exemplu simplificat
}

// Operator<< pentru afișare
std::ostream& operator<<(std::ostream& os, const Plant& pl) {
os << "Plant(" << pl.type << ", Stage: " << growthStageToString(pl.growthStage)
<< ", Water: " << pl.waterLevel << ", Sick: " << (pl.sick ? "Yes" : "No") << ")";
return os;
}