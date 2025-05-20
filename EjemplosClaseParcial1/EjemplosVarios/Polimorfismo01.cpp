#include<iostream>
#include <math.h>
#include <locale.h>
using namespace std;

class Figura {
    //private:
    public:
    //protected:
        float base;
        float altura;
    public:
        void captura();
        virtual float perimetro()=0; /* Función virtual pura */
        virtual float area()=0;
};
class Rectangulo: public Figura {
    public:
        //void imprime();
        float perimetro(){return 2*(base+altura);}
        float area(){return base*altura;}
};
class Triangulo: public Figura {
    public:
        //void muestra();
        float perimetro(){return 2*sqrt(altura*altura+pow((base/2),2))+base;} //Usando pitágoras
        float area(){return (base*altura)/2;}
};
void Figura::captura()
{
    cout << "Calculo del área y perímetro de un triángulo y un rectángulo:" << endl;
    cout << "Escribe la altura: ";
    cin >> altura;
    cout << "Escribe la base: ";
    cin >> base;
    cout << "El Perímetro es: " << perimetro() << endl;
    cout << "El área es:      " << area() << endl;
}

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    Figura *fig;
    Rectangulo rectAn; Triangulo triAn;
    fig = &rectAn;
    fig->captura();
    fig = &triAn;
    fig->captura();
    cout << "Hello world!" << endl;
    return 0;
}
