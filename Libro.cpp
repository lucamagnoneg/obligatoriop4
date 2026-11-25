// Libro.cpp
#include "Libro.h"

Libro :: Libro (long int i, String tit, String edi, float pre): titulo(tit), editorial(edi)
{
    isbn = i;
    precioBase = pre;
    unidadesVendidas = 0;
}

long int Libro :: getISBN ()
{
    return isbn;
}

String Libro :: getTitulo ()
{
    return titulo;
}

String Libro :: getEditorial ()
{
    return editorial;
}

float Libro :: getPrecioBase ()
{
    return precioBase;
}

int Libro :: getUnidadesVendidas ()
{
    return unidadesVendidas;
}

void Libro :: incrementarUnidadesVendidas ()
{
    unidadesVendidas++;
}

Libro :: ~Libro ()
{}
