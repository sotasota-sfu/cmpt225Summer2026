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

struct Node
{
      string data;
      Node *next;
};

int main()
{
      Node *head = nullptr;
      head = new Node{"Lax", nullptr}; // add a new node
      // head --> "BOS" --> nullptr

      //add second Node
      head->next  = new Node{"MSP", head};

      //add third Node
      head->next->next = new Node{"ATL", nullptr};

      //add fourth Node
      head->next->next->next = new Node{"BOS", nullptr};

      //while loop
      Node* p = head;
      while(p != nullptr){
            cout << p->data << " ";
            p = p->next;
      }
      // invariant: p == nullptr
      cout << endl;

      //for loop
      for(Node* p = head; //initialization
            p != nullptr; //condition
            p = p->next // increment
      )
      {
            cout << p->data << " ";
      }

      //how many Node 
      Node *h = head;
      int count = 0;
      while (h != nullptr)
      {
            count++;
            p = p->next;
      }
      cout << "Size" << count << endl;
      //cout << "First value: " << head->data << endl;
      //cout << "Second value: " << head->next->data << endl;
      //cout << "Third value: " << head->next->next->data << endl;
      //cout << "Fourth value: " << head->next->next->next->data << endl;

      delete head->next->next->next;
      delete head->next->next;
      delete head->next;
      delete head; // de-allocate
} // main
