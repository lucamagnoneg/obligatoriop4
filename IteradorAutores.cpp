// IteradorAutores.cpp
#include "IteradorAutores.h"
#include <stddef.h>

IteradorAutores :: IteradorAutores ()
{
    iter.prim = NULL;
    iter.ult = NULL;
    actual = NULL;
}

void IteradorAutores :: insertar (Autor * aut)
{
    NodoA * nuevo = new NodoA;
    nuevo -> info = aut;
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

boolean IteradorAutores :: hayMasAutores ()
{
    return (actual != NULL);
}

Autor * IteradorAutores :: proximoAutor ()
{
    Autor * aut = actual -> info;
    actual = actual -> sig;
    return aut;
}

IteradorAutores :: ~IteradorAutores ()
{
    // se liberan solamente los nodos, NO los autores (pertenecen al diccionario Autores)
    NodoA * aux;
    while (iter.prim != NULL)
    {
        aux = iter.prim;
        iter.prim = iter.prim -> sig;
        delete aux;
    }
}
