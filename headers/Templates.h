//
// Created by horeanga on 11/01/2026.
//

#ifndef GAME_OOP_PROJECT_TEMPLATES_H
#define GAME_OOP_PROJECT_TEMPLATES_H
#include <vector>
#include <string>
#include <iostream>




// clasa template: ColectieGenerica

template <typename T>
class ColectieGenerica {
private:
    std::vector<T> elemente;
    std::string numeColectie;

public:
    explicit ColectieGenerica(const std::string& nume) : numeColectie(nume) {}

    void add(const T& element) { elemente.push_back(element); }

    T& operator[](int index) {
        if (index >= 0 && index < static_cast<int>(elemente.size()))
            return elemente[index];
        throw std::out_of_range("Index invalid in ColectieGenerica");
    }

    int size() const { return elemente.size(); }

    void afiseaza() const {
        std::cout << "=== Colectie: " << numeColectie << " ===\n";
        if (elemente.empty()) {
            std::cout << "(Goala)\n";
            return;
        }
        for (const auto& elem : elemente)
            std::cout << " -> " << elem << "\n";
    }
};


// functia template: afiseazaElemente

template <typename T>
void afiseazaElemente(const std::vector<T>& lista, const std::string& titlu) {
    std::cout << "\n>>> Lista: " << titlu << " <<<\n";
    if (lista.empty()) {
        std::cout << " - Niciun element -\n";
        return;
    }
    for (const auto& el : lista)
        std::cout << el << "\n";
}
#endif //GAME_OOP_PROJECT_TEMPLATES_H