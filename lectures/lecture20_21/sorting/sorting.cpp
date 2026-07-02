// sorting.cpp — compare quicksort, mergesort, heapsort, insertion sort, and std::sort

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using Clock = chrono::steady_clock;

struct Stats
{
    long long comparisons = 0;
};

bool less_than(const string& a, const string& b, Stats& stats)
{
    stats.comparisons++;
    return a < b;
}

bool greater_than(const string& a, const string& b, Stats& stats)
{
    stats.comparisons++;
    return a > b;
}

vector<string> read_words(const string& fname)
{
    ifstream infile(fname);
    if (!infile)
    {
        cerr << "Error: could not open file \"" << fname << "\"\n";
        exit(1);
    }

    vector<string> words;
    string word;
    while (infile >> word)
    {
        words.push_back(word);
    }
    return words;
}

vector<string> remove_duplicates(const vector<string>& words)
{
    unordered_set<string> seen;
    vector<string> unique_words;
    unique_words.reserve(words.size());
    for (const string& word : words)
    {
        if (seen.insert(word).second)
        {
            unique_words.push_back(word);
        }
    }
    return unique_words;
}

bool is_sorted(const vector<string>& v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            return false;
        }
    }
    return true;
}

//
// Insertion sort — O(n^2) worst case
//
void insertion_sort(vector<string>& v, Stats& stats)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        string key = v[i];
        int j      = static_cast<int>(i) - 1;
        while (j >= 0 && greater_than(v[j], key, stats))
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

