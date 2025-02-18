#include "include/libros.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main (void)
{
    //hardcodeo libros de forma estatica, no dinamica para ahorrar trabajo y tener una sintaxis mas limpia.
    Libro libro1 ("Rita salame", "Lucas", 2025);
    Libro libro2 ("Javi salame", "Lucas", 2025);
    Libro libro3 ("Anashei", "Lucas", 2025);
    Libro libro4 ("Lol", "Lucas", 2025);
    Libro libro5 ("Seig Hail", "Lucas", 2025);

    //creo el vector de tipo de dato Libro, llamado librosVector
    vector<Libro> librosVector;
    librosVector.push_back(libro1);
    librosVector.push_back(libro2);
    librosVector.push_back(libro3);
    librosVector.push_back(libro4);
    librosVector.push_back(libro5);
    //Obs vector se comporta como un LIFO, en la posicion 0 del vector esta libro1, en la posicion 1 esta libro2, etc

    //creo la list
    list<Libro> librosList;
    librosList.push_back(libro1);
    librosList.push_back(libro2);
    librosList.push_back(libro3);
    librosList.push_back(libro4);
    librosList.push_back(libro5);

    //creo el map (clave: titulo, valor: libro)
    map<string, Libro> librosMap;
    librosMap.emplace("Rita", libro1);
    librosMap.emplace("Javi", libro2);
    librosMap.emplace("Nashe", libro3);
    librosMap.emplace("Lol", libro4);
    librosMap.emplace("Hitler", libro5);    //Es humor negro, si no te la bancas comeme los 2 huevos pa

    //Imprimo los datos accediendo a mis estructuras de estos:
    for (auto it = librosVector.begin(); it != librosVector.end(); ++it)
    {       
            cout << "Vector" <<endl;
            cout << it->getTitulo() << endl;
            cout << it->getAutor() << endl;
            cout << it->getFecha() << endl;
            cout << endl;
    }

    for (auto it = librosList.begin(); it != librosList.end(); ++it)
    {
            cout << "List" <<endl;
            cout << it->getTitulo() << endl;
            cout << it->getAutor() << endl;
            cout << it->getFecha() << endl;
            cout << endl;
    }

    for (auto it = librosMap.begin(); it != librosMap.end(); ++it)
    {
            cout << "Map" <<endl;
            cout << it->second.getTitulo() << endl;
            cout << it->second.getAutor() << endl;
            cout << it->second.getFecha() << endl;
            cout << endl;
    }

    return 0;
}
