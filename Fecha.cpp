// Fecha.cpp
#include "Fecha.h"

Fecha :: Fecha ()
{
    dia = 1;
    mes = 1;
    anio = 2000;
}

Fecha :: Fecha (int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

int Fecha :: getDia ()
{
    return dia;
}

int Fecha :: getMes ()
{
    return mes;
}

int Fecha :: getAnio ()
{
    return anio;
}

boolean Fecha :: operator< (Fecha otra)
{
    boolean menor;
    if (anio != otra.anio)
        menor = (anio < otra.anio);
    else
        if (mes != otra.mes)
            menor = (mes < otra.mes);
        else
            menor = (dia < otra.dia);
    return menor;
}
