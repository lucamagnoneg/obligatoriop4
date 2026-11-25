// Fecha.h
#ifndef FECHA_H
#define FECHA_H

#include "Boolean.h"

class Fecha
{
    private:
        int dia, mes, anio;

    public:
        Fecha ();                           // Constructor por defecto
        Fecha (int, int, int);              // Constructor comun
        int getDia ();
        int getMes ();
        int getAnio ();
        boolean operator< (Fecha);          // true si la fecha implicita es anterior a la recibida
};

#endif
