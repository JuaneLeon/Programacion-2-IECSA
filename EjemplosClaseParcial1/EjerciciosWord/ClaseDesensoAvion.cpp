#include <iostream>
using namespace std;

class Descenso {
private:
    float disDes;    
    float altAct;    
    float altDes;    
    float tazDes;    
    float velSuelo;  

public:
    void entradaDatos() {
        cout << "Ingrese la altitud actual (en pies): ";
        cin >> altAct;
        cout << "Ingrese la altitud deseada (en pies): ";
        cin >> altDes;
        cout << "Ingrese la velocidad respecto al suelo en nudos (kts): ";
        cin >> velSuelo;
    }

    void calculoDisDescenso() {
        disDes = (altAct - altDes) * 3;
    }

    void calculoTazaDes() {
        tazDes = (velSuelo / 2) * 10;
    }

    void mostrarResultados() {
        cout << "Distancia al punto de inicio de descenso: " << disDes << " millas" << endl;
        cout << "Tasa de descenso: " << tazDes << " en pies/min" << endl;
    }
};

int main() {
    Descenso avion;

    avion.entradaDatos();
    avion.calculoDisDescenso();
    avion.calculoTazaDes();
    avion.mostrarResultados();

    return 0;
}
