//
// Created by horeanga on 11/01/2026.
//

#ifndef GAME_OOP_PROJECT_DECORATOR_H
#define GAME_OOP_PROJECT_DECORATOR_H

#include "PlantBase.h"
#include "Item.h"
#include <memory>


class PlantDecorator : public PlantBase {
protected:
    std::shared_ptr<PlantBase> wrapped;

public:
    explicit PlantDecorator(std::shared_ptr<PlantBase> plant);

    void water() override;
    void grow() override;
    std::string describe() const override;
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;

protected:
    void growImpl() override {}
    void printImpl(std::ostream& os) const override;
};


class FertilizedPlant : public PlantDecorator {
public:
    explicit FertilizedPlant(std::shared_ptr<PlantBase> plant);

    void grow() override;
    Item harvest() override;
};




#endif //GAME_OOP_PROJECT_DECORATOR_H