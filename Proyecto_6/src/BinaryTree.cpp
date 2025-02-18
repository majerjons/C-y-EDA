#include "../include/BinaryTree.h"

namespace DataStructure
{
    Node::Node(int d) : data(d), left(nullptr), right(nullptr)
    {

    }

    BinaryTree::BinaryTree() : root(nullptr)
    {

    }

    BinaryTree:: ~BinaryTree()
    {
        destroyTree(root);
    }

    void BinaryTree::destroyTree (Node* node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* BinaryTree::insert (Node* node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert (node->right, data);
        }
        return node;
    }

    void BinaryTree::insert (int data)
    {
        root = insert (root, data);
    }

    void BinaryTree::inorderTransveral (Node* node) const
    {
        if (node)
        {
            inorderTransveral (node->left);
            std::cout << node->data << " ";
            inorderTransveral (node->right);
        }
    }

    void BinaryTree::inorder() const
    {
        inorderTransveral (root);
        std::cout << std::endl;
    }

}