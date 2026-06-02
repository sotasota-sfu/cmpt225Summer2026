// ll_problem3.cpp

#include <iostream>
#include <cassert>

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
    List() : head(nullptr){};

    ~List(){
        clear();
        cout << "destructor called!\n";
    }

    bool is_empty() const {return head == nullptr;}

    void print() const {
        Node* p = head;
        while(p != nullptr){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int size() const{
        int count = 0;
        Node* p = head;
        while(p != nullptr){
            count++;
            p = p->next;
        }
        return count;
    }

    void add_front(const string &s){head = new Node{s,head};}

    void remove_front(){
        if (is_empty())
        {
            return; // do nothing
        }
        else
        { // not empty
            assert(!is_empty());
            Node *p = head;
            head = head->next;
            delete p;
        }
    }

    void clear(){
        while(!is_empty()){
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
