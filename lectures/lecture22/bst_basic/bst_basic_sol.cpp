// bst_basic_sol.cpp



#include <cassert>
#include <iostream>

using namespace std;

//
// Demonstrates basic BST functions. Assumes all keys are distinct.
//

struct Node
{
    int key;
    Node* left  = nullptr;
    Node* right = nullptr;
};

// returns true if the node p points to is a leaf node, and false otherwise
bool is_leaf(Node* p)
{
    return p->left == nullptr && p->right == nullptr;
}

// returns number of nodes in the tree rooted at p; does not require a BST
int size(Node* p)
{
    if (p == nullptr)
    {
        return 0;
    }
    return 1 + size(p->left) + size(p->right);
}

// returns height of the tree rooted at p; does not require a BST
int height(Node* p)
{
    if (p == nullptr)
    {
        return 0;
    }
    return 1 + max(height(p->left), height(p->right));
}

// uses recursion to find the minimum key in the tree rooted at p
int min_key_rec(Node* p)
{
    assert(p != nullptr);
    if (p->left == nullptr)
    {
        return p->key;
    }
    return min_key_rec(p->left);
}

// uses a loop (and no recursion) to find the minimum key in the tree rooted at p
int min_key_loop(Node* p)
{
    assert(p != nullptr);
    while (p->left != nullptr)
    {
        p = p->left;
    }
    return p->key;
}

int max_key_rec(Node* p)
{
    assert(p != nullptr);
    if (p->right == nullptr)
    {
        return p->key;
    }
    return max_key_rec(p->right);
}

int max_key_loop(Node* p)
{
    assert(p != nullptr);
    while (p->right != nullptr)
    {
        p = p->right;
    }
    return p->key;
}

// returns true if the tree rooted at p is a binary search tree, and false
// otherwise
bool is_bst(Node* p)
{
    if (p == nullptr) // empty tree
    {
        return true;
    }
    else if (is_leaf(p)) // leaf node
    {
        return true;
    }
    else if (p->left == nullptr) // only right subtree
    {
        return p->key < min_key_rec(p->right) && is_bst(p->right);
    }
    else if (p->right == nullptr) // only left subtree
    {
        return max_key_rec(p->left) < p->key && is_bst(p->left);
    }
    else // both left and right subtrees
    {
        return (max_key_rec(p->left) < p->key) && (p->key < min_key_rec(p->right))
            && is_bst(p->left)
            && is_bst(p->right);
    }
}

// prints the nodes of the tree rooted at p in sorted order (assuming it is a
// BST)
void print_inorder(Node* p)
{
    if (p != nullptr)
    {
        print_inorder(p->left);
        cout << p->key << " ";
        print_inorder(p->right);
    }
}

// uses recursion top determine if key is in the tree rooted at p
bool contains_rec(Node* p, int k)
{
    assert(is_bst(p));
    if (p == nullptr)
    {
        return false;
    }
    return p->key == k || contains_rec(p->left, k) || contains_rec(p->right, k);
}

