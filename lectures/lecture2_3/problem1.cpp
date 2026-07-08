// problem1.cpp

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

struct Node {
    string data;
    Node* next;
};


int main()
{
    // "LAX" --> "MSP" --> "ATL" --> "BOS" --> nullptr
    Node* head = nullptr;  // empty list
    head = new Node{"LAX", nullptr}; // one item
    
    // add second node
    head->next = new Node{"MSP", nullptr};

    // add third node
    head->next->next = new Node{"ATL", nullptr};

    // add fourth node
    head->next->next->next = new Node{"BOS", nullptr};

    // Node* p = head; // init
    // while (p != nullptr) { // cond
    //     cout << p->data << " "; 
    //     p = p->next; // increment
    // }

    for (Node* p = head; // init
         p != nullptr;  // cond
         p = p->next // increment
        ) 
    {
        cout << p->data << " "; // body
    }

    // invariant: p == nullptr
    cout << endl;

    // get size
    int count = 0;
    Node* p = head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    cout << "Size: " << count << endl;

    // cout << " First value: " << head->data << endl;  // LAX
    // cout << "Second value: " << head->next->data << endl; // MSP
    // cout << " Third value: " << head->next->next->data << endl; // ATL
    // cout << "Fourth value: " << head->next->next->next->data << endl; // BOS

    delete head->next->next->next; // de-allocate fourth node
    delete head->next->next; // de-allocate third node
    delete head->next; // de-allocate second node
    delete head; // de-allocate first node
} // main
