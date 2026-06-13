#include <iostream>
#include <string>
using namespace std;

class ArrayQueue
{
private:
      string *data;
      int capacity;
      int front;
      int back;
      int count;

public:
      ArrayQueue();
      ~ArrayQueue();

      void enqueue(const string &item);
      void dequeue();
      string peek_front() const;
      int size() const;
      bool is_empty() const;
      void remove_all();
};

ArrayQueue::ArrayQueue() {
      capacity = 100;
      data = new string[capacity];
      front = 0;
      back = -1;
      count = 0;
}

ArrayQueue::~ArrayQueue()
{
      delete[] data;
}

void ArrayQueue::enqueue(const string &item)
{
      back++;
      data[back] = item;
      count++;
}

void ArrayQueue::dequeue()
{
      if(is_empty())
            return;
      front++;
      count--;

      if(count == 0)
      {
            front = 0;
            back = -1;
      }
}

string ArrayQueue::peek_front() const
{
      return data[front];
}

int ArrayQueue::size() const
{
      return count;
}

bool ArrayQueue::is_empty() const
{
      return count == 0;
}

void ArrayQueue::remove_all()
{
      front = 0;
      back = -1;
      count = 0;
}
