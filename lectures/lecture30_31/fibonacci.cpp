// fibonacci.cpp

// #define NDEBUG // uncomment this line to disable assertions
#include <cassert>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

vector<int> fib_values = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

// takes an int to int function and tests that it generates Fibonacci numbers;
// assumes n >= 1, i.e. the first Fibonacci number is fib(1) = 1
void test_fib(const string& name, int (*fib)(int))
{
    cout << "Testing " << name << "..." << endl;
    for (int n = 1; n <= fib_values.size(); n++)
    {
        int actual = fib(n);
        if (actual != fib_values[n - 1])
        {
            cout << "test_fib error: fib(" << n << ") returned     : " << actual;
            cout << "            but fib(" << n << ") should return: " << fib_values[n - 1] << endl;
            return;
        }
    }
    cout << "... " << name << "all tests passed!" << endl;
}

double time_fib(const string& name, int (*fib)(int))
{
    cout << "Timing " << name << "..." << endl;
    //
    // clock() measures CPU time
    //
    clock_t start = clock();
    for (int n = 1; n <= 40; n++)
    {
        cout << fib(n) << " ";
    }
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << endl;
    return time;
}

// standard recursive Fibonacci function; assumes n >= 1
int fib_rec(int n)
{
    assert(n >= 1);
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

//
// fib_rec_counted counts the number of calls to the function
//
int count_calls = 0;
int _fib_rec_counted(int n)
{
    assert(n >= 1);
    count_calls++;
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return _fib_rec_counted(n - 1) + _fib_rec_counted(n - 2);
}

int fib_rec_counted(int n)
{
    count_calls = 0;
    return _fib_rec_counted(n);
}

void show_count_calls()
{
    for (int n = 1; n <= 40; n++)
    {
        int result = fib_rec_counted(n);
        cout << "fib_rec_counted(" << n << ") = " << result << ", calls: " << count_calls << endl;
    }
}

// iterative Fibonacci function; assumes n >= 1
int fib_iter(int n)
{
    assert(n >= 1);
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = a + b;
        a        = b;
        b        = temp;
    }
    return b;
}

//
// This is a memoized version of the Fibonacci function. It uses a vector to
// store the Fibonacci numbers as they are computed and so they never need to be
// re-computed.
//

vector<int> _memo;

int _fib_memoized(int n)
{
    assert(n >= 1);
    if (n <= _memo.size()) // return the memoized value if it exists
    {
        return _memo[n - 1];
    }
    int next = _fib_memoized(n - 1) + _fib_memoized(n - 2);
    _memo.push_back(next);
    return next;
}

int fib_memoized(int n)
{
    _memo = {1, 1}; // start with the first two Fibonacci numbers
    return _fib_memoized(n);
}

void correctness_tests()
{
    test_fib("fib_rec", fib_rec);
    test_fib("fib_iter", fib_iter);
    test_fib("fib_rec_counted", fib_rec_counted);
    test_fib("fib_memoized", fib_memoized);
}

void time_tests()
{
    double rec_time  = time_fib("fib_rec", fib_rec);
    double iter_time = time_fib("fib_iter", fib_iter);
    double memo_time = time_fib("fib_memoized", fib_memoized);
    cout << fixed; // print decimal digits with fixed precision
    cout << " rec_time: " << rec_time << endl;
    cout << "iter_time: " << iter_time << endl;
    cout << "memo_time: " << memo_time << endl;
    cout << "     fib_rec was " << rec_time / iter_time << " times slower than fib_iter" << endl;
    cout << "fib_memoized was " << memo_time / iter_time << " times slower than fib_iter" << endl;
    cout << "fib_memoized was " << rec_time / memo_time << " times faster than fib_rec" << endl;
}

int main()
{
    correctness_tests();
    // time_tests();
    // show_count_calls();
}
