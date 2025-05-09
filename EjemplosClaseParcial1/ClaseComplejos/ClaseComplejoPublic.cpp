#include <iostream>
#include <cmath> 
using namespace std;


class complejo
{   
    public:
    //seccion de definicion de datos, es "public"
    double real=0;
    double imag=0;

    double magnitud()
    {
        return sqrt(pow(real,2)+pow(imag,2));
    }
};

int main()
{
    double r;
    complejo z1;

    z1.real=2;
    z1.imag=2; 
    r=z1.magnitud();
    cout<<"La magnitud del numero complejo es: "<<r<<endl;
}
