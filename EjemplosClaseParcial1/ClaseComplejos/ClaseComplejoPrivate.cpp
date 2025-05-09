#include <iostream>
#include <cmath> 
using namespace std;

class complejo 
    {  
    double real=0;
    double imag=0;
    public:
    void davalores(double, double);
    double magnitud()
    {
        return sqrt(pow(real,2)+pow(imag,2));
    }
    };

void complejo::davalores(double a, double b)

{
    real=a;
    imag=b;
}
int main()
{
    double r,x,y;
    complejo z1;

    //z1.davalores(1.0,-1.5); 
    cout<<"Ingrese x: ";
    cin>>x;
    cout<<"Ingrese y: ";
    cin>>y;
    z1.davalores(x,y);
    r=z1.magnitud();
    cout<<"La magnitud del numero complejo es: "<<r<<endl;
}