// uses a loop (and no recursion) to determine if key is in the tree rooted at p
bool contains_loop(Node* p, int k)
{
    assert(is_bst(p));
    while (p != nullptr)
    {
        if (p->key == k)
        {
            return true;
        }
        else if (p->key > k)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return false;
}

// deletes all nodes in the tree rooted at p
void clear(Node* p)
{
    if (p != nullptr)
    {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

// inserts k as a new leaf node in the tree rooted at p
void leaf_insert(Node*& p, int k)
{
    assert(is_bst(p));
    if (p == nullptr) // empty tree
    {
        p = new Node{k, nullptr, nullptr};
    }
    else if (is_leaf(p))
    {
        if (k < p->key)
        {
            p->left = new Node{k, nullptr, nullptr};
        }
        else
        {
            p->right = new Node{k, nullptr, nullptr};
        }
    }
    else if (k < p->key)
    {
        leaf_insert(p->left, k);
    }
    else if (k > p->key)
    {
        leaf_insert(p->right, k);
    }
    else
    {
        // k is already in the tree, so do nothing
    }
    assert(is_bst(p)); // sanity check: make sure the tree is still a BST
}

//
// Testing code
//
// assert(expr) does nothing if expr is true. But if expr is false, the program
// terminates and prints an error message (with a line number and file name).
//

void test0()
{
    cout << "test0: empty tree ..." << endl;
    Node* root = nullptr;
    assert(is_bst(root));
    assert(size(root) == 0);
    assert(height(root) == 0);
    assert(!contains_rec(root, 5));
    clear(root);
    cout << "ok: test0 passed\n" << endl;
}

void test1()
{
    cout << "test1: single node BST ..." << endl;
    Node* root = new Node{5, nullptr, nullptr};
    assert(is_bst(root));
    assert(size(root) == 1);
    assert(height(root) == 1);
    assert(contains_rec(root, 5));
    assert(!contains_rec(root, 6));
    assert(contains_loop(root, 5));
    assert(!contains_loop(root, 6));
    assert(min_key_rec(root) == 5);
    assert(min_key_loop(root) == 5);
    assert(max_key_rec(root) == 5);
    assert(max_key_loop(root) == 5);
    clear(root);
    cout << "ok: test1 passed\n" << endl;
}

void test2()
{
    cout << "test2: root and 1 left child ..." << endl;
    Node* root = new Node{5, nullptr, nullptr};
    root->left = new Node{3, nullptr, nullptr};
    assert(is_bst(root));
    print_inorder(root);
    cout << endl; // should print 3 5
    assert(size(root) == 2);
    assert(height(root) == 2);
    assert(contains_rec(root, 5));
    assert(!contains_rec(root, 6));
    assert(contains_rec(root, 3));
    assert(contains_loop(root, 5));
    assert(!contains_loop(root, 6));
    assert(contains_loop(root, 3));
    assert(min_key_rec(root) == 3);
    assert(min_key_loop(root) == 3);
    assert(max_key_rec(root) == 5);
    assert(max_key_loop(root) == 5);
    clear(root);
    cout << "ok: test2 passed\n" << endl;
}

void test3()
{
    cout << "test3: root and 1 right child ..." << endl;
    Node* root  = new Node{5, nullptr, nullptr};
    root->right = new Node{7, nullptr, nullptr};
    assert(is_bst(root));
    print_inorder(root);
    cout << endl; // should print 5 7
    assert(size(root) == 2);
    assert(height(root) == 2);
    assert(contains_rec(root, 5));
    assert(!contains_rec(root, 6));
    assert(contains_rec(root, 7));
    assert(contains_loop(root, 5));
    assert(!contains_loop(root, 6));
    assert(contains_loop(root, 7));
    assert(min_key_rec(root) == 5);
    assert(min_key_loop(root) == 5);
    assert(max_key_rec(root) == 7);
    assert(max_key_loop(root) == 7);
    clear(root);
    cout << "ok: test3 passed\n" << endl;
}

void test4()
{
    cout << "test4: root and 1 left child NOT a BST ..." << endl;
    Node* root = new Node{5, nullptr, nullptr};
    root->left = new Node{7, nullptr, nullptr};
    assert(!is_bst(root));
    assert(size(root) == 2);
    assert(height(root) == 2);
    clear(root);
    cout << "ok: test4 passed\n" << endl;
}

void test5()
{
    cout << "test5: root and 1 right child NOT a BST ..." << endl;
    Node* root  = new Node{5, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    assert(!is_bst(root));
    assert(size(root) == 2);
    assert(height(root) == 2);
    clear(root);
    cout << "ok: test5 passed\n" << endl;
}

void test6()
{
    cout << "test6: insert node into an empty tree ..." << endl;
    Node* root = nullptr;
    leaf_insert(root, 10);
    assert(is_bst(root));
    assert(size(root) == 1);
    assert(height(root) == 1);
    assert(contains_rec(root, 10));
    assert(contains_loop(root, 10));
    assert(min_key_rec(root) == 10);
    assert(min_key_loop(root) == 10);
    assert(max_key_rec(root) == 10);
    assert(max_key_loop(root) == 10);
    clear(root);
    cout << "ok: test6 passed\n" << endl;
}

void test7()
{
    cout << "test7: insert 3 then 5 into an empty tree ..." << endl;
    Node* root = nullptr;
    leaf_insert(root, 3);
    leaf_insert(root, 5);
    assert(is_bst(root));
    print_inorder(root);
    cout << endl; // should print 3 5
    assert(size(root) == 2);
    assert(height(root) == 2);
    assert(contains_rec(root, 3));
    assert(contains_rec(root, 5));
    assert(contains_loop(root, 3));
    assert(contains_loop(root, 5));
    assert(min_key_rec(root) == 3);
    assert(min_key_loop(root) == 3);
    assert(max_key_rec(root) == 5);
    assert(max_key_loop(root) == 5);
    clear(root);
    cout << "ok: test7 passed\n" << endl;
}

void test8()
{
    cout << "test8: insert 5 then 3 into an empty tree ..." << endl;
    Node* root = nullptr;
    leaf_insert(root, 5);
    leaf_insert(root, 3);
    assert(is_bst(root));
    print_inorder(root);
    cout << endl; // should print 3 5
    assert(size(root) == 2);
    assert(height(root) == 2);
    assert(contains_rec(root, 3));
    assert(contains_rec(root, 5));
    assert(contains_loop(root, 3));
    assert(contains_loop(root, 5));
    assert(min_key_rec(root) == 3);
    assert(min_key_loop(root) == 3);
    assert(max_key_rec(root) == 5);
    assert(max_key_loop(root) == 5);
    clear(root);
    cout << "ok: test8 passed\n" << endl;
}

//   5
//  / \
// 3   7
//    /
//   2
void test9()
{
    cout << "test9: 5 nodes, NOT a BST ..." << endl;
    cout << "   5" << endl;
    cout << "  / \\" << endl;
    cout << " 3   7" << endl;
    cout << "    /" << endl;
    cout << "   2" << endl;
    Node* root        = new Node{5, nullptr, nullptr};
    root->left        = new Node{3, nullptr, nullptr};
    root->right       = new Node{7, nullptr, nullptr};
    root->right->left = new Node{2, nullptr, nullptr};
    assert(!is_bst(root));
    assert(size(root) == 4);
    assert(height(root) == 3);
    clear(root);
    cout << "ok: test9 passed\n" << endl;
}

void test10()
{
    cout << "test10: insert 5 then 3 into an empty tree ..." << endl;
    Node* root = nullptr;
    for (int i = 0; i < 10; i++)
    {
        leaf_insert(root, i);
    }
    assert(is_bst(root));
    print_inorder(root);
    cout << endl; // should print 0 1 2 3 4 5 6 7 8 9
    assert(size(root) == 10);
    assert(height(root) == 10);
    for (int i = 0; i < 10; i++)
    {
        assert(contains_rec(root, i));
        assert(contains_loop(root, i));
    }
    clear(root);
    cout << "ok: test10 passed\n" << endl;
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}
