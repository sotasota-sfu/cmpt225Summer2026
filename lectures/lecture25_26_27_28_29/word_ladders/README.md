# Word Ladders

A word ladder is a sequence of words where each word is one letter different from the previous word. For example here is a word ladder from `cat` to `dog`:

```
cat
cot
dot
dog
```

## Graph Representation

We can use a graph to find word ladders. 

The file [enable1.txt](enable1.txt) contains a long list of English words, and
we can make a graph as follows:

- Every word is a vertex in the graph.
- Two words (vertices) are connected by an edge if they are one letter different
  (and the same length). Run [interact.py](interact.py) to see the neighbors of
  a word.

The graph is represented as an **adjacency list** in the file
[word_graph.json](word_graph.json). For example:

```
"shoe": ["sloe", "shod", "shog", "shoo", "shop", "shot", "show"]
```

This means that the word `shoe` is connected to --- one letter different from
--- the words `sloe`, `shod`, `shog`, ... etc.

Some words have no neighbors. For example:

```
"circuses": []
```

This means there is no word that is one letter different than `circuses`. To
save storage space, we will only store words that have at least one
neighbor.

The graph was made by the Python program [make_graph.py](make_graph.py). It
reads [enable1.txt](enable1.txt), and creates the graph as a *dictionary* (map)
where the keys are the words and the values are lists of words that are one
letter different.

To save storage space, words with no neighbors were not stored, i.e. the graph
only contains words with at least one neighbor.

The program [graph_stats.py](graph_stats.py) prints some statistics about the
graph:

```
loaded 80602 words from word_graph.json
number of nodes: 80602
number of edges: 135071
 average degree: 3.35
```

The average degree is 3.35, which means that on average, each word is connected
to 3.35 other words.

## Finding Word Ladders

The program [word_ladders2.py](word_ladders2.py) finds word ladders using a
breadth-first search (BFS) algorithm. It starts at the start word and uses
breadth-first search to check all neighboring words until it reaches the end
word or it finds no ladder.

The breadth-first search is implemented using a queue. The initial word is added
to the queue, and the neighbors of each word are added to the queue. This makes
the search go level by level, checking all words at the current level before
moving on to the next level. The `parent` dictionary keeps track of the parent
word for each word, so that the path can be reconstructed when the end word is
found.

Here are some sample runs:

```
Enter a start word: cat
Enter an end word: dog
cat, cot, dot, dog

Enter a start word: fried
Enter an end word: candy
fried, wried, wries, writs, waits, wants, cants, canty, candy

Enter a start word: field
Enter an end word: mouse
<no ladder>
```
