# The Fibonacci Sequence and Memoization

Please see the slides [fibonacci.pptx](fibonacci.pptx) for a discussion of why
the Fibonacci numbers grow exponentially.

Then check out the code examples in this suggested order:

- [fibonacci.cpp](fibonacci.cpp) Has a few implementations of the Fibonacci
  sequence, each with its own performance characteristics. There is also code
  for testing it's correctness and performance.

  - `fib_rec` shows that a basic implementation of the Fibonacci recurrence
     relation grows exponentially. 
  - `fib_rec_counted` shows that the number of calls to `fib_rec` grows
     exponentially.
  - `fib_iter` shows that a loop-based implementation with no recursion is much
     faster, although the code is more complex.
  - `fib_memoized` shows that a memoized implementation of the Fibonacci
    sequence is much faster than the basic implementation, although again at the
    cost of more complex code. Arguably, this is more readable than `fib_iter`
    because the original recursive definition is visible in the code.

- [fibonacci_memo.cpp](fibonacci_memo.cpp) Shows a general-purpose memoization
  function in C++ that can be used to memoize any function. It uses some
  advanced C++ features that we will review briefly, but you don't need to know
  the details.

- [fib_memo.py](fib_memo.py) Shows a general-purpose memoization function in
  Python that can be used to memoize any function. It uses a decorator to
  memoize the function, and the resulting code is much more readable than the
  C++ version.
