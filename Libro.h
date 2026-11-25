// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include "String.h"

class Libro
{
    private:
        long int isbn;
        String titulo;
        String editorial;
        float precioBase;
        int unidadesVendidas;

    public:
        Libro (long int, String, String, float);    // Constructor comun (unidadesVendidas = 0)
        long int getISBN ();
        String getTitulo ();
        String getEditorial ();
        float getPrecioBase ();
        int getUnidadesVendidas ();
        void incrementarUnidadesVendidas ();
        virtual float calcularPrecioVenta () = 0;   // metodo virtual puro
        virtual String tipoLibro () = 0;            // metodo virtual puro
        virtual ~Libro ();                          // Destructor virtual
};

#endif
