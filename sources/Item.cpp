//
// Created by horeanga on 02/11/2025.


#include "Item.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <algorithm>

int Item::totalItemsCreated = 0;

std::string rarityToString(RarityLevel r) {
    switch (r) {
        case RarityLevel::Common: return "Common";
        case RarityLevel::Uncommon: return "Uncommon";
        case RarityLevel::Rare: return "Rare";
        case RarityLevel::Epic: return "Epic";
        case RarityLevel::Legendary: return "Legendary";
    }
    return "Unknown";
}

Item::Item(const std::string& name_, RarityLevel rarity_) : name(name_), rarity(rarity_) {
    ++totalItemsCreated;
}

Item::Item(const Item& other) : name(other.name), rarity(other.rarity) {
    ++totalItemsCreated;
}

Item& Item::operator=(Item other) {
    std::swap(name, other.name);
    std::swap(rarity, other.rarity);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Item& it) {
    os << it.name << " (rarity: " << rarityToString(it.rarity) << ")";
    return os;
}


std::vector<Item> Item::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) throw FileReadException(filename);
    std::vector<Item> items;
    std::string line;
    int lineno = 0;
    while (std::getline(fin, line)) {
        ++lineno;
        std::istringstream iss(line);
        std::string name, rarityStr;
        if (!(iss >> name >> rarityStr)) {
            // skip empty or malformed lines but report format issues as DataFormatException
            throw DataFormatException("Malformed item line " + std::to_string(lineno) + " in " + filename);
        }
        // normalize
        std::transform(rarityStr.begin(), rarityStr.end(), rarityStr.begin(), ::tolower);
        RarityLevel r;
        if (rarityStr == "common") r = RarityLevel::Common;
        else if (rarityStr == "uncommon") r = RarityLevel::Uncommon;
        else if (rarityStr == "rare") r = RarityLevel::Rare;
        else if (rarityStr == "epic") r = RarityLevel::Epic;
        else if (rarityStr == "legendary") r = RarityLevel::Legendary;
        else throw DataFormatException("Unknown rarity '" + rarityStr + "' at line " + std::to_string(lineno));
        items.emplace_back(name, r);
    }
    return items;
}
