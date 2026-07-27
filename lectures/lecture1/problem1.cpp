// problem1_sol.cpp

#include <iostream>

using namespace std;

//
// Make an array of 3000 integers, and initialized with 4, 5, 9 repeated like
// this:
//
//     4, 5, 9, 4, 5, 9, 4, 5, 9, ..., 4, 5, 9
//
// Do it in two different ways: one way using a loop, and one way using
// recursion.
//

void solution1()
{
    const int N = 9;
    int* arr    = new int[N]; // allocate array

    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            arr[i] = 4;
        }
        else if (i % 3 == 1)
        {
            arr[i] = 5;
        }
        else
        {
            arr[i] = 9;
        }
    }

    delete[] arr; // de-allocate array
}

int main()
{
    solution1();
}
