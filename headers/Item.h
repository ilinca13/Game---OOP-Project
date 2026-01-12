//
// Created by horeanga on 02/11/2025.
//


#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>
#include <iostream>
#include <vector>

enum class RarityLevel {
    Common = 1,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

std::string rarityToString(RarityLevel r);

class Item {

private:
    std::string name;
    RarityLevel rarity;
    static int totalItemsCreated;

public:

    explicit Item(const std::string& name = "Unknown", RarityLevel rarity = RarityLevel::Common);
    Item(const Item& other);
    Item& operator=(Item other);
    friend std::ostream& operator<<(std::ostream& os, const Item& it);
    const std::string& getName() const { return name; }
    RarityLevel getRarity() const { return rarity; }
    static std::vector<Item> loadFromFile(const std::string& filename);
    static int getTotalItemsCreated() { return totalItemsCreated; }
};

#endif // OOP_ITEM_H