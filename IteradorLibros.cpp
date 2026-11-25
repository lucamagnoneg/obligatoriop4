// IteradorLibros.cpp
#include "IteradorLibros.h"
#include <stddef.h>

IteradorLibros :: IteradorLibros ()
{
    iter.prim = NULL;
    iter.ult = NULL;
    actual = NULL;
}

void IteradorLibros :: insertar (Libro * lib)
{
    NodoL * nuevo = new NodoL;
    nuevo -> info = lib;
    nuevo -> sig = NULL;
    if (iter.prim == NULL)
    {
        iter.prim = nuevo;
        actual = nuevo;             // el recorrido comienza por el primero
    }
    else
        iter.ult -> sig = nuevo;
    iter.ult = nuevo;
}

boolean IteradorLibros :: hayMasLibros ()
{
    return (actual != NULL);
}

Libro * IteradorLibros :: proximoLibro ()
{
    Libro * lib = actual -> info;
    actual = actual -> sig;
    return lib;
}

IteradorLibros :: ~IteradorLibros ()
{
    // se liberan solamente los nodos, NO los libros (pertenecen al diccionario Libros)
    NodoL * aux;
    while (iter.prim != NULL)
    {
        aux = iter.prim;
        iter.prim = iter.prim -> sig;
        delete aux;
    }
}
