// iterator.h

#pragma once  // prevent multiple inclusion

#include <iostream>

using namespace std;

//
// This is an abstract base class for iterators. It defines the interface for
// iterators, which consists of two methods:
//
// - hasNext() returns true if there are more elements to iterate over, and
//   false otherwise
// - next() returns the next element in the collection; if there are no more
//   elements to iterator over, then it should throw an exception
//
// Both has_next() and next() are pure virtual methods, i.e. they have no
// implementation in the base class.
//
// Virtual means that a method can be overridden in an inheriting class. Indeed,
// because they have been declared to be =0, the methods in Iterator must be
// overridden in an inheriting class.
//
// The "template <typename T>" defines a template parameter T that is the type
// of the elements in the collection.
//
// Iterator declares a virtual destructor to ensure that the destructors in
// inherited classes are called correctly. A C++ base class should always
// provide a virtual destructor.
//
// This particular way of implementing iterators is a good introduction to the
// general idea of iterators. However, C++ implements its standard iterators in
// a different, much more flexible way (which we won't cover here). C++ standard
// iterators are designed to look and act like pointers.
//

template <typename T> class Iterator
{
  public:
    virtual ~Iterator() {}

    virtual bool has_next() const = 0;

    // assumes that has_next() is true
    virtual T next() = 0;
}; // class Iterator

//
// Sample functions to print and sum the list using an iterator.
//

//
// print takes an iterator over a collection of type T and prints the elements
// of the collection.
//
template <typename T> void print(Iterator<T>& iter)
{
    while (iter.has_next())
    {
        cout << iter.next() << endl;
    }
}

//
// sum_list requires an integer iterator over a collection of integers. Note
// that the type T must be a numeric type that supports the += operator.
//
template <typename T> T sum_list(Iterator<T>& iter)
{
    T total = 0;
    while (iter.has_next())
    {
        total += iter.next();
    }
    return total;
}
