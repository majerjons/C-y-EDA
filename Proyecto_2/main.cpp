//Este programa se enfoca en namespace y string

#include <iostream>
#include <string>   //libreria para uso de strings! Ya no mas vectores/arrays de chars. String al igual que iostream, viven en el namespace std.

void saludar (void)
{
    std::cout << "funcion definida de manera global" << std::endl;
}

void saludar (std::string mensaje)
{
    std::cout << "funcion definida de manera global y con sobrecarga, a continuacion imprimo el input " << mensaje << std::endl;
}

namespace Ejemplo 
{
    void saludar (void)
    {
        std::cout << "Funcion encapsulada en un namespace"<< std::endl; 
    }

}
//importa declarar y definir el namespace en el codigo previo a su uso. Si lo definiera despues del main, sale error

int main (void)
{
    std::string mensaje; //string que toma los inputs
    std::string texto ("texto hardcodeado, a continuacion va el input:");
    std::string concatenacion;
    std::cin >> mensaje;
    concatenacion = texto + mensaje;
    std::cout << concatenacion << std::endl;

    std::cout << "A partir de aca se ve el tema de namespaces" << std::endl;

    //como no coloque el namespace(encapsulamiento de scope) al principio de manera global, debo utilizar el operador resolucion de entorno (::) junto al std
    //Ahora dare ejemplo con funciones
    Ejemplo::saludar(); //si no colocara el Ejemplo::, la funcion no seria detectada. Es como si estuviera en otro archivo .cpp y que no fuera linkeado al main.
    saludar();
    saludar (mensaje);
    return 0;
}

//Observacion, esto es un caso particular de sobrecargamiento. Tambien podria colocar 2 funciones con el mismo nombre en un mismo namespace pero con distintos 
//parametros de entrada. El propio lenguaje, depende que tipo de dato le paso en los parametros a la hora de llamarla, sabe diferenciar a cual funcion debe ser

