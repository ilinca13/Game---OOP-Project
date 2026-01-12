//
// Created by horeanga on 08/12/2025.
//



#ifndef OOP_CARROTPLANT_H
#define OOP_CARROTPLANT_H

#include "PlantBase.h"

class CarrotPlant : public PlantBase {
private:
    int size;
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    CarrotPlant();
    CarrotPlant(const CarrotPlant& other) = default;
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};

#endif