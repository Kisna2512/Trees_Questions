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

void Leftview(Node *root, int level, vector<int> &ans)
{
    //code here

    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    Leftview(root->left, level + 1, ans);
    Leftview(root->right, level + 1, ans);
  
}
vector<int> Answer(Node *root)
{
    vector<int> ans;
    Leftview(root, 0, ans);
    return ans;
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
    cout << "The Left view of a given tree is:- " << endl;
    vector<int> v = Answer(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}