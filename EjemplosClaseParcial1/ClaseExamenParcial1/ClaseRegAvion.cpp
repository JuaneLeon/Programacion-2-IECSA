#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <locale.h>

using namespace std;

class RegVelAvion {

private:
    // Atributos privados
    int numSerie;
    char MatAvion[7];
    char modeloAv[25];
    float posInicial;
    float posFinal;
    float tiempo;

    bool existeNumeroSerie(int nSerie) {
        ifstream arch("aviones.dat", ios::binary);
        if (!arch) return false;

        int s;
        char mat[7];
        char mod[25];
        float pi, pf, t;

        while (arch.read(reinterpret_cast<char*>(&s), sizeof(int))) {
            arch.read(mat, sizeof(mat));
            arch.read(mod, sizeof(mod));
            arch.read(reinterpret_cast<char*>(&pi), sizeof(float));
            arch.read(reinterpret_cast<char*>(&pf), sizeof(float));
            arch.read(reinterpret_cast<char*>(&t), sizeof(float));
            if (s == nSerie) {
                arch.close();
                return true;
            }
        }

        arch.close();
        return false;
    }

public:
    //atributos publicos
    void obtenerDatosUsuario() {
        char mat[7];
        char modAv[25];
        float poIni, poFin, tpo;
        int nSerieTemp;

        do {
            cout << "Escribe el numero de serie del avion (1-100): ";
            cin >> nSerieTemp;
            if (nSerieTemp < 1 || nSerieTemp > 100) {
                cout << "El numero de serie debe estar entre 1 y 100\n";
            } else if (existeNumeroSerie(nSerieTemp)) {
                cout << "Ese numero de serie ya existe. Ingrese uno diferente.\n";
                nSerieTemp = 0;
            }
        } while (nSerieTemp < 1 || nSerieTemp > 100);

        cout << "Escribe la matricula del avion: ";
        cin >> mat;

        cout << "Escribe el modelo del avion: ";
        cin.ignore();
        cin.getline(modAv, 25);

        do {
            cout << "Escribe la posicion inicial del avion (en metros): ";
            cin >> poIni;
            cout << "Escribe la posicion final del avion (en metros): ";
            cin >> poFin;
            cout << "Escribe el tiempo transcurrido (en segundos): ";
            cin >> tpo;
        } while (Valida(poIni, poFin, tpo));

        // Asignar a los atributos privados
        numSerie = nSerieTemp;
        strncpy(MatAvion, mat, 7); // Copia la matricula
        MatAvion[6] = '\0'; // Asegura que la cadena esté terminada en nulo
        strncpy(modeloAv, modAv, 25); // Copia el modelo del avion
        modeloAv[24] = '\0'; // Asegura que la cadena esté terminada en nulo
        posInicial = poIni;
        posFinal = poFin;
        tiempo = tpo;
    }

    bool Valida(float posIni, float posFin, float tiem) {
        if (posIni <= 0 || posFin <= 0) {
            cout << "Los valores de posicion deben ser > 0\n";
            return true;
        }
        if (posFin <= posIni) {
            cout << "La posicion final debe ser mayor que la inicial\n";
            return true;
        }
        if (tiem <= 0) {
            cout << "El tiempo debe ser mayor que cero\n";
            return true;
        }
        return false;
    }

    void archAccAleatCreaReg() {
        ofstream arch("aviones.dat", ios::binary | ios::trunc); // Crea el archivo o lo trunca si ya existe
        if (!arch) {
            cout << "Error al crear el archivo.\n";
            return;
        }
        arch.close();
        cout << "Archivo de acceso aleatorio creado.\n"; // Mensaje de confirmación
    }

    void archAccAleatEscrRegs() {
        ofstream arch("aviones.dat", ios::binary | ios::app); // Abre el archivo en modo append
        if (!arch) {
            cout << "Error al abrir el archivo para escritura.\n";
            return;
        }

        obtenerDatosUsuario();
        // Guardar campos individualmente
        arch.write(reinterpret_cast<char*>(&numSerie), sizeof(numSerie));
        arch.write(MatAvion, sizeof(MatAvion));
        arch.write(modeloAv, sizeof(modeloAv));
        arch.write(reinterpret_cast<char*>(&posInicial), sizeof(posInicial));
        arch.write(reinterpret_cast<char*>(&posFinal), sizeof(posFinal));
        arch.write(reinterpret_cast<char*>(&tiempo), sizeof(tiempo));

        arch.close();
        cout << "Registro guardado en archivo.\n";
    }

