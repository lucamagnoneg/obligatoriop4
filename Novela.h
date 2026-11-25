// Novela.h
#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"
#include "Autor.h"

class Novela : public Libro
{
    private:
        String genero;
        Autor * autor;          // puntero al autor (inicialmente NULL), NO se destruye desde la novela

    public:
        Novela (long int, String, String, float, String);
        String getGenero ();
        Autor * getAutor ();
        void setAutor (Autor *);
        float calcularPrecioVenta ();
        String tipoLibro ();
        ~Novela ();
};

#endif
