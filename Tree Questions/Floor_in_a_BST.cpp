#include <bits/stdc++.h>
using namespace std;

// floor means like  d val<=key
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

int findfloor(Node *node, int x)
{
    int floor = -1;

    while (node)
    {
        if (node->data == x)
        {
            floor = node->data;
            return floor;
        }
        if (x > node->data)
        {
            floor = node->data;
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    return floor;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout << "The floor of BST is:- " << findfloor(root, 3) << endl;

    return 0;
}