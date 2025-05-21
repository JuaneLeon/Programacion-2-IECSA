#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <locale> // Para setlocale
#include <cstdlib> // Para system

using namespace std;

class Rectangulo {
private:
    // Coordenadas de las cuatro esquinas en orden: superior-izquierdo, superior-derecho, inferior-derecha, inferior-izquierda
    double x1, y1; // esquina superior-izquierda
    double x2, y2; // esquina superior-derecha
    double x3, y3; // esquina inferior-derecha
    double x4, y4; // esquina inferior-izquierda

    // Función para verificar si un punto está en el primer cuadrante y dentro de los límites
    bool puntoValido(double x, double y) {
        return (x >= 0 && x <= 20.0) && (y >= 0 && y <= 20.0);
    }

    // Función para verificar si las coordenadas forman un rectángulo
    bool esRectangulo(double x1, double y1, double x2, double y2,
                      double x3, double y3, double x4, double y4) {
        // Calculamos los puntos medios de las diagonales
        double midX1 = (x1 + x3) / 2.0;
        double midY1 = (y1 + y3) / 2.0;
        double midX2 = (x2 + x4) / 2.0;
        double midY2 = (y2 + y4) / 2.0;

        // Verificamos si los puntos medios coinciden (propiedad de rectángulo)
        if (abs(midX1 - midX2) > 0.0001 || abs(midY1 - midY2) > 0.0001) {
            return false;
        }

        // Verificamos lados paralelos
        // Lados horizontales deben tener la misma longitud en y
        if (abs((y1 - y2) - (y4 - y3)) > 0.0001) {
            return false;
        }

        // Lados verticales deben tener la misma longitud en x
        if (abs((x2 - x3) - (x1 - x4)) > 0.0001) {
            return false;
        }

        return true;
    }

public:
    // Constructor que llama a la función establecer
    Rectangulo(double x1, double y1, double x2, double y2,
               double x3, double y3, double x4, double y4) {
        establecer(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    // Función para establecer las coordenadas con validación
    void establecer(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4) {
        // Verificar que todos los puntos estén en el primer cuadrante y dentro de los límites
        if (!puntoValido(x1, y1) || !puntoValido(x2, y2) || 
            !puntoValido(x3, y3) || !puntoValido(x4, y4)) {
            throw invalid_argument("Todas las coordenadas deben estar en el primer cuadrante y no exceder 20.0");
        }

        // Verificar que las coordenadas formen un rectángulo
        if (!esRectangulo(x1, y1, x2, y2, x3, y3, x4, y4)) {
            throw invalid_argument("Las coordenadas proporcionadas no forman un rectángulo");
        }

        // Asignar las coordenadas
        this->x1 = x1; this->y1 = y1;
        this->x2 = x2; this->y2 = y2;
        this->x3 = x3; this->y3 = y3;
        this->x4 = x4; this->y4 = y4;
    }

    // Calcular el ancho (la dimensión menor)
    double calcularAncho() {
        double lado1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // lado superior
        double lado2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); // lado derecho
        
        return min(lado1, lado2);
    }

    // Calcular el largo (la dimensión mayor)
    double calcularLargo() {
        double lado1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // lado superior
        double lado2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); // lado derecho
        
        return max(lado1, lado2);
    }

    // Calcular el perímetro
    double calcularPerimetro() {
        return 2 * (calcularLargo() + calcularAncho());
    }

    // Calcular el área
    double calcularArea() {
        return calcularLargo() * calcularAncho();
    }
};

int main() {
    // Permite imprimir caracteres especiales (acentos) en consola
    setlocale(LC_ALL, "");

    try {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        std::wcout << L"Ingrese las coordenadas del rectángulo en el siguiente orden:" << std::endl;
        std::wcout << L"Esquina superior-izquierda (x1 y1): ";
        std::wcin >> x1 >> y1;
        std::wcout << L"Esquina superior-derecha (x2 y2): ";
        std::wcin >> x2 >> y2;
        std::wcout << L"Esquina inferior-derecha (x3 y3): ";
        std::wcin >> x3 >> y3;
        std::wcout << L"Esquina inferior-izquierda (x4 y4): ";
        std::wcin >> x4 >> y4;

        Rectangulo rect(x1, y1, x2, y2, x3, y3, x4, y4);

        std::wcout << L"Ancho: " << rect.calcularAncho() << std::endl;
        std::wcout << L"Largo: " << rect.calcularLargo() << std::endl;
        std::wcout << L"Perímetro: " << rect.calcularPerimetro() << std::endl;
        std::wcout << L"Área: " << rect.calcularArea() << std::endl;
    } catch (const invalid_argument& e) {
        std::wcerr << L"Error: " << e.what() << std::endl;
    }

    return 0;
}
