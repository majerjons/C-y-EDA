#include "../include/BinaryTree.h"

// Se utiliza el namespace DataStructure para agrupar las definiciones
// y evitar conflictos con otras partes del código.
namespace DataStructure
{
    // --------------------------------------------------------------------------
    // Definición del constructor de la clase Node.
    // Inicializa el nodo con el dato 'd' y establece los punteros left y right
    // a nullptr, indicando que inicialmente no tiene hijos.
    // --------------------------------------------------------------------------
    Node::Node(int d) : data(d), left(nullptr), right(nullptr)
    {
        // Cuerpo vacío, ya que la lista de inicialización se encarga de asignar valores.
    }

    // --------------------------------------------------------------------------
    // Constructor de la clase BinaryTree.
    // Inicializa el árbol estableciendo la raíz (root) a nullptr, lo que indica que
    // el árbol comienza vacío.
    // --------------------------------------------------------------------------
    BinaryTree::BinaryTree() : root(nullptr)
    {
        // No se requiere código adicional en el constructor.
    }

    // --------------------------------------------------------------------------
    // Destructor de la clase BinaryTree.
    // Llama a la función destroyTree para liberar la memoria de todos los nodos
    // del árbol y evitar fugas de memoria.
    // --------------------------------------------------------------------------
    BinaryTree::~BinaryTree()
    {
        destroyTree(root);
    }

    // --------------------------------------------------------------------------
    // Función destroyTree (privada, recursiva)
    // Recorre el árbol en postorden y libera la memoria de cada nodo.
    // Primero libera el subárbol izquierdo, luego el derecho y finalmente el nodo actual.
    // --------------------------------------------------------------------------
    void BinaryTree::destroyTree(Node* node)
    {
        if (node) // Si el nodo no es nulo...
        {
            destroyTree(node->left);  // Liberar recursivamente el subárbol izquierdo.
            destroyTree(node->right); // Liberar recursivamente el subárbol derecho.
            delete node;              // Liberar la memoria del nodo actual.
        }
    }

    // --------------------------------------------------------------------------
    // Función insert (privada, recursiva)
    // Inserta un nuevo dato en el árbol binario de búsqueda de manera recursiva.
    // Si el nodo actual es nullptr, se crea un nuevo nodo.
    // Si el dato es menor que el dato del nodo actual, se inserta en el subárbol izquierdo;
    // de lo contrario, se inserta en el subárbol derecho.
    // Devuelve el puntero actualizado al nodo.
    // --------------------------------------------------------------------------
    Node* BinaryTree::insert(Node* node, int data)
    {
        if (node == nullptr)
        {
            // Si el nodo es nulo, se crea un nuevo nodo con el dato.
            return new Node(data);
        }
        if (data < node->data)
        {
            // Si el dato es menor, se inserta en el subárbol izquierdo.
            node->left = insert(node->left, data);
        }
        else
        {
            // Si el dato es mayor o igual, se inserta en el subárbol derecho.
            node->right = insert(node->right, data);
        }
        return node; // Retorna el nodo actualizado.
    }

    // --------------------------------------------------------------------------
    // Función insert (pública)
    // Inserta un dato en el árbol. Esta función es la interfaz pública y llama
    // a la función recursiva insert, actualizando la raíz del árbol.
    // --------------------------------------------------------------------------
    void BinaryTree::insert(int data)
    {
        root = insert(root, data);
    }

    // --------------------------------------------------------------------------
    // Función inorderTransveral (privada, recursiva)
    // Realiza un recorrido inorden del árbol. En un recorrido inorden,
    // se visita primero el subárbol izquierdo, luego el nodo actual y finalmente
    // el subárbol derecho. Este método es utilizado para imprimir los nodos en
    // orden ascendente.
    // --------------------------------------------------------------------------
    void BinaryTree::inorderTransveral(Node* node) const
    {
        if (node)
        {
            inorderTransveral(node->left);           // Recorrer subárbol izquierdo.
            std::cout << node->data << " ";          // Imprimir el dato del nodo actual.
            inorderTransveral(node->right);          // Recorrer subárbol derecho.
        }
    }

    // --------------------------------------------------------------------------
    // Función inorder (pública)
    // Inicia el recorrido inorden a partir de la raíz del árbol y luego imprime
    // un salto de línea.
    // --------------------------------------------------------------------------
    void BinaryTree::inorder() const
    {
        inorderTransveral(root);
        std::cout << std::endl;
    }

} // Fin del namespace DataStructure
