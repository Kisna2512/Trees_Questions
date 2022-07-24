#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
   inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(7);
    inorder(root);

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}