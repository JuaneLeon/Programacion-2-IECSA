#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class Persona {
private:
    std::string nombre;

public:
    Persona();
    void decirNombre();
    void dormir() const;
    void hablar() const;
    void contar() const;
    void setNombre(const std::string& nuevoNombre);
};

#endif // PERSONA_H
