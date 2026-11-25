// TextoEscolar.cpp
#include "TextoEscolar.h"

TextoEscolar :: TextoEscolar (long int i, String tit, String edi, float pre, String mat, Fecha fec, int anio): Texto(i, tit, edi, pre, mat, fec)
{
    anioEscuela = anio;
}

int TextoEscolar :: getAnioEscuela ()
{
    return anioEscuela;
}

float TextoEscolar :: calcularPrecioVenta ()
{
    float precio = Texto :: calcularPrecioVenta();  // se calcula igual que un texto comun
    if (anioEscuela >= 1 && anioEscuela <= 3)
        precio = precio * 0.9;                      // 10% de descuento adicional de 1o a 3o
    return precio;
}

String TextoEscolar :: tipoLibro ()
{
    return "TextoEscolar";
}

TextoEscolar :: ~TextoEscolar ()
{}
