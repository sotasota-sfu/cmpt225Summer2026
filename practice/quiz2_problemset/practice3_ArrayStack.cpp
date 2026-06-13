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

      void push(const string &);
      void pop();
      string peek() const;
      int size() const;
      bool is_empty() const;
      void clear_all();
};

ArrayStack::ArrayStack() {
      capacity = 100;
      data = new string[capacity];
      top = -1;
}

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

void reverse(string *arr, int n)
{
      ArrayStack s;

      for (int i = 0; i < n; i++)
      {
            s.push(arr[i]);
      }

      for (int i = 0; i < n; i++)
      {
            arr[i] = s.peek();
            s.pop();
      }
}

int main()
{
      int n = 5;

      string *arr = new string[n];

      arr[0] = "apple";
      arr[1] = "banana";
      arr[2] = "cat";
      arr[3] = "dog";
      arr[4] = "egg";

      cout << "Before: ";

      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }

      cout << endl;

      reverse(arr, n);

      cout << "After: ";

      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }

      cout << endl;

      delete[] arr;

      return 0;
}