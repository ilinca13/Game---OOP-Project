
#include <iostream>
#include <vector>
#include "Item.h"
#include "Potion.h"
#include "Plant.h"
#include "Container.h"
#include "Garden.h"

int main() {
Potion healing("Healing", 3);
Potion disinfect("Disinfect", 5);

// Plante
Plant carrot("Carrot"); // va ajunge la Mature și va fi recoltat
Plant tomato("Tomato", true); // bolnavă de la început
Plant pepper("Pepper"); // va ajunge la Young
Plant corn("Corn"); // va ajunge la Budding

// Containere
Container c1, c2, c3, c4, c5;

c1.disinfect(disinfect);
c2.disinfect(disinfect);
c3.disinfect(disinfect);
c4.disinfect(disinfect);
// c5 rămâne murdar intenționat

// Plantez
c1.plantSeed(carrot);
c2.plantSeed(tomato);
c3.plantSeed(pepper);
c4.plantSeed(corn);
c5.plantSeed(Plant("Lettuce")); // nu va reuși

Garden garden;
garden.addContainer(c1);
garden.addContainer(c2);
garden.addContainer(c3);
garden.addContainer(c4);
garden.addContainer(c5);

std::cout << "\n--- Initial garden state ---\n";
std::cout << garden;

// Creștere fără udare
std::cout << "\n--- Growth simulation (no watering) ---\n";
garden.simulateGrowth();

    std::cout << "\n--- Watering ---\n";
// Ud plantele
c1.getPlant().water(); // Carrot
c2.getPlant().water(); // Tomato
c3.getPlant().water(); // Pepper
c4.getPlant().water(); // Corn

std::cout << "\n--- Growth simulation after watering ---\n";
garden.simulateGrowth();

// A doua rundă: creștere doar pentru Carrot și Corn
c1.getPlant().water();
c4.getPlant().water();
std::cout << "\n--- Second growth simulation ---\n";
garden.simulateGrowth();

// Pepper se îmbolnăvește acum
std::cout << "\n--- Infecting Pepper ---\n";
c3.getPlant().setSick(true);

// Încercăm creștere
std::cout << "\n--- Growth attempt after Pepper infection ---\n";
garden.simulateGrowth();

// Vindecăm Tomato
std::cout << "\n--- Healing Tomato ---\n";
c2.getPlant().heal(healing);

// Ud și continuăm creșterea până Carrot ajunge la Mature
for (int i = 0; i < 3; ++i) {
c1.getPlant().water(); // doar Carrot pentru a ajunge la Mature
std::cout << "\n--- Additional growth simulation ---\n";
garden.simulateGrowth();
}
    std::cout << "\n--- Watering ---\n";
    c4.getPlant().water();
    c2.getPlant().water();
    std::cout << "\n--- Additional growth simulation ---\n";
    garden.simulateGrowth();

// Recoltarea
std::cout << "\n--- Harvesting ---\n";
/*if (c1.hasPlantInContainer()) c1.getPlant().harvest(); // doar Carrot va fi Mature
if (c2.hasPlantInContainer()) c2.getPlant().harvest(); // Tomato nu e Mature
if (c3.hasPlantInContainer()) c3.getPlant().harvest(); // Pepper nu e Mature
if (c4.hasPlantInContainer()) c4.getPlant().harvest(); // Corn nu e Mature*/

    std::vector<Container*> containers = { &c1, &c2, &c3, &c4 };

    for (auto c : containers) {
        if (c->hasPlantInContainer()) {
            Item fruit = c->getPlant().harvest();
            std::cout << "Harvested item: " << fruit << "\n";
        }
    }

std::cout << "\n--- Final garden state ---\n";
std::cout << garden;

return 0;
}



