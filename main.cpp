/*#include <iostream>
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
}*/

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
#include "Templates.h"

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
garden.addContainer(c2);
garden.addContainer(c3);
garden.addContainer(c4);
garden.addContainer(cTom);

std::cout << "\n--- Initial Garden State ---\n" << garden << "\n";

// --------------------------
// Double Fertilized Decorator Test
// --------------------------
std::cout << "\n=== Double Fertilized Decorator Test ===\n";
auto doubleFertContainer = std::make_shared<Container>();
doubleFertContainer->disinfect();

auto carrot = PlantFactory::createPlant("Carrot");
doubleFertContainer->plantSeed(carrot);

std::cout << "Watering carrot 4 times...\n";
for (int i = 0; i < 4; ++i)
doubleFertContainer->getPlant()->water();

std::cout << "Before decorators: " << *doubleFertContainer << "\n";

auto fert1 = std::make_shared<FertilizedPlant>(doubleFertContainer->getPlant());
doubleFertContainer->setPlant(fert1);
std::cout << "After first Fertilized: " << *doubleFertContainer << "\n";

auto fert2 = std::make_shared<FertilizedPlant>(doubleFertContainer->getPlant());
doubleFertContainer->setPlant(fert2);
std::cout << "After second Fertilized: " << *doubleFertContainer << "\n";

doubleFertContainer->getPlant()->grow();
std::cout << "After grow() with double Fertilized: " << *doubleFertContainer << "\n";

// --------------------------
// Growth cycles to reach maturity
// --------------------------
for (int cycle = 1; cycle <= 5; ++cycle) {
std::cout << "\n--- Growth Simulation #" << cycle << " ---\n";

// Water all plants (except dirty containers)
std::cout << "--- Watering plants ---\n";
for (auto& cont : garden.getContainers()) {
if (cont->hasPlant()) cont->getPlant()->water();
}
doubleFertContainer->getPlant()->water(); // fertilized carrot

// Simulate growth
garden.simulateGrowth();
doubleFertContainer->getPlant()->grow();

// Heal sick Tomato
for (auto& cont : garden.getContainers()) {
if (!cont->hasPlant()) continue;
auto p = cont->getPlant();
auto tptr = std::dynamic_pointer_cast<TomatoPlant>(p);
if (tptr && !tptr->isMature()) {
p->setSick(false);
std::cout << "Healed Tomato in container.\n";
}
}
}

// --------------------------
// Harvest mature plants
// --------------------------
std::cout << "\n--- Harvesting ---\n";
std::vector<std::shared_ptr<Container>> allContainers = garden.getContainers();
allContainers.push_back(doubleFertContainer); // includem planta fertilizata

int harvestedCount = 0;
for (auto& cont : allContainers) {
if (!cont->hasPlant()) continue;
auto p = cont->getPlant();
if (p->isMature()) {
Item it = p->harvest();
std::cout << "Harvested: " << it << "\n";
harvestedCount++;
}
}
std::cout << "Total plants harvested: " << harvestedCount << "\n";

// --------------------------
// Stats
// --------------------------
std::cout << "\n--- Stats ---\n";
std::cout << "Total plants created: " << PlantBase::getTotalPlantsCreated() << "\n";
std::cout << "Total containers created: " << Container::getTotalContainers() << "\n";
std::cout << "Total potions loaded: " << Potion::getTotalPotionsLoaded() << "\n";
std::cout << "Total items loaded: " << Item::getTotalItemsCreated() << "\n";

    // --------------------------
    // --------------------------
    // Template Class Instantiations
    // --------------------------
    ColectieGenerica<Item> itemsCol("Items Colectie");
    for (auto& it : items) itemsCol.add(it);

    ColectieGenerica<std::string> numePlanteCol("Nume Plante Colectie");
    for (auto& c : garden.getContainers()) {
        if (c->hasPlant()) numePlanteCol.add(c->getPlant()->describe());
        else numePlanteCol.add("(empty container)");
    }



    std::cout << "\n=== Template Class Test ===\n";
    itemsCol.afiseaza();
    std::cout<<"\n";
    numePlanteCol.afiseaza();

    // --------------------------
    // Template Function Instantiations
    // --------------------------
    std::cout << "\n=== Template Function Test ===\n";

    // Instanțiere #1: vector de int
    std::vector<int> cresteriPlante = {1, 2, 3, 4, 5};
    afiseazaElemente(cresteriPlante, "Numar cresteri simulate");


    // Instanțiere #2: vector de string, doar pentru a marca dacă planta e decorated
    std::vector<std::string> planteDecorated;
    for (auto& c : garden.getContainers()) {
        if (c->hasPlant()) {
            auto p = c->getPlant();
            if (dynamic_cast<FertilizedPlant*>(p.get()))
                planteDecorated.push_back(p->describe() + " [Decorated]");
            else
                planteDecorated.push_back(p->describe() + " [Normal]");
        } else {
            planteDecorated.push_back("(empty container)");
        }
    }
    afiseazaElemente(planteDecorated, "Decorated status plante");
} catch (const GameException& ge) {
std::cerr << "Game error: " << ge.what() << "\n";
return 2;
} catch (const std::exception& ex) {
std::cerr << "Unexpected error: " << ex.what() << "\n";
return 3;
}

return 0;
}



