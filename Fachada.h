// Fachada.h
#ifndef FACHADA_H
#define FACHADA_H

#include "Libros.h"
#include "Autores.h"
#include "Novela.h"
#include "Texto.h"
#include "TextoEscolar.h"

class Fachada
{
    private:
        Libros libros;
        Autores autores;

    public:
        Fachada ();

        // R1: registrar un nuevo autor. error = true si ya existia la cedula
        void registrarAutor (long int, String, String, boolean &);

        // R2: registrar un nuevo libro. error = true si ya existia el isbn
        void registrarNovela (long int, String, String, float, String, boolean &);
        void registrarTexto (long int, String, String, float, String, Fecha, boolean &);
        void registrarTextoEscolar (long int, String, String, float, String, Fecha, int, boolean &);

        // R3: asociar un autor a una novela. Salidas: existeNovela, existeAutor
        void asociarAutorANovela (long int, long int, boolean &, boolean &);

        // R4: libros cuyo titulo comienza con la frase dada
        void listarLibrosPorFrase (String, IteradorLibros &);

        // R5: libro con el isbn dado (NULL si no existe)
        Libro * consultarLibro (long int);

        // R6: autores ordenados por cedula de menor a mayor
        void listarAutoresOrdenados (IteradorAutores &);

        // R7: registrar la venta de una unidad. existe = false si no existe el isbn
        void registrarVenta (long int, float &, boolean &);

        // R8: monto recaudado por una editorial
        float calcularRecaudacion (String);

        // R9: unidades vendidas de libros que superan un precio base, por tipo
        void contarVentasPorTipo (float, int &, int &, int &);

        // R10: libro mas vendido de una editorial (NULL si no hay libros de esa editorial)
        Libro * obtenerMasVendido (String);

        ~Fachada ();
};

#endif
