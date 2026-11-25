// Autores.h
#ifndef AUTORES_H
#define AUTORES_H

#include "Autor.h"
#include "IteradorAutores.h"

class Autores
{
    private:
        struct NodoABB { Autor * info;      // puntero a autor (referenciado tambien desde las novelas)
                         NodoABB * hizq;
                         NodoABB * hder;
                       };
        typedef NodoABB * ABB;              // ABB ordenado por cedula
        ABB abb;
        void cargarInOrden (ABB, IteradorAutores &);
        void destruirABB (ABB);

    public:
        Autores ();
        boolean member (long int);
        void insert (Autor *);                              // precondicion: !member(cedula)
        Autor * find (long int);                            // precondicion: member(cedula)
        void darAutoresOrdenados (IteradorAutores &);
        ~Autores ();
};

#endif
