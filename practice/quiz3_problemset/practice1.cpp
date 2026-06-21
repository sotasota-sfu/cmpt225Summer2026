#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue
{
public:
      void insert(const T &item);

      void remove_min();

      T min() const;

      int size() const;

      bool is_empty() const;
};

//(b)
// insert().... O(n)
// min_remove().... O(1)
//min().... O(1)
// size().... O(1)
// is_empty().... O(1)

//(c)
// insert().... O(logn)
// min_remove().... O(logn)
// min....O(1)
// size.... O(1)
// is_empty().... O(1)