    void archAccAleatleer() {
        Letrero();

        ifstream arch("aviones.dat", ios::binary);
        if (!arch) {
            cout << "No se pudo abrir el archivo.\n";
            return;
        }

        cout << "\n";
        cout << left // Alineación a la izquierda
             << setw(10) << "Serie" // Ancho de 10 caracteres
             << setw(12) << "Matricula" // Ancho de 12 caracteres
             << setw(25) << "Modelo" // Ancho de 25 caracteres
             << setw(12) << "Pos. Ini" // Ancho de 12 caracteres
             << setw(12) << "Pos. Fin" // Ancho de 12 caracteres
             << setw(10) << "Tiempo" // Ancho de 10 caracteres
             << setw(12) << "Velocidad" // Ancho de 12 caracteres
             << "\n";
        cout << string(93, '-') << "\n"; // Línea de separación

        int s;
        char mat[7];
        char mod[25];
        float pi, pf, t;
        bool hayRegistros = false;

        while (arch.read(reinterpret_cast<char*>(&s), sizeof(int))) {
            arch.read(mat, sizeof(mat));
            arch.read(mod, sizeof(mod));
            arch.read(reinterpret_cast<char*>(&pi), sizeof(float));
            arch.read(reinterpret_cast<char*>(&pf), sizeof(float));
            arch.read(reinterpret_cast<char*>(&t), sizeof(float));

            cout << left
                 << setw(10) << s
                 << setw(12) << mat
                 << setw(25) << mod
                 << setw(12) << pi
                 << setw(12) << pf
                 << setw(10) << t
                 << setw(12) << ((pf - pi) / t)
                 << "\n";

            hayRegistros = true;
        }

        if (!hayRegistros) {
            cout << "No hay registros para mostrar.\n";
        }

        arch.close();
    }

    void buscarPorNumeroSerie() {
        Letrero();
        int buscarSerie;
        bool encontrado = false;
        cout << "Ingrese el numero de serie a buscar (1-100): ";
        cin >> buscarSerie;

        ifstream arch("aviones.dat", ios::binary);
        if (!arch) {
            cout << "No se pudo abrir el archivo.\n";
            return;
        }

        int s;
        char mat[7];
        char mod[25];
        float pi, pf, t;

        while (arch.read(reinterpret_cast<char*>(&s), sizeof(int))) {
            arch.read(mat, sizeof(mat));
            arch.read(mod, sizeof(mod));
            arch.read(reinterpret_cast<char*>(&pi), sizeof(float));
            arch.read(reinterpret_cast<char*>(&pf), sizeof(float));
            arch.read(reinterpret_cast<char*>(&t), sizeof(float));

            if (s == buscarSerie) {
                cout << left
                     << setw(10) << s
                     << setw(12) << mat
                     << setw(25) << mod
                     << setw(12) << pi
                     << setw(12) << pf
                     << setw(10) << t
                     << setw(12) << ((pf - pi) / t)
                     << "\n";
                encontrado = true;
                break;
            }
        }

        arch.close();
        if (!encontrado) {
            cout << "No se encontro un avion con ese numero de serie.\n";
        }
    }

    void Letrero() const {
        const char* texto = "Registro de aviones.\n";
        const char* colores[] = {
            "\033[31m", "\033[33m", "\033[32m",
            "\033[36m", "\033[34m", "\033[35m" 
        };
        int num_colores = 6;
        int i = 0;
        for (const char* p = texto; *p; ++p, ++i) {
            if (*p != ' ' && *p != '\n')
                cout << colores[i % num_colores] << *p << "\033[0m";
            else
                cout << *p;
        }
    }
};

int main() {
    setlocale(LC_ALL, ""); // Configuración de la localización para caracteres especiales
    RegVelAvion avion; // Instancia de la clase RegVelAvion
    int opcion; // Variable para la opción del menú
    char otro; // Variable para preguntar si se desea capturar otro avión

    avion.Letrero();

    do {
        avion.archAccAleatEscrRegs();
        cout << "Desea capturar otro avion? (s/n): ";
        cin >> otro;
    } while (otro == 's' || otro == 'S');

    do {
        cout << "\nMenu:\n";
        cout << "1. Ver todos los registros\n";
        cout << "2. Buscar avion por numero de serie\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                avion.archAccAleatleer();
                break;
            case 2:
                avion.buscarPorNumeroSerie();
                break;
            case 3:
                cout << "Fin del programa.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    return 0;
}
