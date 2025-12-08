//
// Created by horeanga on 08/12/2025.
//
#include "CornPlant.h"

#include <iostream>

CornPlant::CornPlant() : PlantBase("Corn"), height(10) {}

void CornPlant::growImpl() {
    growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
    height += 5;
    std::cout << type << " grew to stage: " << growthStageToString(growthStage)
              << " (height=" << height << "cm)\n";
}

void CornPlant::printImpl(std::ostream& os) const {
    os << " [height=" << height << "cm]";
}



Item CornPlant::harvest() {
    if (isMature()) return Item(type + " Cob", RarityLevel::Rare);
    return Item();
}
std::shared_ptr<PlantBase> CornPlant::clone() const {
    return std::make_shared<CornPlant>(*this);
}