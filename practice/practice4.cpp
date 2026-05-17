#include <iostream>
#include <string>
using namespace std;

struct Node
{
      string data;
      Node *next;
      Node *prev;
};

Node* head = nullptr;
Node* tail = nullptr;

bool is_empty_list()
{
      return head == nullptr;
}

void print()
{
      Node *p = head;
      while (p != nullptr)
      {
            cout << p->data << " ";
            p = p->next;
      }
      cout << endl;
}

void push_front(const string &value)
{
      Node *p = new Node;
      p->data = value;
      p->next = head;
      p->prev = nullptr;

      if(head != nullptr)
            head->prev = p;
      else
            tail = p;
      
      head = p;
}

void remove_front()
{
      if (is_empty_list())
            return;
      Node* p = head;
      head = head->next;

      if(head != nullptr)
            head->prev = nullptr;
      else
            tail = nullptr;
      delete p;
}

void clear_loop()
{
      Node *p = head;
      while (p != nullptr)
      {
            Node *temp = p;
            p = p->next;
            delete temp;
      }
      head = nullptr;
      tail = nullptr;
}

void clear_rec(){
      clear_helper(head);
      head = nullptr;
      tail = nullptr;
}

void clear_helper(Node* p){
      if(p == nullptr)
            return;
      clear_helper(p->next);
      delete p;
}
int size_loop()
{
      Node *p = head;
      int count = 0;
      while (p != nullptr)
      {
            count++;
            p = p->next;
      }
      return count;
}

int size_rec()
{
      return size_helper(head);
}
int size_helper(Node *p)
{
      if (p = nullptr)
            return 0;
      return 1 + size_helper(p->next);
}

bool contains_loop(const string &value)
{
      Node *p = head;
      while (p != nullptr)
      {
            if (p->data == value)
                  return true;
            p = p->next;
      }
      return false;
}

bool contains_rec(const string &value)
{
      return contains_helper(head, value);
}
bool contains_helper(Node *p, const string &value)
{
      if (p == nullptr)
            return false;
      if (p->data == value)
            return true;
      return contains_helper(p->next, value);
}

Node *last_node()
{
      return tail;
}

void push_back(const string &value)
{
      Node *p = new Node;
      p->data = value;
      p->next = nullptr;
      p->prev = tail;

      if(tail != nullptr)
            tail->next = p;
      else
            head = p;

      tail = p;
}

void remove_back()
{
      if (is_empty_list())
            return;

      Node* p = tail;
      tail = tail->prev;

      if(tail != nullptr)
            tail->next = nullptr;
      else
            head = nullptr;
      delete p;

}
