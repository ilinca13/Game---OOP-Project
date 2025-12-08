//
// Created by horeanga on 08/12/2025.
//
#include "TomatoPlant.h"

#include <iostream>

TomatoPlant::TomatoPlant() : PlantBase("Tomato"), ripeness(1) {}
TomatoPlant::TomatoPlant(bool startSick) : PlantBase("Tomato"), ripeness(1) { sick = startSick; }

void TomatoPlant::growImpl() {
    growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
    ++ripeness;
    std::cout << type << " grew to stage: " << growthStageToString(growthStage)
              << " (ripeness=" << ripeness << ")\n";
}

void TomatoPlant::printImpl(std::ostream& os) const {
    os << " [ripeness=" << ripeness << "]";
}

Item TomatoPlant::harvest() {
    if (isMature()) return Item(type + " Fruit", RarityLevel::Uncommon);
    return Item();
}

std::shared_ptr<PlantBase> TomatoPlant::clone() const {
    return std::make_shared<TomatoPlant>(*this);
}