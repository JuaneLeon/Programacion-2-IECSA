#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <locale> // Para setlocale
#include <cstdlib> // Para system

using namespace std;

class Rectangle {
private:
    double length = 1.0;  // Valor predeterminado 1
    double width = 1.0;   // Valor predeterminado 1

    // Función para validar las dimensiones
    bool dimensionValida(double valor) {
        return (valor >= 2.0 && valor <= 30.0);
    }

public:
    // Constructor por defecto (usa valores predeterminados)
    Rectangle() = default;

    // Constructor con parámetros
    Rectangle(double l, double w) {
        setLength(l);
        setWidth(w);
    }

    // Establecer longitud con validación
    void setLength(double l) {
        if (dimensionValida(l)) {
            length = l;
        } else {
            throw invalid_argument("La longitud debe estar entre 2.0 y 30.0");
        }
    }

    // Establecer ancho con validación
    void setWidth(double w) {
        if (dimensionValida(w)) {
            width = w;
        } else {
            throw invalid_argument("El ancho debe estar entre 2.0 y 30.0");
        }
    }

    // Obtener longitud
    double getLength() const {
        return length;
    }

    // Obtener ancho
    double getWidth() const {
        return width;
    }

    // Calcular perímetro
    double calcularPerimetro() const {
        return 2 * (length + width);
    }

    // Calcular área
    double calcularArea() const {
        return length * width;
    }
};

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    system("chcp 65001 > nul");

    cout << "Calculadora de Rectángulos" << endl;

    double l, w;
    cout << "Ingrese la longitud (entre 2.0 - 30.0): ";
    cin >> l;
    cout << "Ingrese el ancho (entre 2.0 - 30.0): ";
    cin >> w;

    try {
        Rectangle rect(l, w);
        cout << fixed << setprecision(2);
        cout << "Longitud: " << rect.getLength() << endl;
        cout << "Ancho: " << rect.getWidth() << endl;
        cout << "Perímetro: " << rect.calcularPerimetro() << endl;
        cout << "Área: " << rect.calcularArea() << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
