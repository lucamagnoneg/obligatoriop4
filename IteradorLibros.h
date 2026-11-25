// IteradorLibros.h
#ifndef ITERADORLIBROS_H
#define ITERADORLIBROS_H

#include "Libro.h"

class IteradorLibros
{
    private:
        struct NodoL { Libro * info;        // puntero a libro (no se destruye desde el iterador)
                       NodoL * sig;
                     };
        struct LPPF  { NodoL * prim;
                       NodoL * ult;
                     };
        LPPF iter;
        NodoL * actual;                     // posicion del recorrido

    public:
        IteradorLibros ();
        void insertar (Libro *);
        boolean hayMasLibros ();
        Libro * proximoLibro ();            // precondicion: hayMasLibros()
        ~IteradorLibros ();
};

#endif
