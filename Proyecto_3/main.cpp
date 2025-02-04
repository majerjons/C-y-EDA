#include "objetos.h"

//Los objetos se definen en los .h
using namespace std;

int main ()
{
    Rectangulo r (6.0 , 3.0);
    r.imprimir();
    r.setAlto(10.0);
    r.setAncho(5.0);
    r.imprimir();
    return 0;
}