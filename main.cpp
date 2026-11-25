// main.cpp
// Capa de Presentacion: realiza la entrada de datos, los listados y los mensajes de error.
// Toda la comunicacion con la Capa Logica se hace a traves de la Fachada.
#include <iostream>
#include <stddef.h>
#include "Fachada.h"
using namespace std;

/* ---------- Procedimientos auxiliares de entrada ---------- */

void limpiarEntrada ()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

long int leerLong (const char * mensaje)
{
    long int valor;
    cout << mensaje;
    while (!(cin >> valor))
    {
        limpiarEntrada();
        cout << "Valor invalido. " << mensaje;
    }
    limpiarEntrada();
    return valor;
}

int leerInt (const char * mensaje)
{
    int valor;
    cout << mensaje;
    while (!(cin >> valor))
    {
        limpiarEntrada();
        cout << "Valor invalido. " << mensaje;
    }
    limpiarEntrada();
    return valor;
}

float leerFloat (const char * mensaje)
{
    float valor;
    cout << mensaje;
    while (!(cin >> valor))
    {
        limpiarEntrada();
        cout << "Valor invalido. " << mensaje;
    }
    limpiarEntrada();
    return valor;
}

String leerString (const char * mensaje)
{
    String s;
    cout << mensaje;
    s.scan();
    return s;
}

boolean fechaValida (int d, int m, int a)
{
    int diasMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    boolean valida = false;
    if (a > 0 && m >= 1 && m <= 12)
    {
        if (m == 2 && ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0))
            valida = (d >= 1 && d <= 29);
        else
            valida = (d >= 1 && d <= diasMes[m]);
    }
    return valida;
}

Fecha leerFecha ()
{
    int d, m, a;
    d = leerInt("  Dia: ");
    m = leerInt("  Mes: ");
    a = leerInt("  Anio: ");
    while (!fechaValida(d, m, a))
    {
        cout << "Fecha invalida, ingresela nuevamente.\n";
        d = leerInt("  Dia: ");
        m = leerInt("  Mes: ");
        a = leerInt("  Anio: ");
    }
    return Fecha(d, m, a);
}

/* ---------- Procedimientos auxiliares de salida ---------- */

void mostrarFecha (Fecha f)
{
    cout << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
}

void mostrarAutor (Autor * aut)
{
    cout << "Cedula: " << aut -> getCedula();
    cout << " - Nombre: ";
    aut -> getNombre().print();
    cout << " - Apellido: ";
    aut -> getApellido().print();
}

void mostrarLibro (Libro * lib)
{
    String tipo = lib -> tipoLibro();

    // si es novela y tiene autor, se listan primero los datos del autor
    if (tipo == "Novela")
    {
        Novela * nov = (Novela *) lib;
        if (nov -> getAutor() != NULL)
        {
            cout << "\n  Autor: ";
            mostrarAutor(nov -> getAutor());
        }
    }

    // luego se listan los datos del libro
    cout << "\n  Tipo: ";
    tipo.print();
    cout << "\n  ISBN: " << lib -> getISBN();
    cout << "\n  Titulo: ";
    lib -> getTitulo().print();
    cout << "\n  Editorial: ";
    lib -> getEditorial().print();
    cout << "\n  Precio base: " << lib -> getPrecioBase();
    cout << "\n  Unidades vendidas: " << lib -> getUnidadesVendidas();
    cout << "\n  Precio de venta: " << lib -> calcularPrecioVenta();

    if (tipo == "Novela")
    {
        cout << "\n  Genero: ";
        ((Novela *) lib) -> getGenero().print();
    }
    else
    {
        Texto * tex = (Texto *) lib;            // TextoEscolar tambien es un Texto
        cout << "\n  Materia: ";
        tex -> getMateria().print();
        cout << "\n  Fecha de publicacion: ";
        mostrarFecha(tex -> getFechaPublicado());
        if (tipo == "TextoEscolar")
            cout << "\n  Anio de escuela: " << ((TextoEscolar *) lib) -> getAnioEscuela();
    }
    cout << "\n";
}

/* ---------- Requerimientos ---------- */

void registrarAutor (Fachada &fachada)
{
    long int ced = leerLong("Cedula: ");
    String nom = leerString("Nombre: ");
    String ape = leerString("Apellido: ");
    boolean error;
    fachada.registrarAutor(ced, nom, ape, error);
    if (error)
        cout << "Error: Ya se encuentra registrado ese autor.\n";
    else
        cout << "Autor registrado correctamente.\n";
}

void registrarLibro (Fachada &fachada)
{
    cout << "Tipo de libro: 1) Novela  2) Texto  3) Texto escolar\n";
    int tipo = leerInt("Opcion: ");
    while (tipo < 1 || tipo > 3)
        tipo = leerInt("Opcion invalida. Opcion: ");

    long int isbn = leerLong("ISBN: ");
    String tit = leerString("Titulo: ");
    String edi = leerString("Editorial: ");
    float pre = leerFloat("Precio base: ");
    while (pre < 0)
        pre = leerFloat("El precio no puede ser negativo. Precio base: ");
    boolean error;

    if (tipo == 1)
    {
        String gen = leerString("Genero: ");
        fachada.registrarNovela(isbn, tit, edi, pre, gen, error);
    }
    else
    {
        String mat = leerString("Materia: ");
        cout << "Fecha de publicacion:\n";
        Fecha fec = leerFecha();
        if (tipo == 2)
            fachada.registrarTexto(isbn, tit, edi, pre, mat, fec, error);
        else
        {
            int anio = leerInt("Anio de escuela: ");
            while (anio < 1)
                anio = leerInt("Anio invalido. Anio de escuela: ");
            fachada.registrarTextoEscolar(isbn, tit, edi, pre, mat, fec, anio, error);
        }
    }

    if (error)
        cout << "Error: Ya se encuentra registrado ese libro.\n";
    else
        cout << "Libro registrado correctamente.\n";
}

