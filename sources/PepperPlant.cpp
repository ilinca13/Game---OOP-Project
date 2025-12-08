//
// Created by horeanga on 08/12/2025.
//
#include "PepperPlant.h"

#include <iostream>

PepperPlant::PepperPlant() : PlantBase("Pepper"), spiciness(1) {}

void PepperPlant::growImpl() {
    growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
    ++spiciness;
    std::cout << type << " grew to stage: " << growthStageToString(growthStage)
              << " (spiciness=" << spiciness << ")\n";
}

void PepperPlant::printImpl(std::ostream& os) const {
    os << " [spiciness=" << spiciness << "]";
}

Item PepperPlant::harvest() {
    if (isMature()) return Item(type + " Pepper", RarityLevel::Uncommon);
    return Item();
}

std::shared_ptr<PlantBase> PepperPlant::clone() const {

    return std::make_shared<PepperPlant>(*this);

}