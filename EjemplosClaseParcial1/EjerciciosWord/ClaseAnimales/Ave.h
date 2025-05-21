#ifndef AVE_H
#define AVE_H

#include "Animal.h"
#include <string>

class Ave : public Animal {
protected:
    std::string colorPlumaje;
    float alturaMaximaVuelo;

public:
    Ave(std::string nom, float p, int j, std::string color, float altura)
        : Animal("Ave", nom, p, j), colorPlumaje(color), alturaMaximaVuelo(altura) {}

    std::string DefinirClaseAnimalEres() override {
        return "Soy un ave llamada " + nombre + " con plumaje " + colorPlumaje;
    }

    // Métodos adicionales para acceder a los atributos específicos
    std::string getColorPlumaje() const { return colorPlumaje; }
    float getAlturaMaximaVuelo() const { return alturaMaximaVuelo; }
};

#endif // AVE_H
