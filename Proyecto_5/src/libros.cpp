#include "../include/libros.h"

    //Definiciones de los metodos:
    
    //Constructores y destructores
    Libro::Libro(std::string Titulo, std::string Autor, double Fecha) : autor(Autor) , titulo(Titulo), fecha(Fecha)
    {

    }

    Libro::~Libro()
    {

    }
    
    //Getters
    std::string Libro::getTitulo () const
    {
        return titulo;
    }

    std::string Libro::getAutor () const
    {
        return autor;
    }

    double Libro::getFecha () const
    {
        return fecha;
    }

