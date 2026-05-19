# Quiz 1 Problem Set

Quiz 1 will be based these parts of the textbook:

- Chapter 3: 3.1, 3.2, 3.3, 3.4, 3.5
- Chapter 4: 4.1, 4.2, 4.3

The questions on the quiz may refer to definitions, theorems, and examples from
the textbook. The questions could be of any type, and will be variations of the
questions below, or questions that are similar.

**Important**: *Treat these problem-sets as non-AI activities!* Turn of all AI
support and try to figure them out yourself by hand. Having AI or another
student do this for you will not help you learn. You must do the learning
yourself!


1. Implement **insertion sort** on an array of strings:

   ```cpp
   void insertion_sort(string arr[], int n) {
      // ...
   }
   ```

2. Implement a Tic Tac Toe board as a 2D array of characters, and set its
   entries so it looks like this:

   ```
   X . O
   O X X
   . . O

  Then write a function that prints it out on the console:

  ```cpp
  void print_board(char board[3][3]) {
    // ...
  }
  ```

3. Implement a singly-linked list of strings where nodes are defined like this:

   ```cpp
   struct Node {
      string data;
      Node* next;
   };

   Node* head = nullptr;
   ```

   `head` is a pointer to the first node in the list. Then write *and* test
   these functions:

   - `bool is_empty()` returns true if the list is empty, and false otherwise
   - `void print()` prints the list out on the console
   - `void push_front(const string& value)` adds a new node with the given value
     to the front of the list
   - `void remove_front()` removes the first node from the list; if the list is
     empty, does nothing
   - `void clear()` deletes all the nodes in the list; implement it both using a
     loop and using recursion.
   - `int size()` returns the number of nodes in the list; implement it both
     using a loop and using recursion.
   - `bool contains(const string& value)` returns `true` if the list contains a
     node with the given value, and `false` otherwise; implement it both using a
     loop and using recursion.
   - `Node* last_node()` returns a pointer to the last node in the list; returns
     `nullptr` if the list is empty
   - `void push_back(const string& value)` adds a new node with the given value
     to the end of the list
   - `void remove_back()` removes the last node from the list; if the list is
     the list is empty, does nothing

4. Re-do question 3, but this time as a doubly-linked list using this node:

   ```cpp
   struct Node {
      string data;
      Node* next;
      Node* prev;
   };

   Node* head = nullptr;
   Node* tail = nullptr;
   ```

5. List the names, and give examples, of each of the 7 functions used in the book.

6. State the textbook definition of $f(n)$ is $O(g(n))$.

7. Using the textbook definition of $f(n)$ is $O(g(n))$, give mathematical
   proofs of the following facts:

   a. $2n$ is $O(n)$
   
   b. $100n + 50$ is $O(n)$
   
   c. $n^2 + 3n - 5$ is $O(n^2)$
   
   d. $n^2$ is *not* $O(n)$
   
   e. $n^2$ is $O(n^3)$
   
   f. a polynomial of degree $k$ is $O(n^k)$
   
   g. $\log_2 n^3$ is $O(n)$
   
   h. $n^2 + n \log n + 1$ is $O(n^2)$

   i. $an^k$ is $O(n^k)$ for any positive constant $a$ and integer $k \geq 1$

   j. $an^k$ is **not** $O(n^(k-1))$ for any positive constant $a$ and integer
      $k \geq 1$

8. For each of the following algorithms, give the tightest $O$-notation bound
   for the worst-case running time of each algorithm.

   a. Sorting an array of $n$ integers using insertion sort

   b. Sorting an array of $5n$ integers using insertion sort

   c. Finding the min value of an a singly-linked list of $n$ integers

   d. Calculating $a^n$, where $a$ and $n$ are integers bigger than 1, and it does
      in the "obvious" method of repeated multiplication.

   e. Calculating $a^n$, where $a$ and $n$ are integers bigger than 1, and it does
      in the "repeated squaring" method (see section 4.2.6 of the textbook).
  
   f. Testing a doubly-linked list of $n$ integers is in sorted order from
      smallest to largest.

   g. Calculating the sum $1 + 2 + 3 + ... + n$ using a loop.

   h. Calculating the sum $1 + 2 + 3 + ... + n$ using recursion.
  
   i. Calculating the sum $1 + 2 + 3 + ... + n$ using the formula $\frac{n(n+1)}{2}$.

9. What is a **loop invariant**? Why would you use one? Give some examples of
   loop invariants for this loop:

   ```cpp
   for(int i = 0; i < n; i++) {
    }
   ```
