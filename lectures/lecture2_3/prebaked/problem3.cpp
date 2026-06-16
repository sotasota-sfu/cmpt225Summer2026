// problem3.cpp

#include <iostream>

using std::cout;
using std::endl;
using std::string;

//
// Starting from the solution to problem 2, rewrite the code in a class called
// List. All the functions should be methods. The initial list should be empty,
// and the destructor clear the list.
//

class List{
private:
    struct Node{
        string data;
        Node* next;
    };
    Node* head = nullptr;

public:
    ~List(){
        clear_list();
    }

    bool is_empty()
    {
        return (head == nullptr);
    }

    void print()
    {
        for (Node *p = head; p != nullptr; p = p->next)
        {
            cout << p->data << " " << endl;
        }
    }

    int size()
    {
        int count = 0;
        for (Node *p = head; p != nullptr; p = p->next)
        {
            count++;
        }
        return count;
    }

    void add_front(string value)
    {
        head = new Node{value, head};
    }

    void remove_front()
    {
        if (is_empty())
        {
            return;
        }

        Node *p = head;
        head = head->next;
        delete p;
    }

    void clear_list()
    {
        while (!is_empty())
        {
            remove_front();
        }
    }
};
int main()
{
    List airports;

    airports.add_front("BOS");
    airports.add_front("ATL");
    airports.add_front("MSP");
    airports.add_front("LAX");

    airports.print();
    cout << "Size: " << airports.size() << endl;

    // // destructor called automatically: no memory leak
} // main
