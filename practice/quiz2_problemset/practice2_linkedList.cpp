#include <iostream>
#include <string>
using namespace std;

class LinkedStack
{
private:
      struct Node
      {
            string data;
            Node *next;
      };
      Node *top;

public:
      LinkedStack();
      ~LinkedStack();

      void push(const string &item);
      void pop();
      string peek() const;

      bool is_empty() const;
      int size() const;
      void clear_all();
};

LinkedStack::LinkedStack()
{
      top = nullptr;
}
LinkedStack::~LinkedStack()
{
      clear_all();
}

void LinkedStack::push(const string &item)
{
      top = new Node{item, top};
}

void LinkedStack::pop()
{
      Node *temp = top;
      top = top->next;
      delete temp;
}

string LinkedStack::peek() const
{
      return top->data;
}
bool LinkedStack::is_empty() const
{
      return top == nullptr;
}

int LinkedStack::size() const
{
      // O(n)
      int count = 0;
      Node *cur = top;

      while (cur != nullptr)
      {
            count++;
            cur = cur->next;
      }

      return count;
}

void LinkedStack::clear_all()
{
      while (top != nullptr)
      {
            pop();
      }
}
