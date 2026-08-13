// vector_spans.cpp

// This file uses features from C++20, and so must be compiled with the
// -std=c++20 flag or later.

//
// Since C++20, C++ has had spans, which are essentially a pointer plus a length
// that is used to refer to a contiguous range of elements in a vector (or other
// container). Languages like Go and Rust have this feature (called slices)
// built in, and it is often a nice alternative to using begin/end iterator
// pairs.
//

#include <iostream>
#include <span>
#include <vector>

using namespace std;

void print_range(span<int> s)
{
    for (auto& x : s)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

void demo1()
{
    cout << "demo1 ..." << endl;
    vector<int> v = {7, 9, 2, 1, 8, 6, 4, 3, 5};
    print_range(v);                     // whole vector, implicit conversion
    print_range(span(v).subspan(1, 3)); // elements [1..3], instead of v.begin()+1, v.end()-1
}

void demo2()
{
    cout << "demo2 ..." << endl;
    vector<int> v = {7, 9, 2, 1, 8, 6, 4, 3, 5};

    // std::ranges::sort is a range-based version of std::sort
    ranges::sort(v);
    print_range(v);
}

int main()
{
    demo1();
    demo2();
}
