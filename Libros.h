// Libros.h
#ifndef LIBROS_H
#define LIBROS_H

#include "Libro.h"
#include "IteradorLibros.h"
#include "Constantes.h"

class Libros
{
    private:
        struct Nodo { Libro * info;         // puntero a libro (coleccion polimorfica)
                      Nodo * sig;
                    };
        typedef Nodo * Lista;
        typedef Lista Hash[B];              // Hash abierto (con encadenamiento)
        Hash tabla;
        int funcionHash (long int);

    public:
        Libros ();
        boolean member (long int);
        void insert (Libro *);                              // precondicion: !member(isbn)
        Libro * find (long int);                            // precondicion: member(isbn)
        void darLibrosPorFrase (String, IteradorLibros &);
        float recaudacionEditorial (String);
        void contarVentasPorTipo (float, int &, int &, int &);
        Libro * masVendidoEditorial (String);               // NULL si no hay libros de la editorial
        ~Libros ();
};

#endif
