#include <iostream>
#include "Mamifero.h"
#include "Ave.h"
#include "Insecto.h"
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

void mostrarInformacionAnimal(Animal* animal) {
    std::cout << "\nInformación del animal:\n";
    std::cout << "------------------------\n";
    std::cout << animal->DefinirClaseAnimalEres() << "\n";
    std::cout << "Especie: " << animal->getEspecie() << "\n";
    std::cout << "Nombre: " << animal->getNombre() << "\n";
    std::cout << "Peso: " << animal->getPeso() << " kg\n";
    std::cout << "Jaula: " << animal->getJaula() << "\n";

    // Mostrar información específica según el tipo de animal
    if (Ave* ave = dynamic_cast<Ave*>(animal)) {
        std::cout << "Color de plumaje: " << ave->getColorPlumaje() << "\n";
        std::cout << "Altura máxima de vuelo: " << ave->getAlturaMaximaVuelo() << " metros\n";
    } 
    else if (Insecto* insecto = dynamic_cast<Insecto*>(animal)) {
        std::cout << "Puede volar: " << (insecto->getVuela() ? "Sí" : "No") << "\n";
    }
}

int main() {
    // Configuración para imprimir acentos y caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int opcion;
    std::string nombre, colorPlumaje;
    float peso, alturaMaximaVuelo;
    int jaula;
    bool vuela;
    char respuesta;

    do {
        std::cout << "Seleccione el tipo de animal:\n";
        std::cout << "1. Mamífero\n";
        std::cout << "2. Ave\n";
        std::cout << "3. Insecto\n";
        std::cout << "Opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        std::cout << "Ingrese el nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese el peso (kg): ";
        std::cin >> peso;
        std::cout << "Ingrese el número de jaula: ";
        std::cin >> jaula;

        Animal* animal = nullptr;

        if (opcion == 1) {
            animal = new Mamifero(nombre, peso, jaula);
        } else if (opcion == 2) {
            std::cin.ignore();
            std::cout << "Ingrese el color de plumaje: ";
            std::getline(std::cin, colorPlumaje);
            std::cout << "Ingrese la altura máxima de vuelo (metros): ";
            std::cin >> alturaMaximaVuelo;
            animal = new Ave(nombre, peso, jaula, colorPlumaje, alturaMaximaVuelo);
        } else if (opcion == 3) {
            char puedeVolar;
            std::cout << "¿Puede volar? (s/n): ";
            std::cin >> puedeVolar;
            vuela = (puedeVolar == 's' || puedeVolar == 'S');
            animal = new Insecto(nombre, peso, jaula, vuela);
        } else {
            std::cout << "Opción no válida.\n";
            continue;
        }

        mostrarInformacionAnimal(animal);
        delete animal;

        std::cout << "\n¿Desea ingresar otro animal? (s/n): ";
        std::cin >> respuesta;
        std::cin.ignore();
        std::cout << std::endl;
    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
