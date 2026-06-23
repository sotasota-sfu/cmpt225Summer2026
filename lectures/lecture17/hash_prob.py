# hash_prob.py

# 
# To use this, choose a table size N and run do_experiment(num_trials) with a
# large number of trials. The program will print the average number of
# insertions before a collision occurs.
#
# For example, if you set N = 365, then the average number of insertions before
# a collision occurs is about 23 (the classic birthday problem result).
#

import random

#
# table size
#
N = 100

def do_one_trial():
    # initially empty table
    table = [0] * N

    # keep inserting keys until a collision occurs
    i = 0
    while True:
        key = random.randint(0, N-1)
        if table[key] == 0:
            table[key] = 1
        else:
            print(f"Collision! i={i}, N={N}, load factor={(i-1)/N}")
            return i
        i += 1

def do_experiment(num_trials):
    total = 0
    for i in range(num_trials):
        print(f'Trial {i} of {num_trials} ... ', end='')
        result = do_one_trial()
        total += result
    
    print(f'{num_trials} trials done.')
    print()
    print(f'table size N = {N}')
    print('Avg first collision after this many insertions:')
    print(f'{total / num_trials}')

do_experiment(1000)
