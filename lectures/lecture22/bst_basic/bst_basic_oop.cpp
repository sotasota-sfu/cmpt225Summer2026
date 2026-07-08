// bst_basic_sol.cpp

#include <cassert>
#include <iostream>

using namespace std;

//
// Object-oriented implementation of the basic BST functions from
// bst_basic_sol.cpp
//

class Basic_BST
{

    struct Node
    {
        int key;
        Node* left  = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;

    // returns true if the node p points to is a leaf node, and false otherwise
    bool is_leaf(Node* p) const { return p->left == nullptr && p->right == nullptr; }

    // returns number of nodes in the tree rooted at p; does not require a BST
    int size(Node* p) const
    {
        if (p == nullptr)
        {
            return 0;
        }
        return 1 + size(p->left) + size(p->right);
    }

    // returns height of the tree rooted at p; does not require a BST
    int height(Node* p) const
    {
        if (p == nullptr)
        {
            return 0;
        }
        return 1 + max(height(p->left), height(p->right));
    }

    // returns the minimum key in the tree rooted at p; does not require a BST
    int simple_min_key(Node* p) const
    {
        assert(p != nullptr);
        int root_key = p->key;
        if (is_leaf(p)) // no children
        {
            return root_key;
        }
        else if (p->left == nullptr) // only right child
        {
            return min(root_key, simple_min_key(p->right));
        }
        else if (p->right == nullptr) // only left child
        {
            return min(root_key, simple_min_key(p->left));
        }
        else // node with two children
        {
            return min(root_key, min(simple_min_key(p->left), simple_min_key(p->right)));
        }
    }

    // returns the minimum key in the tree rooted at p; does not require a BST
    int simple_max_key(Node* p) const
    {
        assert(p != nullptr);
        int root_key = p->key;
        if (is_leaf(p)) // no children
        {
            return root_key;
        }
        else if (p->left == nullptr) // only right child
        {
            return max(root_key, simple_max_key(p->right));
        }
        else if (p->right == nullptr) // only left child
        {
            return max(root_key, simple_max_key(p->left));
        }
        else // node with two children
        {
            return max(root_key, max(simple_max_key(p->left), simple_max_key(p->right)));
        }
    }

    // returns true if the tree rooted at p is a binary search tree, and false
    // otherwise
    bool is_bst(Node* p) const
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
            return p->key < simple_min_key(p->right) && is_bst(p->right);
        }
        else if (p->right == nullptr) // only left subtree
        {
            return simple_max_key(p->left) < p->key && is_bst(p->left);
        }
        else // both left and right subtrees
        {
            return (simple_max_key(p->left) < p->key) && (p->key < simple_min_key(p->right)) &&
                   is_bst(p->left) && is_bst(p->right);
        }
    }

    // uses recursion to find the minimum key in the tree rooted at p
    int min_key_rec(Node* p) const
    {
        assert(p != nullptr);
        if (p->left == nullptr)
        {
            return p->key;
        }
        return min_key_rec(p->left);
    }

    // uses a loop (and no recursion) to find the minimum key in the tree rooted at p
    int min_key_loop(Node* p) const
    {
        assert(p != nullptr);
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p->key;
    }

    int max_key_rec(Node* p) const
    {
        assert(p != nullptr);
        if (p->right == nullptr)
        {
            return p->key;
        }
        return max_key_rec(p->right);
    }

    int max_key_loop(Node* p) const
    {
        assert(p != nullptr);
        while (p->right != nullptr)
        {
            p = p->right;
        }
        return p->key;
    }

    // prints the nodes of the tree rooted at p in sorted order (assuming it is a
    // BST)
    void print_inorder(Node* p) const
    {
        if (p != nullptr)
        {
            print_inorder(p->left);
            cout << p->key << " ";
            print_inorder(p->right);
        }
    }

    // uses recursion top determine if key is in the tree rooted at p
    bool contains_rec(Node* p, int k) const
    {
        assert(is_bst(p));
        if (p == nullptr)
        {
            return false;
        }
        else if (p->key == k)
        {
            return true;
        }
        else if (k < p->key)
        {
            return contains_rec(p->left, k);
        }
        else
        {
            return contains_rec(p->right, k);
        }
    }

    // uses a loop (and no recursion) to determine if key is in the tree rooted at p
    bool contains_loop(Node* p, int k) const
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

  public:
    Basic_BST() : root(nullptr) {}

    ~Basic_BST() { clear(root); }

    bool is_bst() const { return is_bst(root); }
    int size() const { return size(root); }
    int height() const { return height(root); }
    int min_key_rec() const { return min_key_rec(root); }
    int min_key_loop() const { return min_key_loop(root); }
    int max_key_rec() const { return max_key_rec(root); }
    int max_key_loop() const { return max_key_loop(root); }
    void leaf_insert(int k) { leaf_insert(root, k); }

    void clear()
    {
        clear(root);
        root = nullptr;
    }

    void print_inorder() const { print_inorder(root); }
    bool contains_rec(int k) const { return contains_rec(root, k); }
    bool contains_loop(int k) const { return contains_loop(root, k); }
}; // class Basic_BST

int main()
{
    cout << "Testing Basic_BST..." << endl;
    Basic_BST bst;
    assert(bst.is_bst());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.contains_rec(5));
    assert(!bst.contains_loop(5));

    bst.leaf_insert(5);
    assert(bst.is_bst());
    assert(bst.size() == 1);
    assert(bst.height() == 1);
    assert(bst.contains_rec(5));
    assert(bst.contains_loop(5));
    assert(bst.min_key_rec() == 5);
    assert(bst.min_key_loop() == 5);
    assert(bst.max_key_rec() == 5);
    assert(bst.max_key_loop() == 5);

    bst.leaf_insert(3);
    assert(bst.is_bst());
    assert(bst.size() == 2);
    assert(bst.height() == 2);
    assert(bst.contains_rec(3));
    assert(bst.contains_loop(3));
    assert(bst.min_key_rec() == 3);
    assert(bst.min_key_loop() == 3);
    assert(bst.max_key_rec() == 5);
    assert(bst.max_key_loop() == 5);
    cout << "... all Basic_BST tests passed!" << endl;
}
