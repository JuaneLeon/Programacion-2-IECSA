#ifndef ARCHIVO_H
#define ARCHIVO_H

class Fecha {
    private:
        int dia;
        int mes;
        int ssaa;
    public:
        Fecha(int d, int m, int s);
        int diaSemana();
};
#endif
