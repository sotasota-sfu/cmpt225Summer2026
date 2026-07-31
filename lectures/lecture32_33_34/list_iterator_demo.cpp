// list_iterator_demo.cpp

#include "iterator.h"
#include <cassert>
#include <iostream>

using namespace std;

//
// This is a concrete class (i.e. a class with implementation for its methods)
// that implements a singly-linked list.
//
class LinkedList
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head = nullptr;

  public:
    void push_front(int value) { head = new Node{value, head}; }

    //
    // This is the iterator class for this linked list.
    //
    class List_forward_iterator : public Iterator<int>
    {
        Node* current;

      public:
        List_forward_iterator(Node* start) : current(start) {}

        bool has_next() const override { return current != nullptr; }

        int next() override
        {
            int value = current->data;
            current   = current->next;
            return value;
        }
    };

    // the user calls this when they want to get an iterator over the linked
    // list
    List_forward_iterator forward_iterator() { return List_forward_iterator(head); }
}; // class LinkedList

int main()
{
    cout << "Iterators ..." << endl;
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    cout << "Print the list using an iterator ..." << endl;
    auto iter = list.forward_iterator();
    print(iter);

    cout << "Sum the list using an iterator ..." << endl;
    iter = list.forward_iterator();
    cout << "Sum: " << sum_list(iter) << endl;
} // main
