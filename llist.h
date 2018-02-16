#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class J>
class llist
{
    public:
        llist();
        void insert_START(J p);
        void delete_START();
        void insert_END(J p);
        void delete_END();
        void clear_List();
        void print();



        bool isEmpty();
        virtual ~llist();

    protected:

    private:
        struct node{

            J _info;
            node* next;

        };

        node *head;
        node *curr;
        node *temp;

};

#endif // LIST_H
template <class J>
llist<J>::llist()
{
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}
template <class J>
void llist<J>::insert_START(J p)
{
    node *n = new node;
    n->_info = p;
    n->next = nullptr;

    if(head == nullptr)
    {
        head = n;
    }
    else
    {
        n->next = head;

        head = n;

    }

}
template <class J>
void llist<J>::delete_START()
{
    curr = head;
    head = curr->next;

    delete head;
}

template <class J>
void llist<J>::insert_END(J p)
{
    node *n = new node;
    n->_info = p;
    n->next = nullptr;

    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = n;

    }
}
template <class J>
void llist<J>::delete_END()
{
    curr = head;

    while(curr->next != nullptr)
    {
        curr = curr->next;
    }

    delete curr;
}
template <class J>
bool llist<J>::isEmpty()
{
    return(head==nullptr);

}
template <class J>
void llist<J>::clear_List()
{
    while(head != nullptr)
        {
            curr = head;
            head = curr->next;

            delete curr;
        }

}
template <class J>
void llist<J>::print()
{
    curr = head;

        while (curr != nullptr){

            cout << curr->_info;
            curr = curr->next;
        }

        cout << endl;
}
template <class J>
llist<J>::~llist()
{
    if(this->isEmpty()==false)
    {
        while(head != nullptr)
        {
            curr = head;
            head = curr->next;

            delete curr;
        }
    }

    head = nullptr;
    curr = nullptr;
    temp = nullptr;


}
