# experiments.py

import os

def experiment_ospd():
    print('Experiment: ospd.txt (79,000 sorted words) ')
    os.system('./sorting ospd.txt')

def experiment_ospd_randomized():
    print('Experiment: ospd.txt (79,000 randomized words) ')
    os.system('./sorting --randomize ospd.txt')

def experiment_tiny_shakespeare():
    print('Experiment: tiny_shakespeare.txt (202,651 English words)')
    os.system('./sorting tiny_shakespeare.txt')

def experiment_tiny_shakespeare_unique():
    print('Experiment: tiny_shakespeare.txt (202,651 English words, duplicates removed)')
    os.system('./sorting --unique tiny_shakespeare.txt')

def experiment_bill_complete():
    print('Experiment: bill_complete.txt (2,145,564 words)')
    os.system('./sorting --unique --noslow bill_complete.txt')

def experiment_one_value():
    print('Experiment: one_value.txt (100,000 copies of the same value)')
    os.system('./sorting one_value.txt')

def experiment_two_values():
    print('Experiment: two_values.txt (100,000 copies of two different values, randomly ordered)')
    os.system('./sorting two_values.txt')

def experiment_half_sorted():
    print('Experiment: two_values.txt (100,000 copies 1st half random, 2nd half sorted)')
    os.system('./sorting half_random_half_sorted.txt')

# experiment_ospd()
# experiment_ospd_randomized()
# experiment_tiny_shakespeare()
# experiment_tiny_shakespeare_unique()
# experiment_bill_complete()
# experiment_one_value()
# experiment_two_values()
# experiment_half_sorted()
