#include "../include/LinkedList.h"

namespace DataStructure
{
    // Constructor de ListNode.
    // Inicializa el nodo con el valor 'd' y establece el puntero Next a nullptr.
    ListNode::ListNode(int d) : data(d), Next(nullptr)
    {
        // Cuerpo vacío: la lista de inicialización ya realiza la asignación.
    }

    // Constructor de LinkedList.
    // Inicializa la lista vacía, estableciendo Head a nullptr.
    LinkedList::LinkedList() : Head(nullptr)
    {
        // No hay más inicializaciones necesarias.
    }

    // Destructor de LinkedList.
    // Recorre la lista y libera la memoria de cada nodo para evitar fugas de memoria.
    LinkedList::~LinkedList()
    {
        ListNode* Current = Head;
        // Se recorre la lista hasta que no haya más nodos.
        while (Current != nullptr)
        {
            ListNode* Aux = Current;   // Guarda el nodo actual.
            Current = Current->Next;   // Avanza al siguiente nodo.
            delete Aux;                // Libera la memoria del nodo actual.
        }
    }

    // Método insert: inserta un nuevo nodo con el valor 'd' al final de la lista.
    void LinkedList::insert (int d)
    {
        // Crear un nuevo nodo dinámico con el valor 'd'.
        ListNode* newNode = new ListNode(d);
        // Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
        if (Head == nullptr)
        {
            Head = newNode;
        }
        else
        {
            // Se recorre la lista hasta encontrar el último nodo.
            ListNode* Current = Head;
            while (Current->Next != nullptr)
            {
                Current = Current->Next;
            }
            // Se enlaza el último nodo con el nuevo nodo.
            Current->Next = newNode;
        }
    }

    // Método remove: elimina la primera aparición del nodo que contiene el valor 'd'.
    void LinkedList::remove(int d)
    {
        // Si la lista está vacía, no hay nada que eliminar.
        if (Head == nullptr)
        {
            return;
        }
        // Si el nodo a eliminar es la cabeza.
        if (Head->data == d)
        {
            ListNode* Aux = Head;
            Head = Head->Next;  // La cabeza se actualiza al siguiente nodo.
            delete Aux;         // Se libera la memoria del nodo eliminado.
            return;
        }
        // Se busca el nodo anterior al nodo que contiene el valor 'd'.
        ListNode* Current = Head;
        while (Current->Next != nullptr && Current->Next->data != d)
        {
           Current = Current->Next;
        }
        // Si se encontró el nodo (Current->Next no es nullptr), se procede a eliminarlo.
        if (Current->Next != nullptr)
        {
            ListNode* Aux = Current->Next;
            // Se salta el nodo a eliminar, enlazando el nodo actual con el siguiente del nodo eliminado.
            Current->Next = Current->Next->Next;
            delete Aux; // Se libera la memoria del nodo eliminado.
        }
    }

    // Método print: recorre la lista y muestra el valor de cada nodo.
    void LinkedList::print() const
    {
        ListNode* Current = Head;
        // Mientras queden nodos en la lista, se imprime el valor y se avanza.
        while (Current != nullptr)
        {
            std::cout << Current->data << " -> ";
            Current = Current->Next;
        }
        // Se indica el final de la lista.
        std::cout << "Null" << std::endl;
    }

} // Fin del namespace DataStructure
