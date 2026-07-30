# make_graph.py

# given a word, find all the words that are one letter different from it
# (without changing the length of the word
def get_one_letter_different_words(w, word_list):
    result = []
    for i in range(len(w)):
        for c in "abcdefghijklmnopqrstuvwxyz":
            if c != w[i]:
                new_word = w[:i] + c + w[i + 1 :]
                if new_word in word_list: # O(1) look-up
                    result.append(new_word)
    return result


# read in the word list into a dictionary (hash table) so that look-ups are O(1)
word_list_name = "enable1.txt"
words = {w.strip().lower() for w in open(word_list_name)}

print(f"loaded {len(words)} words from {word_list_name}")

# now build an adjacency list of the words; each key is the word, and the value
# is the list of words that are one letter different from it
print("building adjacency list ...")
neighbors = {w: get_one_letter_different_words(w, words) for w in words}

print(f"removing words that have no neighbors...")
neighbors = {k:v for k, v in neighbors.items() if v != []}

import json
out_file = "word_graph.json"
print(f"saving adjacency list to file {out_file} ...")
with open(out_file, "w") as f:
    json.dump(neighbors, f)

print("done")