void asociarAutor (Fachada &fachada)
{
    long int isbn = leerLong("ISBN de la novela: ");
    long int ced = leerLong("Cedula del autor: ");
    boolean existeNovela, existeAutor;
    fachada.asociarAutorANovela(isbn, ced, existeNovela, existeAutor);
    if (!existeNovela)
        cout << "Error: No se encuentra registrada esa novela.\n";
    else
        if (!existeAutor)
            cout << "Error: No se encuentra registrado ese autor.\n";
        else
            cout << "Autor asociado a la novela correctamente.\n";
}

void listarPorFrase (Fachada &fachada)
{
    String frase = leerString("Frase: ");
    IteradorLibros iter;
    fachada.listarLibrosPorFrase(frase, iter);
    if (!iter.hayMasLibros())
        cout << "Error: No se encontraron libros que coincidan con la frase ingresada.\n";
    else
    {
        Libro * lib;
        while (iter.hayMasLibros())
        {
            lib = iter.proximoLibro();
            cout << "ISBN: " << lib -> getISBN() << " - Titulo: ";
            lib -> getTitulo().print();
            cout << " - Tipo: ";
            lib -> tipoLibro().print();
            cout << "\n";
        }
    }
}

void consultarLibro (Fachada &fachada)
{
    long int isbn = leerLong("ISBN: ");
    Libro * lib = fachada.consultarLibro(isbn);
    if (lib == NULL)
        cout << "Error: No se encuentra ese libro registrado.\n";
    else
        mostrarLibro(lib);
}

void listarAutores (Fachada &fachada)
{
    IteradorAutores iter;
    fachada.listarAutoresOrdenados(iter);
    if (!iter.hayMasAutores())
        cout << "Error: No se encontraron autores registrados.\n";
    else
        while (iter.hayMasAutores())
        {
            mostrarAutor(iter.proximoAutor());
            cout << "\n";
        }
}

void registrarVenta (Fachada &fachada)
{
    long int isbn = leerLong("ISBN: ");
    float precio;
    boolean existe;
    fachada.registrarVenta(isbn, precio, existe);
    if (!existe)
        cout << "Error: No se encuentra ese libro registrado. Venta cancelada.\n";
    else
        cout << "Venta registrada. Importe a cobrar: $" << precio << "\n";
}

void recaudacionEditorial (Fachada &fachada)
{
    String edi = leerString("Editorial: ");
    cout << "Monto total recaudado: $" << fachada.calcularRecaudacion(edi) << "\n";
}

void ventasPorTipo (Fachada &fachada)
{
    float precio = leerFloat("Precio base: ");
    int novelas, textos, escolares;
    fachada.contarVentasPorTipo(precio, novelas, textos, escolares);
    cout << "Unidades vendidas de libros con precio base mayor a " << precio << ":\n";
    cout << "  Novelas: " << novelas << "\n";
    cout << "  Libros de texto comunes: " << textos << "\n";
    cout << "  Libros de texto escolares: " << escolares << "\n";
}

void masVendido (Fachada &fachada)
{
    String edi = leerString("Editorial: ");
    Libro * lib = fachada.obtenerMasVendido(edi);
    if (lib == NULL)
        cout << "Error: No se encontraron libros de esa editorial.\n";
    else
        mostrarLibro(lib);
}

/* ---------- Programa principal ---------- */

int main ()
{
    Fachada fachada;
    int opcion;
    do
    {
        cout << "\n========== LIBRERIA ==========\n";
        cout << " 1) Registrar autor\n";
        cout << " 2) Registrar libro\n";
        cout << " 3) Asociar autor a novela\n";
        cout << " 4) Listar libros por frase del titulo\n";
        cout << " 5) Consultar libro por ISBN\n";
        cout << " 6) Listar autores (por cedula)\n";
        cout << " 7) Registrar venta\n";
        cout << " 8) Recaudacion por editorial\n";
        cout << " 9) Unidades vendidas por tipo sobre un precio base\n";
        cout << "10) Libro mas vendido de una editorial\n";
        cout << " 0) Salir\n";
        opcion = leerInt("Opcion: ");
        cout << "\n";
        switch (opcion)
        {
            case 1:  registrarAutor(fachada);        break;
            case 2:  registrarLibro(fachada);        break;
            case 3:  asociarAutor(fachada);          break;
            case 4:  listarPorFrase(fachada);        break;
            case 5:  consultarLibro(fachada);        break;
            case 6:  listarAutores(fachada);         break;
            case 7:  registrarVenta(fachada);        break;
            case 8:  recaudacionEditorial(fachada);  break;
            case 9:  ventasPorTipo(fachada);         break;
            case 10: masVendido(fachada);            break;
            case 0:  cout << "Fin del programa.\n";  break;
            default: cout << "Opcion invalida.\n";
        }
    }
    while (opcion != 0);
    return 0;
}
