// String.cpp
#include "String.h"
#include <iostream>
using namespace std;

String :: String ()
{
    cadena = new char [1];
    cadena[0] = '\0';
}

String :: String (const char * cad)
{
    int largo = strlen(cad);            // cantidad de caracteres de la cadena
    cadena = new char [largo + 1];      // un lugar mas para el '\0'
    strcpy (cadena, cad);               // se copian los caracteres de la cadena
}

String :: String (const String &otro)
{
    int largo = strlen(otro.cadena);
    cadena = new char [largo + 1];
    strcpy (cadena, otro.cadena);
}

String String :: operator= (const String &otro)
{
    if (this != &otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char [largo + 1];
        strcpy (cadena, otro.cadena);
    }
    return (*this);
}

boolean String :: operator== (const String &otro)
{
    return (strcmp(cadena, otro.cadena) == 0);
}

boolean String :: comienzaCon (const String &frase)
{
    int largoFrase = strlen(frase.cadena);
    return (strncmp(cadena, frase.cadena, largoFrase) == 0);
}

int String :: largo ()
{
    return strlen(cadena);
}

void String :: print ()
{
    cout << cadena;
}

void String :: scan ()
{
    char aux[MAX];
    cin.getline(aux, MAX);
    delete [] cadena;
    int largo = strlen(aux);
    cadena = new char [largo + 1];
    strcpy (cadena, aux);
}

String :: ~String ()
{
    delete [] cadena;
}
