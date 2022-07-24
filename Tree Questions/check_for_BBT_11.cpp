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

// Time complexity :-o(n)
// space complexity:-o(n)

int maxdepth(Node *root)
{
    if (root == NULL)
        return 0;

    int lheight = maxdepth(root->left);
    if (lheight == -1)
        return -1;
    int rheight = maxdepth(root->right);
    if (rheight == -1)
        return -1;

    if (abs(lheight - rheight) > 1)
        return -1;

    return 1 + max(lheight, rheight);
}
// if height returns -1 means this is not a balanced binary tree
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<vector<int>> v{{0,0}};

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(7);

    cout << "The maximum depth of tree is:- " << maxdepth(root) << endl;

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}