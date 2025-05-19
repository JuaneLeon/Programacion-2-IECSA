#include <string.h>
#include<iostream>
#include <locale.h>
#include <fcntl.h>
#include <io.h>
using namespace std;

class CuentaAhorros {
    private:
        float saldoAhorro;
        float tasaInteresAnual;

    public:

        CuentaAhorros() {
            wcout << L"Introduce el saldo de la cuenta de ahorro: ";
            cin >> saldoAhorro;
          
            do {

                wcout << L"Introduce la tasa de interés anual (entre 0 y 100%): ";
                cin >> tasaInteresAnual;
                if(tasaInteresAnual < 0 || tasaInteresAnual > 100) {
                    wcout << L"La tasa de interés debe estar entre 0 y 100%" << endl;
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
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U8TEXT);
    wcout << L"Datos para ahorrador1:" << endl;
    CuentaAhorros ahorrador1;
    wcout << L"Datos para ahorrador2:" << endl;
    CuentaAhorros ahorrador2;
    wcout << L"Interés mensual ahorrador1: " << ahorrador1.calcularInteresMensual() << endl;
    wcout << L"Interés mensual ahorrador2: " << ahorrador2.calcularInteresMensual() << endl;
    return 0;
}
