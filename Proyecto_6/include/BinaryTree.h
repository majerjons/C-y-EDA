#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

namespace DataStructure
{
    //Nodos del arbol binario
    class Node
    {
        public:
            int data;
            Node* left;
            Node* right;

            Node(int d);
    };

    //Arbol de Binary Search
    class BinaryTree
    {
        private:
            Node* root;
            Node* insert (Node* node, int data);
            void inorderTransveral (Node* node) const;
            void destroyTree (Node* node);
        
        public:
            BinaryTree();
            ~BinaryTree();

            void insert (int data);
            void inorder () const;
    };

}

#endif