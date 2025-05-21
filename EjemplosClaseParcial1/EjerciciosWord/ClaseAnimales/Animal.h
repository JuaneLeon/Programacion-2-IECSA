#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string especie;
    std::string nombre;
    float peso;
    int jaula;

public:
    Animal(std::string esp, std::string nom, float p, int j)
        : especie(esp), nombre(nom), peso(p), jaula(j) {}

    virtual ~Animal() {}

    // Método virtual puro (clase abstracta)
    virtual std::string DefinirClaseAnimalEres() = 0;

    // Métodos para acceder a los atributos
    std::string getEspecie() const { return especie; }
    std::string getNombre() const { return nombre; }
    float getPeso() const { return peso; }
    int getJaula() const { return jaula; }
};

#endif // ANIMAL_H
