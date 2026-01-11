//
// Created by horeanga on 11/01/2026.
//
#include "Decorator.h"
#include <iostream>


PlantDecorator::PlantDecorator(std::shared_ptr<PlantBase> plant)
: PlantBase(plant->getType()), wrapped(std::move(plant)) {}

void PlantDecorator::water() {
    wrapped->water();
}

void PlantDecorator::grow() {
    wrapped->grow();
}

std::string PlantDecorator::describe() const
{
    return wrapped->describe() + " [Decorated]";
}

Item PlantDecorator::harvest() {
    return wrapped->harvest();
}

std::shared_ptr<PlantBase> PlantDecorator::clone() const {
    return std::make_shared<PlantDecorator>(wrapped->clone());
}

void PlantDecorator::printImpl(std::ostream& os) const {
    os << describe(); //sa tin minte aici sa vad de ce dadea eroare membru inaccesibil wrapped->printImpl(os)
}


FertilizedPlant::FertilizedPlant(std::shared_ptr<PlantBase> plant)
: PlantDecorator(std::move(plant)) {}

void FertilizedPlant::grow() {
    wrapped->grow();
    wrapped->grow();
}

Item FertilizedPlant::harvest() {
    Item base = wrapped->harvest();
    return Item(base.getName(), RarityLevel::Epic);
}



