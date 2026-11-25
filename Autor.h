// Autor.h
#ifndef AUTOR_H
#define AUTOR_H

#include "String.h"

class Autor
{
    private:
        long int cedula;
        String nombre;
        String apellido;

    public:
        Autor (long int, String, String);   // Constructor comun
        long int getCedula ();
        String getNombre ();
        String getApellido ();
        ~Autor ();                          // Destructor
};

#endif
