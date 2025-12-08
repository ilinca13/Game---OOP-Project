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
#include "Item.h" // harvest returns Item

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
    // static counter
    static int totalPlantsCreated;
    explicit PlantBase(const std::string& type_ = "Unknown");
    PlantBase(const PlantBase& other);
    PlantBase& operator=(const PlantBase& other);
    // virtuals (NVI pattern: public grow() will call growImpl)
    virtual void growImpl() = 0;
    virtual void printImpl(std::ostream& os) const = 0;

public:
    virtual ~PlantBase() = default;
    void water();
    void grow();
    bool isMature() const;
    bool isDead() const;
    void setSick(bool state);
    virtual Item harvest() = 0; // theme-specific function (pure virtual)
    virtual std::shared_ptr<PlantBase> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const PlantBase& plant);
    // static accessor
    static int getTotalPlantsCreated() { return totalPlantsCreated; }
};
#endif // OOP_PLANTBASE_H