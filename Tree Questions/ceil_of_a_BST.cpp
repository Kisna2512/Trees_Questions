#include <bits/stdc++.h>
using namespace std;

// Ceil means like lower bound val>=key
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

int findCeil(Node *node, int x)
{
    int ceil = -1;

    while (node)
    {
        if (node->data == x)
        {
            ceil = node->data;
        }
        if (x > node->data)
        {
            node = node->right;
        }
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }

    return ceil;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout << "The ceil of BST is:- " << findCeil(root, 3) << endl;

    return 0;
}