#ifndef MAMIFERO_H
#define MAMIFERO_H

#include "Animal.h"
#include <string>

class Mamifero : public Animal {
public:
    Mamifero(std::string nom, float p, int j)
        : Animal("Mamífero", nom, p, j) {}

    std::string DefinirClaseAnimalEres() override {
        return "Soy un mamífero llamado " + nombre;
    }
};

#endif // MAMIFERO_H
