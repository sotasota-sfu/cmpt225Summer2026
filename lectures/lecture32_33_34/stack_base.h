// stack_base.h

#pragma once  // prevent multiple inclusion

//
// This is an abstract base class for stacks. It defines the interface for all
// stacks, i.e. the essential operations that all stacks must support.
//
// The Stack_base class itself is an abstract base class, which means it does
// not implement any of the methods. Instead, the methods are declared to be =0,
// which means an inheriting classes must provide the implementation.
//
// The virtual keyword means that the methods can be overridden in an inheriting
// class. Indeed, because they have been declared to be =0, they must be
// overridden in an inheriting class.
//
// The Stack_base class declares a virtual destructor to ensure that the
// destructors in inherited classes are called correctly. A C++ base class
// should always provide a virtual destructor.
//
class Stack_base
{
  public:
    // destructor: C++ base classes should always have a virtual destructor so
    // that inheriting classes can implement their own destructor
    virtual ~Stack_base() {}

    // put a copy of the value on the top of the stack
    virtual void push(int value) = 0;

    // remove the top value from the stack
    virtual void pop() = 0;

    // return the top value from the stack
    virtual int peek() = 0;

    // return true if the stack is empty
    virtual bool is_empty() = 0;
}; // class Stack_base