//
// Merge sort — O(n log n) worst case
//
void merge_sort(vector<string>& v, Stats& stats)
{
    if (v.size() <= 1)
    {
        return;
    }

    size_t mid = v.size() / 2;
    vector<string> left(v.begin(), v.begin() + mid);
    vector<string> right(v.begin() + mid, v.end());

    merge_sort(left, stats);
    merge_sort(right, stats);

    vector<string> merged;
    merged.reserve(v.size());

    size_t i = 0;
    size_t j = 0;
    while (i < left.size() && j < right.size())
    {
        if (less_than(left[i], right[j], stats))
        {
            merged.push_back(left[i]);
            i++;
        }
        else
        {
            merged.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        merged.push_back(right[j]);
        j++;
    }

    v = std::move(merged);
}

//
// Heapsort — O(n log n) worst case
//
void sift_down(vector<string>& v, int start, int end, Stats& stats)
{
    int root = start;
    while (true)
    {
        int largest = root;
        int left    = 2 * root + 1;
        int right   = 2 * root + 2;

        if (left <= end && less_than(v[largest], v[left], stats))
        {
            largest = left;
        }
        if (right <= end && less_than(v[largest], v[right], stats))
        {
            largest = right;
        }
        if (largest == root)
        {
            return;
        }

        swap(v[root], v[largest]);
        root = largest;
    }
}

void heap_sort(vector<string>& v, Stats& stats)
{
    if (v.size() <= 1)
    {
        return;
    }

    int last = static_cast<int>(v.size()) - 1;
    for (int start = last / 2; start >= 0; start--)
    {
        sift_down(v, start, last, stats);
    }

    for (int end = last; end > 0; end--)
    {
        swap(v[0], v[end]);
        sift_down(v, 0, end - 1, stats);
    }
}

//
// Quicksort — O(n log n) average, O(n^2) worst case
//
int partition(vector<string>& v, int start, int end, Stats& stats)
{
    string pivot = v[end];
    int i        = start;
    for (int j = start; j < end; j++)
    {
        if (less_than(v[j], pivot, stats))
        {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[end]);
    return i;
}

void quick_sort(vector<string>& v, int start, int end, Stats& stats)
{
    if (start >= end)
    {
        return;
    }
    int pivot = partition(v, start, end, stats);
    quick_sort(v, start, pivot - 1, stats);
    quick_sort(v, pivot + 1, end, stats);
}

void quick_sort(vector<string>& v, Stats& stats)
{
    if (v.empty())
    {
        return;
    }
    quick_sort(v, 0, static_cast<int>(v.size()) - 1, stats);
}

//
// Randomized quicksort — random pivot each partition; O(n log n) average
//
int rand_int(int lo, int hi)
{
    return rand() % (hi - lo + 1) + lo;
}

void randomize_words(vector<string>& words)
{
    for (int i = static_cast<int>(words.size()) - 1; i > 0; i--)
    {
        int j = rand_int(0, i);
        swap(words[i], words[j]);
    }
}

void randomized_quick_sort(vector<string>& v, int start, int end, Stats& stats)
{
    if (start >= end)
    {
        return;
    }
    int pivot_index = rand_int(start, end);
    swap(v[pivot_index], v[end]);
    int pivot = partition(v, start, end, stats);
    randomized_quick_sort(v, start, pivot - 1, stats);
    randomized_quick_sort(v, pivot + 1, end, stats);
}

void randomized_quick_sort(vector<string>& v, Stats& stats)
{
    if (v.empty())
    {
        return;
    }
    randomized_quick_sort(v, 0, static_cast<int>(v.size()) - 1, stats);
}

//
// std::sort — library sort (typically introsort)
//
void std_sort(vector<string>& v, Stats& stats)
{
    sort(v.begin(), v.end(),
         [&](const string& a, const string& b) { return less_than(a, b, stats); });
}

struct SortResult
{
    string name;
    double seconds;
    long long comparisons;
    bool sorted_ok;
};

using SortFn = void (*)(vector<string>&, Stats&);

SortResult run_sort(const string& name, const vector<string>& data, SortFn sort_fn)
{
    cout << "Running " << name << "...\n";

    vector<string> copy = data;
    Stats stats;
    auto start = Clock::now();
    sort_fn(copy, stats);
    auto end = Clock::now();

    double seconds = chrono::duration<double>(end - start).count();
    bool sorted_ok = is_sorted(copy);
    if (!sorted_ok)
    {
        cerr << "  ERROR: " << name << " did not produce sorted output\n";
    }

    return {name, seconds, stats.comparisons, sorted_ok};
}

void print_table(const string &fname, size_t word_count, bool duplicates_removed,
                 bool randomized, const vector<SortResult> &results)
{
    cout << "\nFile: " << fname << "  (" << word_count << " words)\n";
    cout << "Duplicates removed: " << (duplicates_removed ? "yes" : "no") << "\n";
    cout << "Randomized: " << (randomized ? "yes" : "no") << "\n\n";

    size_t name_width = string("Algorithm").size();
    size_t time_width = string("Time (s)").size();
    size_t comp_width = string("Comparisons").size();

    for (const SortResult& r : results)
    {
        name_width = max(name_width, r.name.size());
        ostringstream time_ss;
        time_ss << fixed << setprecision(6) << r.seconds;
        time_width = max(time_width, time_ss.str().size());
        comp_width = max(comp_width, to_string(r.comparisons).size());
    }

    const string col_gap = "  ";

    cout << left << setw(static_cast<int>(name_width)) << "Algorithm" << col_gap << right
         << setw(static_cast<int>(time_width)) << "Time (s)" << col_gap << right
         << setw(static_cast<int>(comp_width)) << "Comparisons"
         << "\n";
    cout << string(name_width, '-') << col_gap << string(time_width, '-') << col_gap
         << string(comp_width, '-')
         << "\n";

    vector<SortResult> sorted = results;
    sort(sorted.begin(), sorted.end(),
         [](const SortResult& a, const SortResult& b) { return a.seconds < b.seconds; });

    for (const SortResult& r : sorted)
    {
        cout << left << setw(static_cast<int>(name_width)) << r.name << col_gap << right
             << setw(static_cast<int>(time_width)) << fixed << setprecision(6) << r.seconds << col_gap
             << right << setw(static_cast<int>(comp_width)) << r.comparisons;
        if (!r.sorted_ok)
        {
            cout << "  (NOT SORTED)";
        }
        cout << "\n";
    }
}

void print_usage(const char *prog)
{
    cerr << "Usage: " << prog << " [--noslow] [--unique] [--randomize] <text-file>\n";
}

int main(int argc, char* argv[])
{
    bool noslow              = false;
    bool duplicates_removed  = false;
    bool randomized          = false;
    string fname;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "--noslow")
        {
            noslow = true;
        }
        else if (arg == "--unique")
        {
            duplicates_removed = true;
        }
        else if (arg == "--randomize")
        {
            randomized = true;
        }
        else if (fname.empty())
        {
            fname = arg;
        }
        else
        {
            print_usage(argv[0]);
            return 1;
        }
    }

    if (fname.empty())
    {
        print_usage(argv[0]);
        return 1;
    }

    vector<string> words = read_words(fname);
    if (duplicates_removed)
    {
        words = remove_duplicates(words);
    }
    srand(static_cast<unsigned>(time(nullptr)));
    if (randomized)
    {
        randomize_words(words);
    }

    vector<SortResult> results;
    results.push_back(run_sort("quick sort (last pivot)", words, quick_sort));
    results.push_back(run_sort("quick sort (rnd pivot)", words, randomized_quick_sort));
    results.push_back(run_sort("merge sort", words, merge_sort));
    results.push_back(run_sort("heap sort", words, heap_sort));
    results.push_back(run_sort("std::sort", words, std_sort));
    if (!noslow)
    {
        results.push_back(run_sort("insertion sort", words, insertion_sort));
    }

    print_table(fname, words.size(), duplicates_removed, randomized, results);
    return 0;
}
