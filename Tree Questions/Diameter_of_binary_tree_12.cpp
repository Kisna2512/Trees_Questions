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

    int rheight = maxdepth(root->right);

    return 1 + max(lheight, rheight);
}

int diameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int d1 = maxdepth(root->left) + maxdepth(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

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

    cout << "The maximum Diameter of tree is:- " << diameter(root) << endl;

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}