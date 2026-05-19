// ll_problem2_sol.cpp

#include <iostream>

using std::cout;
using std::endl;
using std::string;

//
// Starting from the solution to problem 1, do the following:
//
// a. When the head pointer is nullptr, the list is empty. So, write a function
//    called is_empty() that returns true if the list is empty, false otherwise.
// b. Write a function called print() that prints the contents of the list in
//    order.
// c. Write a function called size() that returns the number of nodes in the
//    list.
// d. Write a function called add_front(string value) that adds a new node with
//    the given value to the front of the list.
// e. Write add a function called remove_front() that removes the first node
//    from the list
// f. Write a function called clear_list() that deletes all the nodes in the
//    list. Hint: use some of the functions you already wrote to make this
//    easier.
//

struct Node
{
    string data;
    Node* next;
};

Node* head = nullptr;

bool is_empty() {
    return head == nullptr;
}

void print(){
    if(is_empty())
        cout << "<empty list>\n" << endl;
    else{
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " " << endl;
            p = p->next;
        }
        cout << endl;
    }
}

int size(){
    int count = 0;
    Node *p = head;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}
void add_front(const string &s){
    head = new Node {s,head};
}

void remove_front(const string &s){
    if(is_empty())
        return;
    Node* p = head;
    head = head->next;
    delete p;
}

int main()
{
    head = nullptr;
    add_front("BOS");
    add_front("ATL");
    add_front("MSP");
    add_front("LAX");

    print();
    cout << "Size: " << size() << endl;

    // clear_list();
} // main
