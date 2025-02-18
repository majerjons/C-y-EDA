#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace DataStructure
{
    class ListNode  //objeto nodo para mi lista enlazada
    {
        public:
            int data;
            ListNode* Next;
            ListNode(int d);
    };

    class LinkedList
    {
        private:
            ListNode* Head;

        public:
        LinkedList();
        ~LinkedList();

        //metodos
        void insert (int d);
        void remove (int d);
        void print () const;
    };

}


#endif