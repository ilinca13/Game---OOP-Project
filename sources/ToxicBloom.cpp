//
// Created by horeanga on 08/12/2025.
//

#include "ToxicBloom.h"

#include <iostream>

ToxicBloom::ToxicBloom() : PlantBase("ToxicBloom"), toxicity(5) { sick = true; }
ToxicBloom::ToxicBloom(bool startSick) : PlantBase("ToxicBloom"), toxicity(5) { sick = startSick; }

void ToxicBloom::growImpl() {
    growthStage = static_cast<GrowthStage>(static_cast<int>(growthStage) + 1);
    ++toxicity;
    std::cout << type << " grew to stage: " << growthStageToString(growthStage)
              << " (toxicity=" << toxicity << ")\n";
}

void ToxicBloom::printImpl(std::ostream& os) const {
    os << " [toxicity=" << toxicity << "]";
}

Item ToxicBloom::harvest() {
    if (isMature()) return Item(type + " Spores", RarityLevel::Rare);
    return Item();
}

std::shared_ptr<PlantBase> ToxicBloom::clone() const {
    return std::make_shared<ToxicBloom>(*this);
}