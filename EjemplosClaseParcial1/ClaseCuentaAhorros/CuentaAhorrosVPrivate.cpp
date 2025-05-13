#include <string.h>
#include<iostream>
using namespace std;

class CuentaAhorros {
    private:
        float saldoAhorro;
        float tasaInteresAnual;

    public:

        CuentaAhorros() {
            cout << "Introduce el saldo de la cuenta de ahorro: ";
            cin >> saldoAhorro;
          
            do {

                cout << "Introduce la tasa de interés anual (entre 0 y 100%): ";
                cin >> tasaInteresAnual;
                if(tasaInteresAnual < 0 || tasaInteresAnual > 100) {
                    cout << "La tasa de interés debe estar entre 0 y 100%" << endl;
                }

            } while(tasaInteresAnual < 0 || tasaInteresAnual > 100);
        }

        float calcularInteresMensual() {
            float interesMensual = (saldoAhorro * tasaInteresAnual) / 1200;
            saldoAhorro += interesMensual;
            return interesMensual;
        }
};

int main() {
    cout << "Datos para ahorrador1:" << endl;
    CuentaAhorros ahorrador1;
    cout << "Datos para ahorrador2:" << endl;
    CuentaAhorros ahorrador2;
    cout << "Interés mensual ahorrador1: " << ahorrador1.calcularInteresMensual() << endl;
    cout << "Interés mensual ahorrador2: " << ahorrador2.calcularInteresMensual() << endl;
    return 0;
}
