// TextoEscolar.h
#ifndef TEXTOESCOLAR_H
#define TEXTOESCOLAR_H

#include "Texto.h"

class TextoEscolar : public Texto
{
    private:
        int anioEscuela;

    public:
        TextoEscolar (long int, String, String, float, String, Fecha, int);
        int getAnioEscuela ();
        float calcularPrecioVenta ();
        String tipoLibro ();
        ~TextoEscolar ();
};

#endif
