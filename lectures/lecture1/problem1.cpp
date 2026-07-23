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

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    delete[] arr; // de-allocate array
}

void recursive_init(int *arr, int N, int i)
{
    if (N > i)
    {
        if (i % 3 == 0)
            arr[i] = 4;
        else if (i % 3 == 1)
            arr[i] = 5;
        else
            arr[i] = 9;
        recursive_init(arr, N, i + 1);
    }
}


void solution2(){
    const int N = 9;
    int arr[N];
    recursive_init(arr, N, 0);

    for (int i = 0; i < N; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main()
{
    solution2();
}
