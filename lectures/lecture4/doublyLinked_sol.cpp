// doublyLinked_sol.cpp

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//
// Implement a doubly linked list of strings. The list should have a constructor
// that initializes the list to empty, a destructor that clears the list, and a
// variety of useful methods.
//
// assert is used throughout to help catch bugs. In general, assert(expr) does
// nothing if expr is true, but crashes the program if expr is false. So if
// there are bugs the assertions will crash the program, and you can hopefully
// find the bug more quickly by seeing which assertion failed.
//

class DoublyLinkedList
{
  private:
    struct Node
    {
        string data;
        Node* next;
        Node* prev;
    };

    Node* head = nullptr;

    // check some invariants of the list to help catch bugs
    bool check_rep() const
    {
        if (head == nullptr)
        {
            assert(is_empty());
        }
        if (is_empty())
        {
            assert(head == nullptr);
        }

        if (!is_empty())
        {
            assert(head != nullptr);
            assert(head->prev == nullptr);
        }
        return true;
    }

    // get a pointer to the last node in the list
    Node* find_last() const
    {
        assert(!is_empty());

        // list has at least one node
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        return p;
    }

  public:
    // default constructor: initializes the list to empty
    DoublyLinkedList() : head(nullptr) { check_rep(); }

    // destructor: clears the list when the object is destroyed
    ~DoublyLinkedList() { clear_list(); }

    // returns true if the list is empty, false otherwise
    bool is_empty() const { return head == nullptr; }

    // returns the number of nodes in the list
    int size() const
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

    // prints the contents of the list in order
    void print() const
    {
        Node* p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // add a new node with the given value to the front of the list
    void add_front(const string& value)
    {
        // add to empty list
        if (is_empty())
        {
            head = new Node{value, nullptr, nullptr};
        }
        else
        {
            // add to a non-empty list
            Node* new_node = new Node{value, head, nullptr};
            head->prev     = new_node;
            head           = new_node;
        }
        check_rep();
    }

    // remove the first node from the list; if the list is empty, do nothing
    void remove_front()
    {
        if (is_empty())
        {
            return;
        }

        // there is a first node to delete
        Node* temp = head->next;
        delete head;
        head = temp;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        check_rep();
    }

    // remove all nodes from the list; if the list is empty, do nothing
    void clear_list()
    {
        while (!is_empty())
        {
            remove_front();
        }
        check_rep();
    }

    // return the value of the last node in the; error if the list is empty
    string get_last() const
    {
        assert(!is_empty());
        return find_last()->data;
    }

    // prints the contents of the list in reverse order
    void print_reverse() const
    {
        Node* last = find_last();
        while (last != nullptr)
        {
            cout << last->data << " ";
            last = last->prev;
        }
        cout << endl;
    }

}; // class DoublyLinkedList

int main()
{
    DoublyLinkedList airports;
    assert(airports.is_empty());
    assert(airports.size() == 0);

    airports.add_front("BOS");
    assert(!airports.is_empty());
    assert(airports.size() == 1);
    assert(airports.get_last() == "BOS");

    airports.add_front("ATL");
    assert(!airports.is_empty());
    assert(airports.size() == 2);
    assert(airports.get_last() == "BOS");

    airports.add_front("MSP");
    assert(!airports.is_empty());
    assert(airports.size() == 3);
    assert(airports.get_last() == "BOS");

    airports.add_front("LAX");
    assert(!airports.is_empty());
    assert(airports.size() == 4);
    assert(airports.get_last() == "BOS");

    // remove the items one at a time and print the list after each removal
    while (!airports.is_empty())
    {
        cout << "size=" << airports.size();
        cout << ", last=\"" << airports.get_last() << "\": ";
        airports.print_reverse();
        airports.remove_front();
    }

    // destructor called automatically: no memory leak
} // main
