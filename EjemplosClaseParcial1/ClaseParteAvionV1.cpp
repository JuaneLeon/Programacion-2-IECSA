#include <string.h>
#include <iostream>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class Parte {
public:
    int clave;
    char nomParte[40];
    float vidaUtil, TiempoUso, TiempoRest;

    void CargarInformacion() {
        char nopart[40];
        cout << "Escribe la clave de la parte: ";
        cin >> clave;
        cin.ignore(); 
        cout << "Escribe el nombre de la parte: ";
        cin.getline(nopart, 40); 
        do {
            cout << "Escribe la vida útil (máximo 10 años): ";
            cin >> vidaUtil;
            cout << "Escribe el tiempo de uso: ";
            cin >> TiempoUso;

            if (vidaUtil > 10) {
                cout << "Advertencia: La vida útil no puede ser mayor a 10 años.\n";
            }
            if (vidaUtil <= TiempoUso) {
                cout << "Advertencia: La vida útil debe ser mayor que el tiempo de uso.\n";
            }
        } while ((vidaUtil <= 0 || vidaUtil > 10) || (TiempoUso <= 0 || vidaUtil <= TiempoUso));
        strcpy(nomParte, nopart);
    }

    void tiempoRestante() {
        TiempoRest = (vidaUtil - TiempoUso);
    }

    void ImprimeDatos(); // Prototipo método
}; // Fin clase Parte

void Parte::ImprimeDatos() {
    cout << "Parte: \n";
    cout << "Clave: " << clave << endl;
    cout << "Nombre: " << nomParte << "\n";
    cout << "Tiempo restante: " << TiempoRest << " año(s)" << endl;
}

void ConfigurarConsola() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    setlocale(LC_ALL, "es_ES.UTF-8");
}

int main() {
    ConfigurarConsola();
    Parte partavion;
    partavion.CargarInformacion();
    partavion.tiempoRestante();
    partavion.ImprimeDatos();
    return 0;
}
