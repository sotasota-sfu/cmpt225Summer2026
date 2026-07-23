# interact.py

import json

graph_file = "word_graph.json"

# read in the adjacency list
with open(graph_file, "r") as f:
    neighbors = json.load(f)

print(f"loaded {len(neighbors)} words from {graph_file}")

while True:
    word = input("Enter a word: ")
    if word not in neighbors:
        print(f"{word} has no neighbors")
    else:
        related = neighbors[word]
        related.sort()
        words = ', '.join(related)
        print(f"{len(related)} related words\n{words}\n")
