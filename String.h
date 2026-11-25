// String.h
#ifndef STRING_H
#define STRING_H

#include <string.h>
#include "Boolean.h"
#include "Constantes.h"

class String
{
    private:
        char * cadena;

    public:
        String ();                                  // Constructor por defecto
        String (const char *);                      // Constructor comun
        String (const String &);                    // Constructor de copia
        String operator= (const String &);          // Sobrecarga de asignacion
        boolean operator== (const String &);        // Igualdad entre strings
        boolean comienzaCon (const String &);       // true si el string implicito comienza con el parametro
        int largo ();                               // cantidad de caracteres
        void print ();                              // despliega el string por pantalla
        void scan ();                               // carga el string desde teclado (linea completa)
        ~String ();                                 // Destructor
};

#endif
