# word_ladders.py

import json

graph_file = "word_graph.json"

# read in the adjacency list
with open(graph_file, "r") as f:
    neighbors = json.load(f)

print(f"loaded {len(neighbors)} words from {graph_file}")

#
# This version works, but is quite slow (e.g. the queue is a list and each
# pop(0) is O(n) where n is the length of the queue.)
#
def find_word_ladder(start, end):
    if start not in neighbors or end not in neighbors:
        return '<no ladder>'
    if start == end:
        return [start]
    queue = [(start, [start])]
    while queue != []:
        word, path = queue.pop(0)
        if word == end:
            return path
        for n in neighbors[word]:
            if n not in path:
                queue.append((n, path + [n]))
    return '<no ladder>'

while True:
    start = input("Enter a start word: ")
    end = input("Enter an end word: ")
    ladder = find_word_ladder(start, end)
    print(ladder)
