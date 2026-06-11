// binary_tree.cpp

#include <cassert>
#include <iostream>

using namespace std;

// TODO 1: Write a struct for a binary tree node that contains an int and a
// pointer to its left and right children. It doesn't need a parent pointer.
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//
// TODO 2: Make pointer to the root of the binary tree. It should be initialized
// to nullptr (meaning the tree is empty).
//

Node *root = nullptr;

//
// TODO 4: Write a function called is_leaf_node(p) that returns true if p is a
// leaf node, i.e. a node with no children.
//

bool is_leaf_node(Node *p)
{
    return p != nullptr && p->left == nullptr && p->right == nullptr;
}

//
// TODO 5: Write a function called height(p) that returns the height of the tree
// rooted at p.
//
// To calculate the height of a tree, all the leaves have height 0. Then every
// other node's height is 1 + the height of its tallest child. The height of an
// empty tree is 0.
//

int height(Node *p)
{
    if (p == nullptr)
        return 0;
    else if (is_leaf_node(p))
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

int tree_height()
{
    return height(root);
}

//
// TODO 6: Write a function called sum(p) that returns the sum of the values in
// the tree rooted at p (including p).
//

int sum(Node *p)
{
    if (p == nullptr)
        return 0;
    else
    {
        int left_sum = sum(p->left);
        int right_sum = sum(p->right);
        return left_sum + right_sum + p->data;
    }
}

int sum_tree()
{
    return sum(root);
}

//
// printing a binary tree in three different orders
//

//
// TODO 6: Write a function called print_preorder(p) that prints the tree rooted
// at p in pre-order.
//

void print_preorder(Node *p)
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

//
// TODO 7: Write a function called print_inorder(p) that prints the tree rooted
// at p in in-order.
//

void print_inorder(Node *p)
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

// TODO 8: Write a function called print_postorder(p) that prints the tree rooted
// at p in post-order.
//

void print_postorder(Node *p)
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
// TODO 9: Write a function called clear_tree(p) that deletes all the nodes in
// the tree rooted at p.
//
// Careful: delete the left and right subtrees first, then delete the current
// node.
//

void clear_tree(Node *p)
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
    // TODO 3: Make this binary tree by creating the nodes and connecting their
    // pointers:
    //
    //   1
    //  / \
    // 2   3
    //    / \
    //   4   5
    //

    root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};

    root->right->left = new Node{4, nullptr, nullptr};
    root->right->right = new Node{5, nullptr, nullptr};

    cout << "Tree height: ";
    cout << tree_height();
    assert(height(root->left) == 0);
    cout << endl;

    cout << "Tree sum: ";
    cout << sum_tree();
    assert(sum_tree() == 15);
    cout << endl;

    cout << "Preorder: ";
    print_preorder_tree();
    cout << endl;

    cout << "Inorder: ";
    print_inorder_tree();
    cout << endl;

    cout << "Postorder: ";
    print_postorder_tree();
    cout << endl;

    cout << "Clearing tree ... \n";
    clear_tree();
} // main
