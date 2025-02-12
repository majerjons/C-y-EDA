#include "rectangulo.h";

//Si bien el prototipo esta dentro del namespace ejemplo, hecho en el .h, es necesario que la definicion d elos metodos tambien esten encapsulados en ejemplo
//Por eso mismo encapsulo las definiciones, en vez deusar using namespace ejemplo, debido a que sino va a haber un error de linkeo. 
//Una analogia para entenderlo, es que en un archivo .c defina una funcion y que el prototipo este en un .h que no esta siendo incluido en ese .c. Habra error de linkeo.

namespace ejemplo
{
    //Definiciones de los metodos:

    //Constructores
    Rectangulo::Rectangulo() : ancho(0) , alto(0)
    {
        std::cout << "Constructor nulo" << std::endl;
    }

    Rectangulo::Rectangulo(double a, double h) : ancho(a) , alto(h)
    {
        std::cout << "Constructor parametrizado" << std::endl;
    }

    //Destructor
    Rectangulo::~Rectangulo()
    {
        std::cout << "Destructor" << std::endl;
    }

    //Metodos
    double Rectangulo::perimetro() const
    {
        return 2 * (ancho + alto);
    }

    double Rectangulo::area() const
    {
        return (alto * ancho);
    }

    //Setters
    void Rectangulo::setAlto (double h)
    {
        if (h < 0)
        {
            std::cout<<" No puede ser un valor negativo el alto." << std::endl;
            alto = 0;
        }
        alto = h;
    }

    void Rectangulo::setAncho (double a)
    {
        if (a < 0)
        {
            std::cout<<" No puede ser un valor negativo el ancho." << std::endl;
        }
        ancho = a;
    }

    //Getters
    double Rectangulo::getAlto () const
    {
       return alto;
    }

    double Rectangulo::getAncho () const
    {
        return ancho;
    }



}
