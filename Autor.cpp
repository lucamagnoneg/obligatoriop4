// Autor.cpp
#include "Autor.h"

Autor :: Autor (long int ced, String nom, String ape): nombre(nom), apellido(ape)
{
    cedula = ced;
}

long int Autor :: getCedula ()
{
    return cedula;
}

String Autor :: getNombre ()
{
    return nombre;
}

String Autor :: getApellido ()
{
    return apellido;
}

Autor :: ~Autor ()
{}
