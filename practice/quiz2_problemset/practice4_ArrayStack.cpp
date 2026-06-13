#include <iostream>
#include <string>
using namespace std;

class ArrayStack
{
private:
      string *data;
      int capacity;
      int top;

public:
      ArrayStack();
      ~ArrayStack();

      void push(const string &data);
      void pop();
      string peek() const;
      int size() const;
      bool is_empty() const;
      void clear_all();
};

ArrayStack::ArrayStack() { new string[capacity], 100, -1; }

ArrayStack::~ArrayStack()
{
      delete[] data;
}

void ArrayStack::push(const string &item)
{
      top++;
      data[top] = item;
}

void ArrayStack::pop()
{
      top--;
}

string ArrayStack::peek() const
{
      return data[top];
}

int ArrayStack::size() const
{
      return top + 1;
}

bool ArrayStack::is_empty() const
{
      return top == -1;
}

void ArrayStack::clear_all()
{
      top = -1;
}

bool is_marched(string str)
{
      ArrayStack s;

      for (int i = 0; i < str.size(); i++)
      {
            char c = str[i];

            if (c == '(' || c == '{' || c == '[')
            {
                  s.push(string(1, c));
            }
            else if (c == ')' || c == '}' || c == ']')
            {
                  if (s.is_empty())
                        return false;

                  string top = s.peek();
                  if (c == ')' && top != "(")
                        return false;
                  else if (c == '}' && top != "{")
                        return false;
                  else if (c == ']' && top != "[")
                        return false;
                  s.pop();
            }
      }
      return s.is_empty();
}