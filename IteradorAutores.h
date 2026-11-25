// IteradorAutores.h
#ifndef ITERADORAUTORES_H
#define ITERADORAUTORES_H

#include "Autor.h"

class IteradorAutores
{
    private:
        struct NodoA { Autor * info;        // puntero a autor (no se destruye desde el iterador)
                       NodoA * sig;
                     };
        struct LPPF  { NodoA * prim;
                       NodoA * ult;
                     };
        LPPF iter;
        NodoA * actual;                     // posicion del recorrido

    public:
        IteradorAutores ();
        void insertar (Autor *);
        boolean hayMasAutores ();
        Autor * proximoAutor ();            // precondicion: hayMasAutores()
        ~IteradorAutores ();
};

#endif
