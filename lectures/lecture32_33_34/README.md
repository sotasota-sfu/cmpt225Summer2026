# OOP and Iterators

This directory contains notes and code examples for implementing OOP and
iterators for data structures and algorithms in C++.

We recommend you go through the codes example in this order:

- [creatures.cpp](creatures.cpp): This example shows how to use abstract base
  classes and inheritance to create a hierarchy of creature objects.

- [stack_demo.cpp](stack_demo.cpp): This example shows how to use an abstract
  base class to implement a stack data structure. It provides two different
  implementations, one using a vector and one using a list, and both use stack
  base class and so they share the same interface. The `test_Stack(Stack_base*
  stack)` is an example of **runtime polymorphism**: you can pass it a pointer
  to any type of `Stack_base` object and the correct methods will be called at
  runtime.

- [iterator_fib.cpp](iterator_fib.cpp): This example demonstrates the basic idea
  of an iterator using the Fibonacci sequence. Compared to most iterators, this
  is an infinite iterator (because the Fibonacci sequence is infinite), and so
  there is no need to check if there is a next element.

- [iterator_demo.cpp](iterator_demo.cpp): This example shows how to use an
  **iterator** to access the elements of a collection without needing access to
  the implementation details of the collection.

- [oop_stack.cpp](oop_stack.cpp): This example shows how to use both the
  abstract base class and the iterator to implement a stack data structure.
