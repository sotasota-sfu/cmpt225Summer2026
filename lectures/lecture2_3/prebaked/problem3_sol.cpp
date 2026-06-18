// problem3_sol.cpp

#include <iostream>

using std::cout;
using std::endl;
using std::string;

//
// Starting from the solution to problem 2, rewrite the code in a class called
// List. All the functions should be methods. The initial list should be empty,
// and the destructor clear the list.
//

class List
{
  private:
    struct Node
    {
        string data;
        Node* next;
    };

    Node* head = nullptr;

  public:
    // destructor: deletes all nodes in the list
    ~List() { clear_list(); }

    bool is_empty() { return head == nullptr; }

    void print()
    {
        Node* p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int size()
    {
        int count = 0;
        Node* p   = head;
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void add_front(string value) { head = new Node{value, head}; }

    void remove_front()
    {
        if (is_empty())
        {
            return;
        }
        Node* p = head;
        head    = head->next;
        delete p;
    }

    void clear_list()
    {
        while (!is_empty())
        {
            remove_front();
        }
    }

}; // class List

int main()
{
    List airports;

    airports.add_front("BOS");
    airports.add_front("ATL");
    airports.add_front("MSP");
    airports.add_front("LAX");

    airports.print();
    cout << "Size: " << airports.size() << endl;

    // destructor called automatically: no memory leak
} // main
