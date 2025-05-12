#include <iostream>
using namespace std;

class Complejo {
private:
    float parteRealNum1;
    float parteRealNum2;
    float parteImagNum1;
    float parteImagNum2;

public:
    // Constructor
    Complejo(float real1, float real2, float imag1, float imag2) {
        parteRealNum1 = real1;
        parteRealNum2 = real2;
        parteImagNum1 = imag1;
        parteImagNum2 = imag2;
    }

    // Método para capturar datos
    void capturarDatos() {
        parteRealNum1 = leerNumero("Ingrese la parte real del numero 1 (-125 a 125): ", -125, 125);
        parteImagNum1 = leerNumero("Ingrese la parte imaginaria del numero 1 (-150 a 175): ", -150, 175);
        parteRealNum2 = leerNumero("Ingrese la parte real del numero 2 (-125 a 125): ", -125, 125);
        parteImagNum2 = leerNumero("Ingrese la parte imaginaria del numero 2 (-150 a 175): ", -150, 175);
    }

    void suma() {
        float sumaReal = parteRealNum1 + parteRealNum2;
        float sumaImag = parteImagNum1 + parteImagNum2;
        cout << "Resultado de la suma: ";
        imprimirComplejo(sumaReal, sumaImag);
    }

    void resta() {
        float restaReal = parteRealNum1 - parteRealNum2;
        float restaImag = parteImagNum1 - parteImagNum2;
        cout << "Resultado de la resta: ";
        imprimirComplejo(restaReal, restaImag);
    }

    void imprimirComplejo(float real, float imag) {
        cout << "(" << real << ", " << imag << "i)\n";
    }

    static float leerNumero(string mensaje, float minimo, float maximo) {
        float valor;
        do {
            cout << mensaje;
            cin >> valor;
            if (valor < minimo || valor > maximo) {
                cout << "El valor no esta dentro del rango, vuelve a ingresarn uno nuevo.\n";
            }
        } while (valor < minimo || valor > maximo);
        return valor;
    }
};

int main() {

    Complejo c(0, 0, 0, 0);

    c.capturarDatos();
    c.suma();
    c.resta();

    return 0;
}
