#include <iostream>
#include "Fecha.h"
using namespace std;

int main()
{
    int d, m, s;
    cout << "Ingrese el dia: ";
    cin >> d;
    cout << "Ingrese el mes: ";
    cin >> m;
    cout << "Ingrese el anio: ";
    cin >> s;
    Fecha f(d, m, s);
    int ds = f.diaSemana();
    switch (ds)
    {
        case 0: cout << "Domingo" << endl; break;
        case 1: cout << "Lunes" << endl; break;
        case 2: cout << "Martes" << endl; break;
        case 3: cout << "Miercoles" << endl; break;
        case 4: cout << "Jueves" << endl; break;
        case 5: cout << "Viernes" << endl; break;
        case 6: cout << "Sabado" << endl; break;
    }
    return 0;
}
