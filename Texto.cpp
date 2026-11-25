// Texto.cpp
#include "Texto.h"

Texto :: Texto (long int i, String tit, String edi, float pre, String mat, Fecha fec): Libro(i, tit, edi, pre), materia(mat), fechaPublicado(fec)
{}

String Texto :: getMateria ()
{
    return materia;
}

Fecha Texto :: getFechaPublicado ()
{
    return fechaPublicado;
}

float Texto :: calcularPrecioVenta ()
{
    float precio = getPrecioBase();
    Fecha limite(1, 1, 2026);
    if (fechaPublicado < limite)
        precio = precio * 0.75;         // publicado antes del 01/01/2026: 75% del precio base
    return precio;
}

String Texto :: tipoLibro ()
{
    return "Texto";
}

Texto :: ~Texto ()
{}
