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

bool help(Node *left, Node *right)
{
    if (left == NULL or right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return help(left->left, right->right) and help(left->right, right->left);
}

bool isSymmetric(Node *root)
{
    return root == NULL || help(root->left, root->right);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<vector<int>> v{{0,0}};

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->right->left = new Node(4);
    if (isSymmetric(root))
    {
        cout << "The Given Binary Tree is Symmetrical" << endl;
    }
    else
    {
        cout << "Not symmetrical" << endl;
    }

    // this tree is like this
    //      1
    //     / \
    //    2    2
    //   / \  / \
    //  3  4  4  3

    return 0;
}