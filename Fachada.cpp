// Fachada.cpp
#include "Fachada.h"
#include <stddef.h>

Fachada :: Fachada (): libros(), autores()
{}

// R1
void Fachada :: registrarAutor (long int ced, String nom, String ape, boolean &error)
{
    if (autores.member(ced))
        error = true;
    else
    {
        error = false;
        autores.insert(new Autor(ced, nom, ape));
    }
}

// R2
void Fachada :: registrarNovela (long int isbn, String tit, String edi, float pre, String gen, boolean &error)
{
    if (libros.member(isbn))
        error = true;
    else
    {
        error = false;
        libros.insert(new Novela(isbn, tit, edi, pre, gen));
    }
}

void Fachada :: registrarTexto (long int isbn, String tit, String edi, float pre, String mat, Fecha fec, boolean &error)
{
    if (libros.member(isbn))
        error = true;
    else
    {
        error = false;
        libros.insert(new Texto(isbn, tit, edi, pre, mat, fec));
    }
}

void Fachada :: registrarTextoEscolar (long int isbn, String tit, String edi, float pre, String mat, Fecha fec, int anio, boolean &error)
{
    if (libros.member(isbn))
        error = true;
    else
    {
        error = false;
        libros.insert(new TextoEscolar(isbn, tit, edi, pre, mat, fec, anio));
    }
}

// R3
void Fachada :: asociarAutorANovela (long int isbn, long int ced, boolean &existeNovela, boolean &existeAutor)
{
    // con el isbn de la novela, buscarla en el diccionario de libros
    existeNovela = false;
    existeAutor = false;
    if (libros.member(isbn))
    {
        Libro * lib = libros.find(isbn);
        existeNovela = (lib -> tipoLibro() == "Novela");
    }
    if (existeNovela)
    {
        // con la cedula del autor, buscarlo en el diccionario de autores
        existeAutor = autores.member(ced);
        if (existeAutor)
        {
            // obtener el autor y setearselo a la novela (si ya tenia autor, es remplazado)
            Novela * nov = (Novela *) libros.find(isbn);
            nov -> setAutor(autores.find(ced));
        }
    }
}

// R4
void Fachada :: listarLibrosPorFrase (String frase, IteradorLibros &iter)
{
    libros.darLibrosPorFrase(frase, iter);
}

// R5
Libro * Fachada :: consultarLibro (long int isbn)
{
    Libro * lib = NULL;
    if (libros.member(isbn))
        lib = libros.find(isbn);
    return lib;
}

// R6
void Fachada :: listarAutoresOrdenados (IteradorAutores &iter)
{
    autores.darAutoresOrdenados(iter);
}

// R7
void Fachada :: registrarVenta (long int isbn, float &precio, boolean &existe)
{
    existe = libros.member(isbn);
    if (existe)
    {
        Libro * lib = libros.find(isbn);
        lib -> incrementarUnidadesVendidas();
        precio = lib -> calcularPrecioVenta();      // binding dinamico
    }
}

// R8
float Fachada :: calcularRecaudacion (String editorial)
{
    return libros.recaudacionEditorial(editorial);
}

// R9
void Fachada :: contarVentasPorTipo (float precio, int &novelas, int &textos, int &escolares)
{
    libros.contarVentasPorTipo(precio, novelas, textos, escolares);
}

// R10
Libro * Fachada :: obtenerMasVendido (String editorial)
{
    return libros.masVendidoEditorial(editorial);
}

Fachada :: ~Fachada ()
{}  // los destructores de libros y autores se invocan automaticamente
