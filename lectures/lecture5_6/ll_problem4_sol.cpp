// ll_problem4.cpp

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//
// Starting from the singly-linked list class from ll_problem3, do the
// following:
//
// 1. Replace the size() method so that it works in constant time, i.e. it
//    doesn't need to traverse the list every time it is called.
//
// 2. Add a private method called make_copy() that returns a pointer to the
//    first node of a new list that is a copy of the current list. (It's private
//    because it returns a pointer, and users should not know about this
//    implementation detail.) Should it be a const method?
//
// 3. Add a copy constructor that makes a new list by copying a given list. See
//    the copy_demo() function below for how it should work.
//
// 4. Add a method called append_copy(other) that appends a copy of the given
//    list to the end of the current list. See the append_copy_demo() function
//    below for how it should work. Should it be a const method?
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
    int sz     = 0;

    // returns a pointer to the new of a new list that is a copy of the given
    // list
    Node* copyList() const
    {
        if (head == nullptr)
            return nullptr;

        // current list has at least one node
        Node* newHead = new Node{head->data, nullptr};
        Node* curr    = head->next;
        Node* tail    = newHead;

        while (curr != nullptr)
        {
            tail->next = new Node{curr->data, nullptr};
            tail       = tail->next;
            curr       = curr->next;
        }

        return newHead;
    }

    // returns a pointer to the last node in the list; returns nullptr if the
    // list is empty
    Node* get_last() const
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        return p;
    }

  public:
    // default constructor: initialize the list to be empty
    List() : head(nullptr), sz(0) {}

    // copy constructor: make a new list by copying a given list
    List(const List& other) : head(copyList()), sz(other.sz) {}

    // destructor: deletes all nodes in the list
    ~List()
    {
        clear_list();
        cout << "destructor called!\n";
    }

    // return true if the list is empty, false otherwise
    bool is_empty() const { return head == nullptr; }

    // print the contents of the list
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

    // return the number of nodes in the list
    int size() const { return sz; }

    // add a new node with the given value to the front of the list
    void add_front(const string& value)
    {
        head = new Node{value, head};
        sz++;
    }

    // remove the first node in the list; if the list is empty, do nothing
    void remove_front()
    {
        if (is_empty())
        {
            return;
        }
        Node* p = head;
        head    = head->next;
        delete p;
        sz--;
    }

    // remove all nodes in the list
    void clear_list()
    {
        while (!is_empty())
        {
            remove_front();
        }
    }

    // append a copy of the given list to the end of the current list
    void append_copy(const List& other)
    {
        if (other.is_empty())
        {
            return;
        }
        else if (is_empty())
        {
            head = other.copyList();
            sz   = other.sz;
        }
        else
        {
            Node* last = get_last();
            last->next = copyList();
            sz += other.sz;
        }
    }

}; // class List

void airport_demo()
{
    List airports;
    assert(airports.is_empty());
    assert(airports.size() == 0);

    airports.add_front("BOS");
    assert(!airports.is_empty());
    assert(airports.size() == 1);

    airports.add_front("ATL");
    assert(!airports.is_empty());
    assert(airports.size() == 2);

    airports.add_front("MSP");
    assert(!airports.is_empty());
    assert(airports.size() == 3);

    airports.add_front("LAX");
    assert(!airports.is_empty());
    assert(airports.size() == 4);

    airports.print();
    cout << "Size: " << airports.size() << endl;

    airports.remove_front();
    assert(!airports.is_empty());
    assert(airports.size() == 3);

    airports.remove_front();
    assert(!airports.is_empty());
    assert(airports.size() == 2);

    airports.remove_front();
    assert(!airports.is_empty());
    assert(airports.size() == 1);

    airports.remove_front();
    assert(airports.is_empty());
    assert(airports.size() == 0);
}

void copy_demo()
{
    cout << "\npets:\n";
    List pets;
    pets.add_front("dog");
    pets.add_front("cat");
    pets.add_front("bird");
    pets.print();
    cout << "Size: " << pets.size() << endl;

    cout << "\npets2 (copy of pets):\n";
    List pets2(pets);
    assert(pets2.size() == pets.size());
    assert(pets2.is_empty() == pets.is_empty());
    pets2.print();
    cout << "Size: " << pets2.size() << endl;
}

void append_copy_demo()
{
    List items;
    items.add_front("apples");
    items.add_front("bananas");

    List extra;
    extra.add_front("sun hat");
    extra.add_front("water bottle");
    extra.add_front("compass");

    items.append_copy(extra);
    assert(items.size() == 5);
    assert(extra.size() == 3);
    items.print();
    cout << "items size: " << items.size() << endl;

    extra.print();
    cout << "extra size: " << extra.size() << endl;
}

int main()
{
    // airport_demo();
    // copy_demo();
    append_copy_demo();
} // main
