#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
class pareja
 {
     /*Datos miembros de la clase "pareja"*/
     private:
         int a, b, c;
     public:
    //Constructor
        pareja(){cout<< "hola constructor sin parametros.\n";}
        pareja(int a2, int b2){
            a = a2;
            b = b2;
            cout << "\nConstructor de pareja en acción . . . ." << endl;
        }
    //Destructor
    ~pareja(){
        cout << "Pareja destruida completamente..... jajajaja .... adios" << endl;
    }
    //Funciones miembros de la clase "pareja"
    void Calcula(){
        c = pow(a,2)+pow(b,3);
        cout << "Calcula realiza el calculo: " << c << endl;
    }
    void Calcula02(){
        c = sqrt(c);
        cout << "Calcula02 realiza el calculo: " << c << endl;
    }
 };
 int main()
 {
     setlocale(LC_CTYPE,"Spanish");
     int x, y;
     pareja pare1(12, 32);
     pare1.Calcula();
     pare1.Calcula02();
     cout << endl;
     cout << "Escribe un valor para x: ";
     cin >> x;
     cout << "Escribe un valor para y: ";
     cin >> y;
     pareja pare2(x,y);
     pare2.Calcula();
     pare2.Calcula02();
     cout << endl;
     /*pareja pare3;
     pare3.Calcula();
     pare3.Calcula02();
     cout << endl; */
    return 0;
 }
