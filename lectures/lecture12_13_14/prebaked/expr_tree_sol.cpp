// expr_tree_sol.cpp

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
};

Node* root = nullptr;

bool is_leaf_node(Node* p)
{
    return p != nullptr && p->left == nullptr && p->right == nullptr;
}

//
// TODO 2: Write a function called print_inorder(p) that prints the tree rooted
// at p in in-order.
//
// For simplicity, you initially don't need to add parentheses to the output,
// i.e. e.g. (1 + 2) * 5 can be printed as 1 + 2 * 5. 
//
// But you should add them later: if p is a leaf node, then it is an int
// (according to the rules of the expression tree) and you can print it as-is.
// If p is an internal node, then it is an operator and you should put
// parentheses around the everything, and spaces around the operator.
//
void print_inorder(Node* p)
{
    if (p != nullptr)
    {
        if (is_leaf_node(p)) // leaf node is an int
        {
            cout << p->data;
        }
        else // internal node is an operator
        {
            cout << "(";
            print_inorder(p->left);
            cout << " " << p->data << " ";
            print_inorder(p->right);
            cout << ")";
        }
    }
}

void print_inorder_tree()
{
    print_inorder(root);
}

//
// TODO 3: Write a function called eval(p) that evaluates the expression tree
// rooted at p. Assume that the leaf nodes are ints, and internal nodes are the
// symbols +, -, * (skipping / for simplicity).
//
// Use the helper function stoi(s) to convert a string s to an int, e.g.
// stoi("123") evaluates to 123.
//

int eval(Node* p)
{
    assert(p != nullptr);
    if (is_leaf_node(p)) // leaf node: return it as an int
    {
        return stoi(p->data);
    }
    else
    {
        int left  = eval(p->left);
        int right = eval(p->right);
        if (p->data == "+")
        {
            return left + right;
        }
        else if (p->data == "-")
        {
            return left - right;
        }
        else if (p->data == "*")
        {
            return left * right;
        }
        else
        {
            cout << "eval: unknown operator: " << p->data << endl;
            assert(false);
        }
    }
} // eval

int eval_tree()
{
    return eval(root);
}

int main()
{
    //
    // TODO 1: Make this expression tree:
    //
    //     *
    //    / \
    //   +   5
    //  / \
    // 1   2
    //
    // This is the expression: (1 + 2) * 5.
    //
    cout << "Making the expression tree ..." << endl;
    
    root = new Node{"*", nullptr, nullptr};
    // left subtree
    root->left        = new Node{"+", nullptr, nullptr};
    root->left->left  = new Node{"1", nullptr, nullptr};
    root->left->right = new Node{"2", nullptr, nullptr};
    // right subtree
    root->right = new Node{"5", nullptr, nullptr};

    cout << "Inorder: ";
    print_inorder_tree();
    cout << endl;

    cout << "Evaluation: ";
    cout << eval_tree();
    cout << endl;
} // main
