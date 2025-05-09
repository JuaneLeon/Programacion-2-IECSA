#include <iostream>
#include <string>
using namespace std;

class velAvion {
private:
    string matriculaAvion; 
    float posInicial;      
    float posFinal;        
    float tiempo;          

public:
    velAvion(string matricula, float posIni, float posFin, float t) {
        matriculaAvion = matricula;
        posInicial = posIni;
        posFinal = posFin;
        tiempo = t;
    }

    float velocidad() {
        return (posFinal - posInicial) / tiempo;
    }

    bool valida() {
        return posInicial > 0 && posFinal > 0 && posFinal > posInicial;
    }

    void mostrarDatos() {
        if (valida()) {
            cout << "Matricula del avion: " << matriculaAvion << endl;
            cout << "Velocidad del avion: " << velocidad() << " m/s" << endl;
        } else {
            cout << "Datos invalidos. Verifique las posiciones." << endl;
        }
    }
};

int main() {
    string matricula;
    float posInicial, posFinal, tiempo;

    cout << "Ingrese la matricula del avion (6 caracteres): ";
    cin >> matricula;
    cout << "Ingrese la posicion inicial (m): ";
    cin >> posInicial;
    cout << "Ingrese la posicion final (m): ";
    cin >> posFinal;
    cout << "Ingrese el tiempo (seg): ";
    cin >> tiempo;

    velAvion avion(matricula, posInicial, posFinal, tiempo);
    avion.mostrarDatos();

    return 0;
}
