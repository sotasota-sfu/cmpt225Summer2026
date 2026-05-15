// problem1_sol.cpp

#include <iostream>

using namespace std;

//
// Make a singly-linked list with these strings:
//
// head
//  |
//  v
// "LAX" --> "MSP" --> "ATL" --> "BOS" --> nullptr
//
// Then after the list is created, print the strings using
// a loop. Then, finally, de-allocate all the nodes.
//

struct Node
{
    string data;
    Node* next;
};

int main()
{
    Node* head = nullptr;
    head       = new Node{"BOS", nullptr}; // add a new node
    // head --> "BOS" --> nullptr

    head = new Node{"ATL", head}; // add a new node
    // head --> "ATL" --> "BOS" --> nullptr

    head = new Node{"MSP", head}; // add a new node
    // head --> "MSP" --> "ATL" --> "BOS" --> nullptr

    head = new Node{"LAX", head}; // add a new node
    // head --> "LAX" --> "MSP" --> "ATL" --> "BOS" --> nullptr

    //
    // print the list
    //
    Node* p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    //
    // de-allocate the list
    //
    while (head != nullptr)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }
} // main
