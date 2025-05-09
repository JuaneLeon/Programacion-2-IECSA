#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

class velAvion {
private:
    // Atributos
    string matriculaAvion;
    float posInicial, posFinal, tiempo;

public:
    // Métodos
    float velocidad() { // Definición de la función para el cálculo de la velocidad
        return (posFinal - posInicial) / tiempo;
    }

    bool valida(float posIni, float posFin, float tiem) {
        if (posIni <= 0 || posFin <= 0) {
            cout << "Los valores de posición deben de ser >0 \n";
            return true;
        }
        if (posFin <= posIni) {
            cout << "posFinal debe de ser > posInicial \n";
            return true;
        }
        if (tiem <= 0) {
            cout << "tiempo debe de ser > cero\n";
            return true;
        }
        return false;
    }

    void obtenerDatos() {
        string mat;
        float poIni, poFin, tpo;
        cout << "Escribe la matrícula del avión: ";
        cin >> mat;
        do {
            cout << "Escribe la posición inicial del avión(m): ";
            cin >> poIni;
            cout << "Escribe la posición final del avión(m): ";
            cin >> poFin;
            cout << "Escribe el tiempo transcurrido(seg): ";
            cin >> tpo;
        } while (valida(poIni, poFin, tpo));
        matriculaAvion = mat;
        posInicial = poIni;
        posFinal = poFin;
        tiempo = tpo;
    }

    void imprimeDatos() {
        cout << "\nEl avión con matrícula " << matriculaAvion << " lleva una velocidad de: " << velocidad() << " m/seg\n";
    }
}; // Fin de la clase velAvion ---

int main() {
    setlocale(LC_CTYPE, "Spanish");
    velAvion avion02;
    avion02.obtenerDatos();
    avion02.imprimeDatos();

    return 0;
}
