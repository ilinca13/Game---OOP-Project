//
// Created by horeanga on 08/12/2025.
//

#include "CarrotPlant.h"

#include <iostream>

CarrotPlant::CarrotPlant() : PlantBase("Carrot"), size(1) {}
void CarrotPlant::growImpl() {
    // advance growth stage by one
    growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
    ++size;
    std::cout << type << " grew to stage: " << growthStageToString(growthStage) << " (size=" << size << ")\n";
}

void CarrotPlant::printImpl(std::ostream& os) const {
    os << " [size=" << size << "]";
}

Item CarrotPlant::harvest() {
    if (isMature()) return Item(type + " Fruit", RarityLevel::Common);
    return Item();
}

std::shared_ptr<PlantBase> CarrotPlant::clone() const {
    return std::make_shared<CarrotPlant>(*this);
}