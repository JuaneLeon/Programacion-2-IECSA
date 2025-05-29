#include "Fecha.h"

Fecha::Fecha(int d, int m, int s)
{
    dia = d;
    mes = m;
    ssaa = s;
}

int Fecha::diaSemana()
    {
    int ss, aa, T, diaSemana;
    if (mes < 3)
    {
        mes = mes + 12;
        ssaa = ssaa - 1;
    }
    mes = mes - 2;
    ss = ssaa / 100;
    aa = ssaa % 100;
    T = ((26 * mes - 2) / 10) + dia + aa + (aa / 4) + ((ss / 4) + 5 * ss);
    diaSemana = T % 7;
    return diaSemana;
}
