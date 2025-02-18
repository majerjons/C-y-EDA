#include <iostream>
#include "include/LinkedList.h"
#include "include/BinaryTree.h"
using namespace std;
using namespace DataStructure;

int main (void)
{
    //Lista simplemente enlazada (solo se puede recorrer en un sentido)
    cout << "-----Lista enlazada-----" << endl;
    LinkedList List;
    List.insert(10);
    List.insert(20);
    List.insert(30);
    List.insert(40);
    List.print();
    List.remove(20);
    List.print();

    //Implemento un rbol pero con una lista simplemente enlazada, es decir, no puedo recorrerlo desde las hojas hasta la raiz, sino de la raiz hasta las hojas.
    //Implemento un arbol de busquedo binario, no AVL. 

    cout << "Arbol Binario de busqueda" << endl;

    BinaryTree tree;
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);

    cout << "Recorrido inorder:" << endl;
    tree.inorder();


    

    return 0;
}