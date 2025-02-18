#include "../include/LinkedList.h"

namespace DataStructure
{
    //Definicion de los metodos
    ListNode::ListNode(int d) : data(d), Next(nullptr)
    {

    }

    LinkedList::LinkedList() : Head(nullptr)
    {

    }

    LinkedList::~LinkedList()
    {
        ListNode* Current = Head;
        while (Current != nullptr)
        {
            ListNode* Aux = Current;
            Current = Current->Next;
            delete Aux;
        }
    }

    void LinkedList::insert (int d)
    {
        ListNode* newNode = new ListNode(d);
        if (Head == nullptr)
        {
            Head = newNode;
        }
        else
        {
            ListNode* Current = Head;
            while (Current->Next != nullptr)
            {
                Current = Current->Next;
            }
            Current->Next = newNode;
        }
    }

    void LinkedList::remove(int d)
    {
        if (Head == nullptr)
        {
            return;
        }
        if (Head->data == d)
        {
            ListNode* Aux = Head;
            Head = Head->Next;
            delete Aux;
            return;
        }
        ListNode* Current = Head;
        while (Current->Next != nullptr && Current->Next->data != d)
        {
           Current = Current->Next;
        }
        if (Current->Next != nullptr)
        {
            ListNode* Aux = Current->Next;
            Current->Next = Current->Next->Next;
            delete Aux;
        }
    }

    void LinkedList::print() const
    {
        ListNode* Current = Head;
        while (Current != nullptr)
        {
            std::cout << Current->data << " -> ";
            Current = Current->Next;
        }
        std::cout << "Null" << std::endl;
    }



}