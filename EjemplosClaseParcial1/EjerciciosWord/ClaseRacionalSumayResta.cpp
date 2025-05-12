#include <iostream>
#include <stdexcept> 
#include <limits>    

class Racional {
private:
    int numerador;
    int denominador;

public:

    Racional(int num = 1, int den = 1) : numerador(num), denominador(den) {
        if (denominador == 0) {
            throw std::runtime_error("El denominador no puede ser cero.");
        }
        reducirFraccion();
    }


    void sumar(const Racional& otra) {
        numerador = numerador * otra.denominador + otra.numerador * denominador;
        denominador *= otra.denominador;
        reducirFraccion();
    }

    void restar(const Racional& otra) {
        numerador = numerador * otra.denominador - otra.numerador * denominador;
        denominador *= otra.denominador;
        reducirFraccion();
    }

    void imprimirFraccion() const {
        std::cout << numerador << "/" << denominador;
    }

    void imprimirDecimal() const {
        double resultado = static_cast<double>(numerador) / denominador;
        std::cout << resultado;
    }


private:
    
    void reducirFraccion() {
        int gcd = calcularMCD(numerador, denominador);
        numerador /= gcd;
        denominador /= gcd;
    }

    
    int calcularMCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    char opcion;
    do {
        std::cout << "Seleccione una operacion:\n";
        std::cout << "a) Suma\n";
        std::cout << "b) Resta\n";
        std::cout << "c) Salir\n";
        std::cout << "Opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese una opcion valida.\n";
            continue;
        }

        if (opcion == 'a' || opcion == 'b') {
            int num1, den1, num2, den2;

            std::cout << "Ingrese la primera fraccion (num1/den1) No escribir / : ";
            if (!(std::cin >> num1 >> den1) || den1 == 0) {
                std::cout << "Ingrese valores numericos validos y un denominador no nulo.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Ingrese la segunda fraccion (num2/den2): ";
            if (!(std::cin >> num2 >> den2) || den2 == 0) {
                std::cout << "Ingrese valores numericos validos y un denominador no nulo.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            Racional fraccion1(num1, den1);
            Racional fraccion2(num2, den2);

            try {
                if (opcion == 'a') {
                    fraccion1.sumar(fraccion2);
                    std::cout << "Resultado de la suma: ";
                } else {
                    fraccion1.restar(fraccion2);
                    std::cout << "Resultado de la resta: ";
                }

                fraccion1.imprimirFraccion();
                std::cout << " o ";
                fraccion1.imprimirDecimal();
                std::cout << std::endl;

            } catch (const std::runtime_error& e) {
                std::cout << "" << e.what() << std::endl;
            }
        }

    } while (opcion != 'c');

    return 0;
}
