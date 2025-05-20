#include<iostream>
#include <math.h>
#include <locale.h>
using namespace std;
#define PI 3.1416
class Poligono {
    //protected:
    public:
        float base;
        float altura;
        float radio;
    public:
        void captura(int);
        virtual float perimetro()=0; /* Función virtual pura */
        virtual float area()=0;
};
class Rectangulo: public Poligono {
    public:
        //void imprime();
        float perimetro(){return 2*(base+altura);}
        float area(){return base*altura;}
};
class Triangulo: public Poligono {
    public:
        //void muestra();
        float perimetro(){return 2*sqrt(altura*altura+pow((base/2),2))+base;} //Usando pitágoras
        float area(){return (base*altura)/2;}
};
class Circulo: public Poligono {
    public:
        //void muestra();
        float perimetro(){return PI*2*radio;}
        float area(){return PI*pow(radio,2);}
};
void Poligono::captura(int opc)
{
    cout << "Calculo del área y perímetro de un ";
    if (opc == 1 || opc == 2){
        if (opc == 1) cout << "Rectángulo "<< endl;
        if (opc == 2) cout << "Triángulo "<< endl;
        cout << "Escribe la altura: ";
        cin >> altura;
        cout << "Escribe la base: ";
        cin >> base;
    }
    if (opc == 3){
        cout << "Círculo "<< endl;
        cout << "Escribe el radio: ";
        cin >> radio;
    }
    cout << "El Perímetro es: " << perimetro() << endl;
    cout << "El área es:      " << area() << endl;
}

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int opcion = 0; char resp;
    Rectangulo rectAn; Triangulo triAn; Circulo cirCunf;
    do{
        do{
            cout << "Que figura quieres calcular? \n";
            cout << "1) Rectángulo, 2) Triángulo, 3) Círculo \n";
            cin >> opcion;
        }
        while (opcion < 1 || opcion >3);
        Poligono *fig;
        if (opcion == 1) fig = &rectAn;
        if (opcion == 2) fig = &triAn;
        if (opcion == 3) fig = &cirCunf;
        fig->captura(opcion);
        cout << "Quieres calcular otra figura? (s/n): ";
        cin>> resp; cout<< endl;
    }while (resp == 's');
    return 0;
}
