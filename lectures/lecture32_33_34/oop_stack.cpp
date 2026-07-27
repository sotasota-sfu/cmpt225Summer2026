// oop_stack.cpp

//
// This file is an example of a stack implemented using the Stack_base class,
// and also the Iterator class.
//`

#include "iterator.h"
#include "stack_base.h"
#include <cassert>
#include <iostream>

using namespace std;

class Stack_list : public Stack_base
{
  private:
    struct Node
    {
        int value;
        Node* next;
    };
    Node* top;

  public:
    // constructor: create an empty stack
    Stack_list() : top(nullptr) {}

    // destructor: remove all nodes from the stack
    ~Stack_list()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top        = top->next;
            delete temp;
        }
    }

    void push(int value) override { top = new Node{value, top}; }

    void pop() override
    {
        if (top == nullptr)
        {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = top;
        top        = top->next;
        delete temp;
    }

    int peek() override
    {
        if (top == nullptr)
        {
            throw std::runtime_error("Stack is empty");
        }
        return top->value;
    }

    bool is_empty() override { return top == nullptr; }

    //
    // This is the iterator class for Stack_list.
    //
    class StackIterator : public Iterator<int>
    {
        Node* current;

      public:
        StackIterator(Node* start) : current(start) {}

        bool has_next() const override { return current != nullptr; }

        int next() override
        {
            int value = current->value;
            current   = current->next;
            return value;
        }
    };

    //
    // This is the iterator factory method for Stack_list.
    //
    StackIterator createIterator() { return StackIterator(top); }

}; // class Stack_list

void test_Stack(Stack_base* stack)
{
    assert(stack->is_empty());
    stack->push(1);
    assert(!stack->is_empty());
    assert(stack->peek() == 1);
    stack->push(2);
    assert(stack->peek() == 2);
    stack->push(3);
    assert(stack->peek() == 3);
    stack->pop();
    assert(stack->peek() == 2);
    stack->pop();
    assert(stack->peek() == 1);
    assert(!stack->is_empty());
}

void test_Stack_list()
{
    cout << "Testing Stack_list ... \n";
    Stack_list stack;
    test_Stack(&stack);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    auto iter = stack.createIterator();
    cout << "Printing the stack using an iterator ... \n";
    print(iter);
    cout << "Summing the stack using an iterator ... \n";
    cout << sum_list(iter) << endl;
    cout << "done" << endl;
} // test_Stack_list

int main()
{
    test_Stack_list();
} // main
