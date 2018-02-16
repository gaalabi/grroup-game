#ifndef DLIST_H
#define DLIST_H
#include <iostream>

using namespace std;

template <class T>
class dList
{
    public:

        dList();
        void insert_START(T p);
        void delete_START();
        void insert_END(T p);
        void delete_END();
        void clear_List();
        void print();



        bool isEmpty();

        virtual ~dList();

    protected:

    private:
        struct node{

            T _info;
            node* prev;
            node* next;

        };

        node* head;
        node* tail;
        node* temp;
        node* curr;
        int _nodeCount;


};

#endif // DLIST_H

template <class T>
dList<T>::dList()
{
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
    temp = nullptr;
    _nodeCount = 0;

}

template <class T>
void dList<T>::insert_START(T p)
{
    node* n = new node;
    n->_info = p;
    n->next = nullptr;
    n->prev = nullptr;


    if(head == nullptr)
    {
        n->next = tail;
        n->prev = head;

        head = n;
        tail = n;
    }
    else
    {
        head->prev = n;
        n->next = head;

        head = n;
    }

    _nodeCount++;
}

template <class T>
void dList<T>::insert_END(T p)
{
    node* n = new node;
    n->_info = p;
    n->prev = nullptr;
    n->next = nullptr;

    if(head == nullptr)
    {
        n->next = tail;
        n->prev = head;

        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;

        tail = n;
    }

    _nodeCount++;

}

template <class T>
void dList<T>::delete_START()
{
    curr = head;
    head = curr->next;
    head->prev = nullptr;

    delete curr;
    _nodeCount--;
}
template <class T>
void dList<T>::delete_END()
{
    curr = tail;
    tail = curr->prev;
    tail->next = nullptr;

    delete curr;
    _nodeCount--;
}
template <class T>
void dList<T>::clear_List()
{
    curr = head;

    while(curr != nullptr)
    {
        head = curr->next;

        delete curr;
        _nodeCount--;

        curr = head;

    }


}
template <class T>

bool dList<T>::isEmpty()
{
    return(head == nullptr);
}

template <class T>
void dList<T>::print()
{
    if(this->isEmpty()==false)
    {
        curr = head;

        while(curr != nullptr)
        {
            cout << curr->_info << endl;
            curr = curr->next;
        }

        cout << _nodeCount << endl;
    }

}


template <class T>
dList<T>::~dList()
{
    if(this->isEmpty() == false)
    {
        this->clear_List();
    }


    head = nullptr;
    tail = nullptr;
    curr = nullptr;
    temp = nullptr;
}

