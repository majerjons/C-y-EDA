#ifndef LIBROS_H
#define LIBROS_H

//Librerias
#include <string>

//Al tratarse de un solo objeto con metodos, no se necesita usar el namespace... Antes solo estaba para practicar.

    class Libro 
    {
        private:
            double fecha;
            std::string autor;
            std::string titulo;
        
        public:
            //Constructor
            Libro (std::string titulo, std::string autor, double fecha); //parametrizado/inicializado

            //Destructor
            ~Libro ();

            //Getters
            std::string getTitulo () const;
            std::string getAutor () const;
            double getFecha () const;

    };


#endif