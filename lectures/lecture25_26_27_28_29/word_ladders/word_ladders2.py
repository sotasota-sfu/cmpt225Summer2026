# word_ladders2.py

# A more efficient implementation of the word ladder problem using a deque, which is
# a double-ended queue.

import json

graph_file = "word_graph.json"

# read in the adjacency list
with open(graph_file, "r") as f:
    neighbors = json.load(f)

print(f"loaded {len(neighbors)} words from {graph_file}")

from collections import deque

def find_word_ladder(start, end):
    if start not in neighbors or end not in neighbors:
        return '<no ladder>'
    if start == end:
        return [start]

    queue = deque([start])
    parent = {start: None}

    while queue:
        word = queue.popleft()
        for n in neighbors[word]:
            if n not in parent:
                parent[n] = word  # word comes before n in the ladder
                if n == end: # done, found the end word
                    # reconstruct the path from end to start
                    path = [end]
                    while path[-1] != start:
                        path.append(parent[path[-1]])
                    path.reverse()
                    return path
                queue.append(n) # not the end word, so add it to the queue

    return '<no ladder>'

while True:
    start = input("Enter a start word: ")
    end = input("Enter an end word: ")
    ladder = find_word_ladder(start, end)
    words = ', '.join(ladder)
    print(words)
    print()

#
# sample output
#

# Enter a start word: cat
# Enter an end word: dog
# cat, cot, dot, dog

# Enter a start word: fried
# Enter an end word: candy
# fried, wried, wries, writs, waits, wants, cants, canty, candy

# Enter a start word: field
# Enter an end word: mouse
# <no ladder>
