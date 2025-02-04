#include <iostream> //libreria para el flujo standar de datos, es el analogo a stdio

using namespace std; //basicamente declaro el scope standar, ya que los flujos de salida (cin y cout) viven en estos, en caso de estar en otro scope especifico 
                    //(otro namespace) se es necesario colocar previo al cout: std::cout y lo mismo para el cin

//En C++ no hace falta colocar prototipos de funciones, vienen implicitas con la definicion de la misma, siempre y cuando la definicion este antes que el llamado

void referencia (int &y)
{
    y = y + 1;
}

int main (void)
{
    char letter;
    cin >> letter; //se le denomina operador de entrada de flujo de entrada al >> y se utiliza luego del cin.
    cout <<"la letra tecleada es: "<< letter << endl; //Se le denomina operador de flujo de salida al << y va previo a cada string, char o cadena de caracteres a imprimir. endl es \n
    
    //Ejemplo de pasaje de parametros por referencia, no debo crear el puntero a la variable, se autocrea solo
    int x = 10;
    cout <<"El valor original de x es:" << x << endl;
    referencia(x);
    cout << "se modifico x y su valor es:" << x << endl;
    
    return 0;
}

//Por ultimo, para compilarlo sin Cmake o makefile, se apreta: shift izq, control izq y b. Luego se elige la opcion C/C++: g++ build active file
//Obs: cin es getchar pero mejorado, depende el tipo de dato que sea tu variable donde se almacena, te almacena un char, una string o int o doubles, etc.

