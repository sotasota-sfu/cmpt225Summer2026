#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
      struct Node
      {
            string data;
            Node *prev;
            Node *next;
      };

      Node *head;
      Node *tail;
      int count;

public:
      Deque();
      ~Deque();

      bool is_empty() const;
      int size() const;

      string front() const;
      string back() const;

      void insertFront(const string &e);
      void insertBack(const string &e);

      void removeFront();
      void removeBack();

      void clear();
};

Deque::Deque()
{
      head = nullptr;
      tail = nullptr;
      count = 0;
}

Deque::~Deque()
{
      clear();
}

bool Deque::is_empty() const
{
      return count == 0;
}

int Deque::size() const
{
      return count;
}

string Deque::front() const
{
      return head->data;
}

string Deque::back() const
{
      return tail->data;
}

void Deque::insertFront(const string &e)
{
      Node *p = new Node{e, nullptr, head};

      if (is_empty())
      {
            tail = p;
      }
      else
      {
            head->prev = p;
      }

      head = p;
      count++;
}

void Deque::insertBack(const string &e)
{
      Node *p = new Node{e, tail, nullptr};

      if (is_empty())
      {
            head = p;
      }
      else
      {
            tail->next = p;
      }

      tail = p;
      count++;
}

void Deque::removeFront()
{
      if (is_empty())
            return;

      Node *p = head;
      head = head->next;

      if (head == nullptr)
      {
            tail = nullptr;
      }
      else
      {
            head->prev = nullptr;
      }

      delete p;
      count--;
}

void Deque::removeBack()
{
      if (is_empty())
            return;

      Node *p = tail;
      tail = tail->prev;

      if (tail == nullptr)
      {
            head = nullptr;
      }
      else
      {
            tail->next = nullptr;
      }

      delete p;
      count--;
}

void Deque::clear()
{
      while (!is_empty())
      {
            removeFront();
      }
}