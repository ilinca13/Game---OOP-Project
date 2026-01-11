//
// Created by horeanga on 11/01/2026.
//

#ifndef GAME_OOP_PROJECT_FACTORY_H
#define GAME_OOP_PROJECT_FACTORY_H
#include <memory>
#include <string>
#include "PlantBase.h"
#include "CarrotPlant.h"
#include "CornPlant.h"
#include "TomatoPlant.h"
#include "PepperPlant.h"


class PlantFactory {
public:
    static std::shared_ptr<PlantBase> createPlant(const std::string& type, bool sick = false) {
        if (type == "Carrot") return std::make_shared<CarrotPlant>();
        else if (type == "Corn") return std::make_shared<CornPlant>();
        else if (type == "Tomato") return std::make_shared<TomatoPlant>(sick);
        else if (type == "Pepper") return std::make_shared<PepperPlant>();
        else return nullptr;
    }
};
#endif //GAME_OOP_PROJECT_FACTORY_H