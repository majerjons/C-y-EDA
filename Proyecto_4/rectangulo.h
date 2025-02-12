#ifndef RECTANGULO_H
#define RECTANGULO_H

//Librerias
#include <iostream>

namespace ejemplo
{

    class Rectangulo 
    {
        private:
            double ancho;
            double alto;
        
        public:
            //Constructores
            Rectangulo (); //por defecto
            Rectangulo (double a, double h); //parametrizado/inicializado

            //Destructor
            ~Rectangulo ();

            //Metodos
            double area () const;
            double perimetro () const;

            //Getters y Setter
            double getAncho () const;
            double getAlto () const;
            void setAncho (double a);
            void setAlto (double h);

    };

}


#endif