// binary_tree_sol.cpp

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// root points to the root of the binary tree; if the tree is empty, root is
// nullptr
Node* root = nullptr;

void print_preorder(Node* p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        print_preorder(p->left);
        print_preorder(p->right);
    }
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

void print_postorder(Node* p)
{
    if (p != nullptr)
    {
        print_postorder(p->left);
        print_postorder(p->right);
        cout << p->data << " ";
    }
}

void clear_tree(Node* p)
{
    if (p != nullptr)
    {
        clear_tree(p->left);
        clear_tree(p->right);
        delete p;
    }
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

    cout << "Preorder: ";
    print_preorder(root);
    cout << endl;

    cout << "Inorder: ";
    print_inorder(root);
    cout << endl;

    cout << "Postorder: ";
    print_postorder(root);
    cout << endl;

    // delete entire tree
    clear_tree(root);
    root = nullptr;
} // main
