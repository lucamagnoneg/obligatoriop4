// Autores.cpp
#include "Autores.h"
#include <stddef.h>

Autores :: Autores ()
{
    abb = NULL;
}

boolean Autores :: member (long int ced)
{
    ABB aux = abb;
    boolean encontre = false;
    while (aux != NULL && !encontre)
    {
        if (aux -> info -> getCedula() == ced)
            encontre = true;
        else
            if (ced < aux -> info -> getCedula())
                aux = aux -> hizq;
            else
                aux = aux -> hder;
    }
    return encontre;
}

void Autores :: insert (Autor * aut)
{
    ABB nuevo = new NodoABB;
    nuevo -> info = aut;
    nuevo -> hizq = NULL;
    nuevo -> hder = NULL;
    if (abb == NULL)
        abb = nuevo;
    else
    {
        ABB aux = abb;
        boolean ubicado = false;
        while (!ubicado)
        {
            if (aut -> getCedula() < aux -> info -> getCedula())
            {
                if (aux -> hizq == NULL)
                {
                    aux -> hizq = nuevo;
                    ubicado = true;
                }
                else
                    aux = aux -> hizq;
            }
            else
            {
                if (aux -> hder == NULL)
                {
                    aux -> hder = nuevo;
                    ubicado = true;
                }
                else
                    aux = aux -> hder;
            }
        }
    }
}

Autor * Autores :: find (long int ced)
{
    ABB aux = abb;
    while (aux -> info -> getCedula() != ced)
    {
        if (ced < aux -> info -> getCedula())
            aux = aux -> hizq;
        else
            aux = aux -> hder;
    }
    return (aux -> info);
}

void Autores :: cargarInOrden (ABB a, IteradorAutores &iter)
{
    if (a != NULL)
    {
        cargarInOrden(a -> hizq, iter);
        iter.insertar(a -> info);
        cargarInOrden(a -> hder, iter);
    }
}

void Autores :: darAutoresOrdenados (IteradorAutores &iter)
{
    cargarInOrden(abb, iter);
}

void Autores :: destruirABB (ABB a)
{
    if (a != NULL)
    {
        destruirABB(a -> hizq);
        destruirABB(a -> hder);
        delete (a -> info);     // cada autor se destruye una unica vez, aqui
        delete a;
    }
}

Autores :: ~Autores ()
{
    destruirABB(abb);
}
