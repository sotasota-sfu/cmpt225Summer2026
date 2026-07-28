# fib_memo.py

#
# Demonstrates a general-purpose memoization function in Python. It lets you
# write a simple recursive function like fib, but without the exponential
# blowup.
#

from functools import wraps

def memoize(f):
    cache = {}
    @wraps(f) # keep f's name, docstring, etc.
    def wrapper(*args):
        if args not in cache:
            cache[args] = f(*args)
        return cache[args]
    return wrapper

@memoize # a decorator: it passes fib to memoize
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

@memoize
def triangular(n):
    if n == 0:
        return 0
    return n + triangular(n - 1)

print('       fib(100):', fib(100))  # instant, instead of exponential blowup
print('triangular(100):', triangular(100))
