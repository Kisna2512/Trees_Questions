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

bool getPath(Node *root, vector<int> &arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    arr.push_back(root->data);

    // if it is the required node
    // return true
    if (root->data == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false
    arr.pop_back();
    return false;
}
vector<int> solve(Node *A, int B)
{
    vector<int> arr;
    if (A == NULL)
    {
        return arr;
    }
    getPath(A, arr, B);
    return arr;
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
    cout << "The path of a given tree to this node  is:- " << endl;
    vector<int> v = solve(root, 4);
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << "]";
    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}