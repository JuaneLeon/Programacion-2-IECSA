// Practica 02 - Programacion II
// Universidad Aeronautica de Queretaro
// Equipo: [Juan Eduardo Leon Granados]

#include <iostream>
#include <string>
#include "Persona.h"

int main() {
    Persona persona;
    std::string nombre;

    std::cout << "Ingrese un nombre: ";
    std::getline(std::cin, nombre);

    persona.setNombre(nombre);
    persona.decirNombre();

    return 0;
}
