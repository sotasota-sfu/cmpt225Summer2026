# hash_fn.py

def sum_ascii(s):
    return sum(ord(c) for c in s)







# polynomial hash function for a string
def hash(s):
    h = 0
    for c in s:
        h = h * 31 + ord(c)
    return h

# In C++:
# int hash(const string &s)
# {
#     int h = 0;
#     for (char c : s)
#     {
#         h = h * 31 + c;
#     }
#     return h;
# }

# test the hash function
def test_hash():
    print(hash('hello'))
    print(hash('world'))
    print(hash('hello world'))
    print(hash('hello world'))
