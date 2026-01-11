//
// Created by horeanga on 08/12/2025.
//
#include "PlantBase.h"

int PlantBase::totalPlantsCreated = 0;
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

PlantBase::PlantBase(const std::string& type_) : type(type_), growthStage(GrowthStage::Seed), waterLevel(0), sick(false) {
    ++totalPlantsCreated;
}

PlantBase::PlantBase(const PlantBase& other)
    : type(other.type), growthStage(other.growthStage), waterLevel(other.waterLevel), sick(other.sick) {
    ++totalPlantsCreated;
}

PlantBase& PlantBase::operator=(const PlantBase& other) {
    if (this != &other) {
        type = other.type;
        growthStage = other.growthStage;
        waterLevel = other.waterLevel;
        sick = other.sick;
    }
    return *this;
}

void PlantBase::water() { ++waterLevel; }
void PlantBase::grow() {
    if (sick) {
        std::cout << type << " is sick and cannot grow.\n";
        return;
    }
    if (waterLevel > 0 && growthStage != GrowthStage::Mature) {
        --waterLevel;
        growImpl();
    } else if (growthStage == GrowthStage::Mature) {
        std::cout << type << " is already mature.\n";
    } else {
        std::cout << type << " needs water to grow.\n";
    }
}

bool PlantBase::isMature() const { return growthStage == GrowthStage::Mature; }
bool PlantBase::isDead() const { return sick && waterLevel == 0; }
void PlantBase::setSick(bool state) { sick = state; }
std::ostream& operator<<(std::ostream& os, const PlantBase& plant) {
    os << plant.describe(); // in loc de plant.printImpl()
    return os;
}