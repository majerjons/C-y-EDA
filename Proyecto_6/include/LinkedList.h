#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace DataStructure
{
    // Definición de la clase ListNode que representa un nodo en la lista enlazada.
    // Cada nodo contiene un valor de tipo entero y un puntero al siguiente nodo.
    class ListNode  
    {
        public:
            int data;           // Valor almacenado en el nodo.
            ListNode* Next;     // Puntero al siguiente nodo en la lista.

            // Constructor que inicializa el nodo con un valor específico.
            ListNode(int d);
    };

    // Definición de la clase LinkedList que representa la lista enlazada.
    // Contiene un puntero a la cabeza de la lista y métodos para manipularla.
    class LinkedList
    {
        private:
            ListNode* Head;     // Puntero al primer nodo de la lista (cabeza).

        public:
            // Constructor que inicializa la lista vacía.
            LinkedList();

            // Destructor que libera la memoria ocupada por la lista.
            ~LinkedList();

            // Método para insertar un nuevo nodo con un valor específico al final de la lista.
            void insert(int d);

            // Método para eliminar el primer nodo que contiene un valor específico.
            void remove(int d);

            // Método para imprimir los valores de todos los nodos en la lista.
            void print() const;
    };

}

#endif
