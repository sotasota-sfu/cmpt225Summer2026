# graph_stats.py

import json

graph_file = "word_graph.json"

# read in the adjacency list
with open(graph_file, "r") as f:
    neighbors = json.load(f)

print(f"loaded {len(neighbors)} words from {graph_file}")

num_nodes = len(neighbors)
total_degree = sum(len(neighbors[word]) for word in neighbors)
average_degree = total_degree / num_nodes
num_edges = total_degree // 2
print(f"number of nodes: {num_nodes}")
print(f"number of edges: {num_edges}")
print(f" average degree: {average_degree}")
