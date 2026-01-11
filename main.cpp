#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Item.h"
#include "Potion.h"
#include "Container.h"
#include "Garden.h"
#include "Factory.h"
#include "Exceptions.h"
#include "Decorator.h" // Fertilized, RareHarvest

int main() {
try {
// --------------------------
// Load items and potions
// --------------------------
auto items = Item::loadFromFile("data/items.txt");
auto potions = Potion::loadFromFile("data/potions.txt");

std::cout << "Loaded " << items.size() << " items and " << potions.size() << " potions.\n";
for (const auto& p : potions) std::cout << " Potion: " << p << "\n";
for (const auto& it : items) std::cout << " Item: " << it << "\n";

Potion healing = potions.size() >= 1 ? potions[0] : Potion("Healing", 3);
Potion disinfect = potions.size() >= 2 ? potions[1] : Potion("Disinfect", 5);

// --------------------------
// Create containers
// --------------------------
auto c1 = std::make_shared<Container>();
auto c2 = std::make_shared<Container>();
auto c3 = std::make_shared<Container>();
auto c4 = std::make_shared<Container>();

// Disinfect some containers
c1->disinfect();
// c2 remains dirty intentionally
c3->disinfect();
c4->disinfect();

// --------------------------
// Plant seeds
// --------------------------
//

    c1->plantSeed(PlantFactory::createPlant("Carrot"));
    c3->plantSeed(PlantFactory::createPlant("Pepper"));
    c4->plantSeed(PlantFactory::createPlant("Corn"));
// Tomato sick plant
auto cTom = std::make_shared<Container>();
cTom->disinfect();
    cTom->plantSeed(PlantFactory::createPlant("Tomato", true));

// --------------------------
// Garden
// --------------------------
Garden garden;
garden.addContainer(c1);
garden.addContainer(c2); // dirty, empty
garden.addContainer(c3);
garden.addContainer(c4);
garden.addContainer(cTom);

std::cout << "\n--- Initial Garden State ---\n" << garden << "\n";

    /*// --- Mini-test Fertilized Decorator ---
    std::cout << "\n=== Fertilized Decorator Test ===\n";

    auto testContainer = std::make_shared<Container>();
    testContainer->disinfect();

    // Cream morcov
    auto testCarrot = std::make_shared<CarrotPlant>();
    testContainer->plantSeed(testCarrot);

    // Udam planta de 3 ori
    std::cout << "Watering carrot 3 times...\n";
    testContainer->getPlant()->water();
    testContainer->getPlant()->water();
    testContainer->getPlant()->water();

    // Afisam stadiul initial
    std::cout << "Before applying Fertilized: " << *testContainer << "\n";

    // Aplicam decoratorul
    auto fertCarrot = std::make_shared<FertilizedPlant>(testContainer->getPlant());
    testContainer->setPlant(fertCarrot);

    // Afisam stadiul dupa decorator
    std::cout << "After applying Fertilized: " << *testContainer << "\n";

    // Apelam grow (decoratorul va creste de doua ori)
    testContainer->getPlant()->grow();

    // Afisam stadiul final
    std::cout << "After grow() with Fertilized: " << *testContainer << "\n";*/

    // --- Test: Două decoratori Fertilized peste morcov ---
    std::cout << "\n=== Double Fertilized Decorator Test ===\n";

    auto doubleFertContainer = std::make_shared<Container>();
    doubleFertContainer->disinfect();

    // 1. Cream morcov
    auto carrot = PlantFactory::createPlant("Carrot");
    doubleFertContainer->plantSeed(carrot);

    // 2. Udam planta de 4 ori pentru waterLevel suficient
    std::cout << "Watering carrot 4 times...\n";
    for (int i = 0; i < 4; ++i)
        doubleFertContainer->getPlant()->water();

    // Afisam stadiul initial
    std::cout << "Before decorators: " << *doubleFertContainer << "\n";

    // 3. Aplicam primul Fertilized decorator
    auto fert1 = std::make_shared<FertilizedPlant>(doubleFertContainer->getPlant());
    doubleFertContainer->setPlant(fert1);
    std::cout << "After first Fertilized: " << *doubleFertContainer << "\n";

    // 4. Aplicam al doilea Fertilized decorator peste primul
    auto fert2 = std::make_shared<FertilizedPlant>(doubleFertContainer->getPlant());
    doubleFertContainer->setPlant(fert2);
    std::cout << "After second Fertilized: " << *doubleFertContainer << "\n";

    // 5. Apelam grow; fiecare Fertilized crește de două ori => total 4 creșteri
    doubleFertContainer->getPlant()->grow();

    // 6. Afisam stadiul final
    std::cout << "After grow() with double Fertilized: " << *doubleFertContainer << "\n";
// --------------------------
// Test Decorators
// --------------------------
/*std::cout << "\n--- Testing Fertilized Decorator ---\n";
auto fertCarrot = std::make_shared<FertilizedPlant>(c1->getPlant());
c1->setPlant(fertCarrot);
std::cout << "Before growth: " << *c1 << "\n";
c1->getPlant()->grow(); // crește de 2 ori
std::cout << "After growth (Fertilized): " << *c1 << "\n";

std::cout << "\n--- Testing RareHarvest Decorator ---\n";
auto rareCarrot = std::make_shared<RareHarvestPlant>(c1->getPlant());
c1->setPlant(rareCarrot);
Item hiItem = c1->getPlant()->harvest();
std::cout << "Harvested: " << hiItem << "\n"; // raritate Epic*/

// --------------------------
// Simulate general growth
// --------------------------
std::cout << "\n--- Growth Simulation #1 (no watering) ---\n";
garden.simulateGrowth();

std::cout << "\n--- Watering plants ---\n";
for (auto& cont : garden.getContainers()) {
if (cont->hasPlant()) cont->getPlant()->water();
}

std::cout << "\n--- Growth Simulation #2 ---\n";
garden.simulateGrowth();

// Heal sick Tomato
std::cout << "\n--- Healing sick plants ---\n";
for (auto& cont : garden.getContainers()) {
if (!cont->hasPlant()) continue;
auto p = cont->getPlant();
auto tptr = std::dynamic_pointer_cast<TomatoPlant>(p);
if (tptr && !tptr->isMature()) {
p->setSick(false);
std::cout << "Healed Tomato in container.\n";
}
}

// Water again
std::cout << "\n--- Watering again ---\n";
for (auto& cont : garden.getContainers()) {
if (cont->hasPlant()) cont->getPlant()->water();
}

std::cout << "\n--- Growth Simulation #3 ---\n";
garden.simulateGrowth();

// Harvest mature plants
std::cout << "\n--- Harvesting ---\n";
for (auto& cont : garden.getContainers()) {
if (!cont->hasPlant()) continue;
auto p = cont->getPlant();
if (p->isMature()) {
Item it = p->harvest();
std::cout << "Harvested: " << it << "\n";
}
}

// --------------------------
// Stats
// --------------------------
std::cout << "\n--- Stats ---\n";
std::cout << "Total plants created: " << PlantBase::getTotalPlantsCreated() << "\n";
std::cout << "Total containers created: " << Container::getTotalContainers() << "\n";
std::cout << "Total potions loaded: " << Potion::getTotalPotionsLoaded() << "\n";
std::cout << "Total items loaded: " << Item::getTotalItemsCreated() << "\n";

} catch (const GameException& ge) {
std::cerr << "Game error: " << ge.what() << "\n";
return 2;
} catch (const std::exception& ex) {
std::cerr << "Unexpected error: " << ex.what() << "\n";
return 3;
}

return 0;
}



