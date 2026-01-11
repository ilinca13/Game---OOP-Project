//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_PLANTBASE_H
#define GAME_OOP_PROJECT_PLANTBASE_H

#endif //GAME_OOP_PROJECT_PLANTBASE_H*/
#ifndef OOP_PLANTBASE_H
#define OOP_PLANTBASE_H

#include <iostream>
#include <memory>
#include <string>
#include "Item.h"

enum class GrowthStage {
    Seed = 1,
    Sprout,
    Young,
    Budding,
    Flowering,
    Mature
};

std::string growthStageToString(GrowthStage gs);

class PlantBase {
protected:
    std::string type;
    GrowthStage growthStage;
    int waterLevel;
    bool sick;
    static int totalPlantsCreated;
    explicit PlantBase(const std::string& type_ = "Unknown");
    PlantBase(const PlantBase& other);
    PlantBase& operator=(const PlantBase& other);
    virtual void growImpl() = 0;
    virtual void printImpl(std::ostream& os) const = 0;

public:
    virtual ~PlantBase() = default;
    const std::string& getType() const {return type;}
    virtual void water();
    virtual void grow();
    bool isMature() const;
    bool isDead() const;
    void setSick(bool state);
    virtual Item harvest() = 0;
    virtual std::shared_ptr<PlantBase> clone() const = 0;
    virtual std::string describe() const {
        return type + " (Stage: " + growthStageToString(growthStage)
        + ", Water: " + std::to_string(waterLevel)
        + ", Sick: " + (sick ? "Yes" : "No") + ")";
    }
    friend std::ostream& operator<<(std::ostream& os, const PlantBase& plant);

    static int getTotalPlantsCreated() { return totalPlantsCreated; }
};
#endif // OOP_PLANTBASE_H