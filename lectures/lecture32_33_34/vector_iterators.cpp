// vector_iterators.cpp

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void demo1()
{
    cout << "demo1 ..." << endl;
    vector<int> v = {7, 9, 2, 1, 8, 6, 4, 3, 5};

    // p is like a pointer to an int in the vector v
    for (vector<int>::iterator p = v.begin(); p != v.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // the type name is so long that we usually use auto
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // you can also call begin and end functions (instead of v.begin() and
    // v.end())
    for (auto p = begin(v); p != end(v); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // if you want to iterator over the entire vector, you can use the
    // range-based for loop, which is "syntactic sugar" for the iterator loop
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    // vectors also have reverse iterators
    for (auto p = v.rbegin(); p != v.rend(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

void demo2()
{
    cout << "demo2 ..." << endl;
    vector<int> v = {7, 9, 2, 1, 8, 6, 4, 3, 5};

    // sorting using std::sort uses iterators
    sort(v.begin(), v.end());
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // an easy trick for sorting in reverse is to sort in ascending order and
    // then reverse the vector and then call reverse()
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // std::sort can also sort regular arrays
    
    sort(arr, arr + 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // you can print regular arrays treating the pointers like iterators
    for (auto p = begin(arr); p != end(arr); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    // or use the range-based for loop
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

// sums the elements in the range [begin, end); note that this function does not
// have direct access to the vector, it only has the iterators (pointers) to it
int sum(vector<int>::iterator begin, vector<int>::iterator end)
{
    int total = 0;
    for (auto p = begin; p != end; p++)
    {
        total += *p;
    }
    return total;
}

void demo3()
{
    cout << "demo3 ..." << endl;
    vector<int> v = {7, 9, 2, 1, 8, 6, 4, 3, 5};
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl; 
    cout << "sum of v: " << sum(v.begin(), v.end()) << endl;
    cout << "sum of v, excluding first and last: " << sum(v.begin() + 1, v.end() - 1)
         << endl;
}

int main()
{
    demo1();
    demo2();
    demo3();
} // main
