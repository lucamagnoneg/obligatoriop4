// Texto.h
#ifndef TEXTO_H
#define TEXTO_H

#include "Libro.h"
#include "Fecha.h"

class Texto : public Libro
{
    private:
        String materia;
        Fecha fechaPublicado;

    public:
        Texto (long int, String, String, float, String, Fecha);
        String getMateria ();
        Fecha getFechaPublicado ();
        float calcularPrecioVenta ();
        String tipoLibro ();
        ~Texto ();
};

#endif
