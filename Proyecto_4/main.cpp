#include "rectangulo.h"

int main (void)
{
    using namespace ejemplo;
    double a;
    double h;
    unsigned int n;

    std::cout<< "A continuacion, ingresar los valores del conjunto de rectangulos uniformes" << std::endl;
    std::cout<< "Ingrese la cantidad de rectangulos que desea:" << std::endl;
    std::cin >> n;
    std::cout<< "Ingrese el ancho:" << std::endl;
    std::cin >> a;
    std::cout<< "Ingrese el alto:" << std::endl;
    std::cin >> h;


    //objeto dinamico de tipo rectangulo
    Rectangulo* r1_ptr = new Rectangulo(a , h);
    std::cout<< "Las medidas del rectangulo 1 son:" << std::endl;
    std::cout<< "Ancho: " << r1_ptr->getAncho() <<std::endl;
    std::cout<< "Alto: " << r1_ptr->getAlto()<<std::endl;
    std::cout<< "Area: " << r1_ptr->area() <<std::endl;
    std::cout<< "Perimetro: " << r1_ptr->perimetro() <<std::endl;

    //Libero la memoria
    delete r1_ptr;

    //Arreglo de objetos dinamicos
    Rectangulo* arr = new Rectangulo [n];
    for (int i = 0; i < n; i++)
    {
        arr[n].setAlto(h);
        arr[n].setAncho(a);
        std::cout<< "Las medidas del rectangulo " << i << " son:" << std::endl;
        std::cout<< "Ancho: " << arr[n].getAncho() <<std::endl;
        std::cout<< "Alto: " << arr[n].getAlto()<<std::endl;
        std::cout<< "Area: " << arr[n].area() <<std::endl;
        std::cout<< "Perimetro: " << arr[n].perimetro() <<std::endl;
    }
    delete [] arr;

    return 0;
}