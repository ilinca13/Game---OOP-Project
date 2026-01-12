

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
#include "Decorator.h"
#include "Templates.h"

int main() {
try {

// Incarc items si potions

auto items = Item::loadFromFile("data/items.txt");
auto potions = Potion::loadFromFile("data/potions.txt");

std::cout << "Loaded " << items.size() << " items and " << potions.size() << " potions.\n";
for (const auto& p : potions) std::cout << " Potion: " << p << "\n";
for (const auto& it : items) std::cout << " Item: " << it << "\n";

Potion healing = potions.size() >= 1 ? potions[0] : Potion("Healing", 3);
Potion disinfect = potions.size() >= 2 ? potions[1] : Potion("Disinfect", 5);


// Creez containere

auto c1 = std::make_shared<Container>();
auto c2 = std::make_shared<Container>();
auto c3 = std::make_shared<Container>();
auto c4 = std::make_shared<Container>();

// Dezinfectez anumite containere
c1->disinfect();
// c2 ramane murdar
c3->disinfect();
c4->disinfect();

std::cout << "\n";

// Plantez seminte de la diferite plante in containerele dezinfectate
// --------------------------
c1->plantSeed(PlantFactory::createPlant("Carrot"));
c3->plantSeed(PlantFactory::createPlant("Pepper"));
c4->plantSeed(PlantFactory::createPlant("Corn"));
// Tomato este planta bolnava de la inceput
auto cTom = std::make_shared<Container>();
cTom->disinfect();
cTom->plantSeed(PlantFactory::createPlant("Tomato", true));


// Incarc containerele in gradina

Garden garden;
garden.addContainer(c1);
garden.addContainer(c2);
garden.addContainer(c3);
garden.addContainer(c4);
garden.addContainer(cTom);

std::cout << "\n--- Initial Garden State ---\n" << garden << "\n";


// Test: aplic de 2 ori consecutive pe aceeasi planta decoratorul FertilizedPlant

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


// Cicluri de crestere pentru a ca plantele sa atinga maturitatea

for (int cycle = 1; cycle <= 5; ++cycle) {
    std::cout << "\n--- Growth Simulation #" << cycle << " ---\n";

    // Ud plantele (fara cele din containere murdare)
    std::cout << "--- Watering plants ---\n";
    for (const auto& cont : garden.getContainers()) {
    if (cont->hasPlant()) cont->getPlant()->water();
        }
    doubleFertContainer->getPlant()->water(); // fertilized carrot

    // Simulez cresterea
    garden.simulateGrowth();
    doubleFertContainer->getPlant()->grow();

    // Vindec Tomato bolnava
    for (const auto& cont : garden.getContainers()) {
    if (!cont->hasPlant()) continue;
    auto p = cont->getPlant();
    auto tptr = std::dynamic_pointer_cast<TomatoPlant>(p);
    if (tptr && !tptr->isMature()) {
    p->setSick(false);
    std::cout << "Healed Tomato in container.\n";
        }
    }
}


// Cultiv plantele mature

std::cout << "\n--- Harvesting ---\n";
std::vector<std::shared_ptr<Container>> allContainers = garden.getContainers();
allContainers.push_back(doubleFertContainer); // includem planta fertilizata

int harvestedCount = 0;
for (const auto& cont : allContainers) {
if (!cont->hasPlant()) continue;
auto p = cont->getPlant();
if (p->isMature()) {
Item it = p->harvest();
std::cout << "Harvested: " << it << "\n";
harvestedCount++;
}
}
std::cout << "Total plants harvested: " << harvestedCount << "\n";


// Stats

std::cout << "\n--- Stats ---\n";
std::cout << "Total plants created: " << PlantBase::getTotalPlantsCreated() << "\n";
std::cout << "Total containers created: " << Container::getTotalContainers() << "\n";
std::cout << "Total potions loaded: " << Potion::getTotalPotionsLoaded() << "\n";
std::cout << "Total items loaded: " << Item::getTotalItemsCreated() << "\n";



    // Clasa template
    //1.Instantiere
    ColectieGenerica<Item> itemsCol("Items Colectie");
    for (const auto& it : items) itemsCol.add(it);

    //2.Instantiere
    ColectieGenerica<std::string> numePlanteCol("Nume Plante Colectie");
    for (const auto& c : garden.getContainers()) {
        if (c->hasPlant()) numePlanteCol.add(c->getPlant()->describe());
        else numePlanteCol.add("(empty container)");
    }


    std::cout << "\n=== Template Class Test ===\n";
    itemsCol.afiseaza();
    std::cout<<"\n";
    numePlanteCol.afiseaza();


    // Functie template

    std::cout << "\n=== Template Function Test ===\n";

    // 1.Instantiere
    std::vector<int> cresteriPlante = {1, 2, 3, 4, 5};
    afiseazaElemente(cresteriPlante, "Numar cresteri simulate");


    // 2.Instantiere
    std::vector<std::shared_ptr<Container>> toateContainerele = garden.getContainers();
    toateContainerele.push_back(doubleFertContainer);

    std::vector<std::string> planteDecorated;

    /*for (auto& c : garden.getContainers()) {
        if (c->hasPlant()) {
            auto p = c->getPlant();
            if (dynamic_cast<FertilizedPlant*>(p.get()))
                planteDecorated.push_back(p->describe() + " [Decorated]");
            else
                planteDecorated.push_back(p->describe() + " [Normal]");
        } else {
            planteDecorated.push_back("(empty container)");
        }
    }*/
    for (const auto& c : toateContainerele) {
        if (!c->hasPlant()) {
            planteDecorated.push_back("(empty container)");
            continue;
        }

        auto p = c->getPlant();

        if (dynamic_cast<FertilizedPlant*>(p.get()))
            planteDecorated.push_back("[Decorated]");
        else
            planteDecorated.push_back("[Normal]");
    }
    afiseazaElemente(planteDecorated, "Decorated status plante");


    // cppcheck

    for (const auto& it : items) {
        (void)it.getRarity();
    }

    for (const auto& p : potions) {
        (void)p.getPotency();
    }

    for (const auto& c : garden.getContainers()) {
        if (c->hasPlant()) {
            (void)c->getPlant()->isDead();
        }
    }
} catch (const GameException& ge) {
std::cerr << "Game error: " << ge.what() << "\n";
return 2;
} catch (const std::exception& ex) {
std::cerr << "Unexpected error: " << ex.what() << "\n";
return 3;
}

return 0;
}




