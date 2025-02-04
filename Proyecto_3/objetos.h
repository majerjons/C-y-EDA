#ifndef OBJETOS_H
#define OBJETOS_H

//librerias
#include <iostream>
using namespace std;

//el const evita que se modifiquen los miembros del objeto. 
//Aparte, los metodos tienen acceso directo a los miembros del objeto, por eso no ahce falta pasarlos como parametros.

class Rectangulo
{
    private: //se encapsulan los atributos/miebros(datos) que definen el estado del rectangulo, como anchura, altura, coordendas si se coloca en algun lugar
        double ancho;
        double alto;

    public: //con lo que nteractua el usuario, metodos getters para saber el estado del rectangulo, metodos setter para modificar dicho estado si asi lo deseo. 
            //Metodos como calcular su area y imprimirla, etc. Aqui se utilizan los metodos constructores y destructores.

    //Constructor parametrizado, inicializa mi objeto con un valor dado, puede ser cualquier valor.
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    //Getters
    double getAncho() const 
    {
        return ancho;
    }

    double getAlto() const 
    {
        return alto;
    }

    //Setters
    void setAncho (double a)
    {
        if (a >= 0)
        {
            ancho = a;
        }
        else
        {
            cerr << "Error, el ancho no puede ser un numero engativo" << endl;
        }
    }

    void setAlto (double h)
    {
        if (h >= 0)
        {
            alto = h;
        }
        else
        {
            cerr << "Error, el alto no puede ser un numero engativo" << endl;
        }
    }

    //Metodos distintos, como calculo de area o perimetro
    double area() const
    {
        return (ancho*alto);
    }

    double perimetro() const  
    {
        return (2*(ancho*alto));
    }

    void imprimir () const
    {
        cout << "Medidas del rectangulo:" << endl;
        cout << "Ancho: " << ancho <<" Alto: "<< alto << endl;
        cout << "area: " << area() <<" Perimetro: "<< perimetro() << endl;
    }

};

#endif
