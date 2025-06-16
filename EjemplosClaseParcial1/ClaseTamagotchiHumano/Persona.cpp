#include "Persona.h"
#include <iostream>

Persona::Persona() {
    // Inicializar la semilla para n�meros aleatorios
    std::srand(std::time(0));
}

void Persona::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Persona::decirNombre() {
    // Paso 1: Recibir nombre (ya est� en el atributo)

    // Paso 2: Decir el nombre
    std::cout << "Mi nombre es: " << nombre << std::endl;

    // Paso 3: Generar n�mero aleatorio entre 20 y 120
    int num = 20 + (std::rand() % 101); // 20-120 inclusive

    // Paso 4: Evaluar condiciones
    if (num >= 20 && num <= 59) {
        dormir();
    } else if (num >= 60 && num <= 99) {
        hablar();
    } else {
        contar();
    }

    // Paso 5: Decir adi�s
    std::cout << "Adios!" << std::endl;
}

void Persona::dormir() const {
    std::cout << "Zzz... (durmiendo)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Persona::hablar() const {
    std::cout << "bla bla bla... (hablando)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Persona::contar() const {
    std::cout << "1, 2, 3... (contando)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
