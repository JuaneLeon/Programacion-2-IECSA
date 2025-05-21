#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Clase base Empleado
class Empleado {
protected:
    int horasTrabajadas;
    float sueldoPorHora;

public:
    // Constructor
    Empleado(int horas = 0, float sueldo = 0.0f) 
        : horasTrabajadas(horas), sueldoPorHora(sueldo) {}

    // setters son opcionales, pero pueden ser útiles para modificar los valores dentro de la clase
    void HorasTrabajadas(int horas) {
        horasTrabajadas = horas;
    }

    void SueldoPorHora(float sueldo) {
        sueldoPorHora = sueldo;
    }

    // Método virtual puro (clase abstracta para calcular salario)
    // Este método debe ser implementado por las clases derivadas
    virtual float CalcularSalario() = 0;

    // Destructor virtual
    // Asegura que el destructor de la clase base se llame correctamente
    // al eliminar un objeto de una clase derivada a través de un puntero de la clase base
    virtual ~Empleado() {}
};

// Clase para empleados sin horas extras
class EmpleadoSinHorasExtras : public Empleado {
public:
    EmpleadoSinHorasExtras(int horas = 0, float sueldo = 0.0f) 
        : Empleado(horas, sueldo) {}

    float CalcularSalario() override {
        return horasTrabajadas * sueldoPorHora;
    }
};

// Clase para empleados con horas dobles
class EmpleadoConHorasDobles : public Empleado {
private:
    int horasExtras;

public:
    EmpleadoConHorasDobles(int horas = 0, float sueldo = 0.0f) 
        : Empleado(horas, sueldo) {
        horasExtras = (horasTrabajadas > 40) ? horasTrabajadas - 40 : 0;
    }

    int HorasExtras() const {
        return horasExtras;
    }

    float CalcularSalario() override {
        float salarioBase = 40 * sueldoPorHora;
        float salarioExtras = horasExtras * sueldoPorHora * 2;
        return salarioBase + salarioExtras;
    }
};

// Clase para empleados con horas triples
class EmpleadoConHorasTriples : public Empleado {
private:
    int horasExtras;

public:
    EmpleadoConHorasTriples(int horas = 0, float sueldo = 0.0f) 
        : Empleado(horas, sueldo) {
        horasExtras = (horasTrabajadas > 45) ? horasTrabajadas - 45 : 0;
    }

    int HorasExtras() const {
        return horasExtras;
    }

    float CalcularSalario() override {
        float salarioBase = 40 * sueldoPorHora;
        float salarioExtrasDobles = 5 * sueldoPorHora * 2; // Horas 41-45 (5 horas)
        float salarioExtrasTriples = horasExtras * sueldoPorHora * 3;
        return salarioBase + salarioExtrasDobles + salarioExtrasTriples;
    }
};

// Función para mostrar información del empleado
void MostrarInformacion(Empleado* emp) {
    cout << fixed << setprecision(2);
    cout << "Salario calculado: $" << emp->CalcularSalario() << endl;
}

int main() {
    // Configuración para imprimir acentos y caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int tipoEmpleado, horas;
    float sueldo;
    char continuar;

    do {
        cout << "Seleccione el tipo de empleado:\n";
        cout << "1. Sin horas extras\n";
        cout << "2. Con horas dobles (más de 40 horas)\n";
        cout << "3. Con horas triples (más de 45 horas)\n";
        cout << "Opción: ";
        cin >> tipoEmpleado;

        cout << "Ingrese las horas trabajadas: ";
        cin >> horas;
        cout << "Ingrese el sueldo por hora: ";
        cin >> sueldo;

        Empleado* emp = nullptr;

        switch (tipoEmpleado) {
            case 1:
                emp = new EmpleadoSinHorasExtras(horas, sueldo);
                break;
            case 2:
                emp = new EmpleadoConHorasDobles(horas, sueldo);
                break;
            case 3:
                emp = new EmpleadoConHorasTriples(horas, sueldo);
                break;
            default:
                cout << "Tipo de empleado no valido.\n";
                continue;
        }

        MostrarInformacion(emp);
        delete emp;

        cout << "\n¿Desea calcular otro salario? (s/n): ";
        cin >> continuar;
        cout << endl;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
