#include <iostream>
#include <string>
using namespace std;

class ArrayStack
{
private:
      string* data;
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

ArrayStack::ArrayStack(){new string[capacity], 100, -1;}

ArrayStack::~ArrayStack(){
      delete[] data;
}

void ArrayStack::push(const string &item){
      top++;
      data[top] = item;
}

void ArrayStack::pop(){
      top--;
}

string ArrayStack::peek() const{
      return data[top];
}

int ArrayStack::size() const{
      return top + 1;
}

bool ArrayStack::is_empty() const{
      return top == -1;
}

void ArrayStack::clear_all(){
      top = -1;
}
