#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

namespace DataStructure
{
    // La clase Node representa un nodo individual en un árbol binario.
    // Cada nodo contiene un valor (data) y dos punteros, left y right, que apuntan
    // a sus hijos izquierdo y derecho respectivamente. Esta estructura es fundamental
    // para construir la jerarquía del árbol.
    class Node
    {
        public:
            int data;      // Valor almacenado en el nodo.
            Node* left;    // Puntero al hijo izquierdo.
            Node* right;   // Puntero al hijo derecho.

            // Constructor: inicializa el nodo con un valor dado y establece
            // los punteros a nullptr, indicando que inicialmente no tiene hijos.
            Node(int d);
    };

    // La clase BinaryTree representa el árbol binario de búsqueda (BST) en su totalidad.
    // Aquí se gestiona la estructura global del árbol a través del puntero root (la raíz).
    // Se implementan métodos privados (recursivos) para realizar operaciones básicas:
    // - insert: inserta un nuevo nodo en el lugar correcto para mantener la propiedad del BST.
    // - inorderTransveral: recorre el árbol en inorden (orden ascendente).
    // - destroyTree: libera la memoria de todos los nodos al destruir el árbol.
    //
    // Se utiliza una clase separada para el árbol para encapsular la lógica de gestión
    // del conjunto de nodos, dejando a la clase Node solo la definición de cada elemento.
    // Esta separación mejora la modularidad y el mantenimiento del código.
    class BinaryTree
    {
        private:
            Node* root; // Puntero a la raíz del árbol. Si es nullptr, el árbol está vacío.

            // Función recursiva privada para insertar un nuevo nodo.
            // Toma como parámetros el nodo actual y el dato a insertar, y devuelve el nodo actualizado.
            Node* insert(Node* node, int data);

            // Función recursiva privada para realizar un recorrido inorden.
            // Recorre primero el subárbol izquierdo, luego el nodo actual, y finalmente el subárbol derecho.
            void inorderTransveral(Node* node) const;

            // Función recursiva privada para liberar la memoria de todos los nodos del árbol.
            void destroyTree(Node* node);
        
        public:
            // Constructor: Inicializa el árbol vacío, estableciendo root a nullptr.
            BinaryTree();

            // Destructor: Libera toda la memoria asignada a los nodos llamando a destroyTree.
            ~BinaryTree();

            // Función pública para insertar un dato en el árbol.
            // Esta función llama a la versión recursiva de insert.
            void insert(int data);

            // Función pública para iniciar un recorrido inorden del árbol.
            // Imprime los datos en orden ascendente.
            void inorder() const;
    };

}

#endif
