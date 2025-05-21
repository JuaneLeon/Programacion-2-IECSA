#ifndef INSECTO_H
#define INSECTO_H

#include "Animal.h"
#include <string>

class Insecto : public Animal {
protected:
    bool vuela;

public:
    Insecto(std::string nom, float p, int j, bool v)
        : Animal("Insecto", nom, p, j), vuela(v) {}

    std::string DefinirClaseAnimalEres() override {
        return "Soy un insecto llamado " + nombre + " que " + 
               (vuela ? "puede volar" : "no puede volar");
    }

    // Método adicional para acceder al atributo específico
    bool getVuela() const { return vuela; }
};

#endif // INSECTO_H
