// Novela.cpp
#include "Novela.h"
#include <stddef.h>

Novela :: Novela (long int i, String tit, String edi, float pre, String gen): Libro(i, tit, edi, pre), genero(gen)
{
    autor = NULL;
}

String Novela :: getGenero ()
{
    return genero;
}

Autor * Novela :: getAutor ()
{
    return autor;
}

void Novela :: setAutor (Autor * aut)
{
    autor = aut;
}

float Novela :: calcularPrecioVenta ()
{
    float precio = getPrecioBase();
    if (genero == "infantil" || genero == "Infantil" || genero == "INFANTIL")
        precio = precio * 0.8;          // 20% de descuento a las novelas infantiles
    return precio;
}

String Novela :: tipoLibro ()
{
    return "Novela";
}

Novela :: ~Novela ()
{}  // no se destruye al autor: puede estar referenciado por otras novelas
