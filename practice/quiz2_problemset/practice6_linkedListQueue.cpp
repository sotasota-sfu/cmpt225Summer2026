#include <iostream>
#include <string>
using namespace std;

class LinkedQueue
{
private:
    struct Node
    {
        string data;
        Node *prev;
        Node *next;
    };

    Node *front;
    Node *back;
    int count;

public:
    LinkedQueue();
    ~LinkedQueue();

    void enqueue(const string &item);
    void dequeue();

    string peek_front() const;

    bool is_empty() const;
    int size() const;

    void remove_all();
};

LinkedQueue::LinkedQueue()
{
    front = nullptr;
    back = nullptr;
    count = 0;
}
LinkedQueue::~LinkedQueue() {
    remove_all();
}

void LinkedQueue::enqueue(const string &item)
{
    Node *p = new Node;
    p->data = item;
    p->next = nullptr;

    if (is_empty())
    {
        front = p;
        back = p;
    }

    else
    {
        back->next = p;
        back = p;
    }
    count++;
}
void LinkedQueue::dequeue() {
    if (is_empty())
    {
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    count--;

    if(count == 0)
    {
        front = nullptr;
        back = nullptr;
    }
}

string LinkedQueue::peek_front() const {
    return front->data;
}

bool LinkedQueue::is_empty() const {
    return front == nullptr;
}
int LinkedQueue::size() const {
    return count;
}

void LinkedQueue::remove_all() {
    while(!is_empty()){
        dequeue();
    }
}