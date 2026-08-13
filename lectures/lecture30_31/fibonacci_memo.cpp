// fibonacci_memo.cpp

//
// This shows how to use a general-purpose memoizer function to memoize a
// function like the Fibonacci function.
//
// It should work with almost any function -- even recursive functions -- that
// takes a single int argument and returns a single int value.
//
// It automatically saves the results of the function calls in a map so that the
// function does not need to be re-computed for the same argument. This can
// result in a significant speedup, although it may use more memory, and the
// complexity of the code is higher.
//

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

template <typename F> class Memoizer
{
    F function;
    std::unordered_map<int, int> cache;

  public:
    explicit Memoizer(F f) : function(std::move(f)) {}

    int operator()(int n)
    {
        if (auto it = cache.find(n); it != cache.end())
        {
            return it->second;
        }

        int result = function(*this, n);
        cache.emplace(n, result);
        return result;
    }
};

template <typename F> auto memoize(F f)
{
    return Memoizer<F>(std::move(f));
}

auto fib = memoize(
    [](auto& fib, int n) -> int
    {
        assert(n >= 1);
        if (n <= 2)
        {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    });

auto triangular = memoize(
    [](auto& triangular, int n) -> int
    {
        assert(n >= 0);
        if (n == 0)
        {
            return 0;
        }
        return n + triangular(n - 1);
    });


int main()
{
    cout << "Fibonacci numbers:" << endl;
    for (int n = 1; n <= 40; n++)
    {
        cout << fib(n) << " ";
    }
    cout << endl;

    cout << "Triangular numbers:" << endl;
    for (int n = 0; n <= 10; n++)
    {
        cout << triangular(n) << " ";
    }
    cout << endl;
}
