// Libros.cpp
#include "Libros.h"
#include <stddef.h>

int Libros :: funcionHash (long int isbn)
{
    if (isbn < 0)
        isbn = -isbn;
    return (isbn % B);
}

Libros :: Libros ()
{
    for (int i = 0; i < B; i++)
        tabla[i] = NULL;
}

boolean Libros :: member (long int isbn)
{
    Lista aux = tabla[funcionHash(isbn)];
    boolean encontre = false;
    while (aux != NULL && !encontre)
    {
        if (aux -> info -> getISBN() == isbn)
            encontre = true;
        else
            aux = aux -> sig;
    }
    return encontre;
}

void Libros :: insert (Libro * lib)
{
    int cubeta = funcionHash(lib -> getISBN());
    Lista nuevo = new Nodo;
    nuevo -> info = lib;
    nuevo -> sig = tabla[cubeta];       // se inserta al principio de la lista
    tabla[cubeta] = nuevo;
}

Libro * Libros :: find (long int isbn)
{
    Lista aux = tabla[funcionHash(isbn)];
    while (aux -> info -> getISBN() != isbn)
        aux = aux -> sig;
    return (aux -> info);
}

void Libros :: darLibrosPorFrase (String frase, IteradorLibros &iter)
{
    Lista aux;
    for (int i = 0; i < B; i++)
    {
        aux = tabla[i];
        while (aux != NULL)
        {
            if (aux -> info -> getTitulo().comienzaCon(frase))
                iter.insertar(aux -> info);
            aux = aux -> sig;
        }
    }
}

float Libros :: recaudacionEditorial (String editorial)
{
    float total = 0;
    Lista aux;
    for (int i = 0; i < B; i++)
    {
        aux = tabla[i];
        while (aux != NULL)
        {
            if (aux -> info -> getEditorial() == editorial)
                total = total + aux -> info -> getUnidadesVendidas() * aux -> info -> calcularPrecioVenta();
            aux = aux -> sig;
        }
    }
    return total;
}

void Libros :: contarVentasPorTipo (float precio, int &novelas, int &textos, int &escolares)
{
    novelas = 0;
    textos = 0;
    escolares = 0;
    Lista aux;
    for (int i = 0; i < B; i++)
    {
        aux = tabla[i];
        while (aux != NULL)
        {
            if (aux -> info -> getPrecioBase() > precio)
            {
                String tipo = aux -> info -> tipoLibro();
                if (tipo == "Novela")
                    novelas = novelas + aux -> info -> getUnidadesVendidas();
                else
                    if (tipo == "TextoEscolar")
                        escolares = escolares + aux -> info -> getUnidadesVendidas();
                    else
                        textos = textos + aux -> info -> getUnidadesVendidas();
            }
            aux = aux -> sig;
        }
    }
}

Libro * Libros :: masVendidoEditorial (String editorial)
{
    Libro * mayor = NULL;
    Lista aux;
    for (int i = 0; i < B; i++)
    {
        aux = tabla[i];
        while (aux != NULL)
        {
            if (aux -> info -> getEditorial() == editorial)
            {
                if (mayor == NULL)
                    mayor = aux -> info;
                else
                    if (aux -> info -> getUnidadesVendidas() > mayor -> getUnidadesVendidas())
                        mayor = aux -> info;
            }
            aux = aux -> sig;
        }
    }
    return mayor;
}

Libros :: ~Libros ()
{
    // se destruyen los nodos y los libros (el destructor virtual de Libro
    // garantiza que se ejecute el destructor de Novela, Texto o TextoEscolar)
    Lista aux;
    for (int i = 0; i < B; i++)
    {
        while (tabla[i] != NULL)
        {
            aux = tabla[i];
            tabla[i] = tabla[i] -> sig;
            delete (aux -> info);
            delete aux;
        }
    }
}
