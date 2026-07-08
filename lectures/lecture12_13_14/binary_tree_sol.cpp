// binary_tree_sol.cpp

#include <cassert>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//
// root points to the root of the binary tree; if the tree is empty, root is
// nullptr
//
Node* root = nullptr;

bool is_leaf_node(Node* p)
{
    return p != nullptr && p->left == nullptr && p->right == nullptr;
}

bool is_internal_node(Node* p)
{
    return p != nullptr && !is_leaf_node(p);
}

//
// To calculate the height of a tree, all the leaves have height 0. Then every
// other node's height is 1 + the height of its tallest child.
//

int height(Node* p)
{
    if (p == nullptr) // empty tree
    {
        return 0;
    }
    else if (is_leaf_node(p))
    {
        return 0;
    }
    else
    {
        return 1 + max(height(p->left), height(p->right));
    }
}

int tree_height()
{
    return height(root);
}

// returns the sum of the values in the tree rooted at p (including p)
int sum(Node* p)
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        int left_sum  = sum(p->left);
        int right_sum = sum(p->right);
        return p->data + left_sum + right_sum;
    }
}

int sum_tree()
{
    return sum(root);
}

//
// printing a binary tree in three different orders
//

void print_preorder(Node* p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        print_preorder(p->left);
        print_preorder(p->right);
    }
}

void print_preorder_tree()
{
    print_preorder(root);
}

void print_inorder(Node* p)
{
    if (p != nullptr)
    {
        print_inorder(p->left);
        cout << p->data << " ";
        print_inorder(p->right);
    }
}

void print_inorder_tree()
{
    print_inorder(root);
}

void print_postorder(Node* p)
{
    if (p != nullptr)
    {
        print_postorder(p->left);
        print_postorder(p->right);
        cout << p->data << " ";
    }
}

void print_postorder_tree()
{
    print_postorder(root);
}

//
// deleting a binary tree
//
// Careful: delete the left and right subtrees first, then delete the current
// node.
//
void clear_tree(Node* p)
{
    if (p != nullptr)
    {
        clear_tree(p->left);
        clear_tree(p->right);
        delete p;
    }
}

void clear_tree()
{
    clear_tree(root);
}

int main()
{
    //
    // Make this binary tree:
    //   1
    //  / \
    // 2   3
    //    / \
    //   4   5
    //

    root = new Node{1, nullptr, nullptr};

    root->left  = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};

    root->right->left  = new Node{4, nullptr, nullptr};
    root->right->right = new Node{5, nullptr, nullptr};

    cout << "Tree height: ";
    // cout << tree_height();
    // assert(height(root->left) == 0);
    cout << endl;

    cout << "Tree sum: ";
    // cout << sum_tree();
    // assert(sum_tree() == 15);
    cout << endl;

    cout << "Preorder: ";
    // print_preorder_tree();
    cout << endl;

    cout << "Inorder: ";
    // print_inorder_tree();
    cout << endl;

    cout << "Postorder: ";
    // print_postorder_tree();
    cout << endl;

    cout << "Clearing tree ... \n";
    // clear_tree();
} // main
