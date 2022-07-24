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

vector<int> bottomview(Node *root)
{
    //code here
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mp;

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node *n = it.first;
        int line = it.second;
        
            mp[line] = n->data;

        if (n->left)
            q.push({n->left, line - 1});
        if (n->right)
            q.push({n->right, line + 1});
    }

    for (auto ip : mp)
    {
        ans.push_back(ip.second);
    }

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
    cout << "The bottom view of a guven tree is:- " << endl;
    vector<int> v = bottomview(root);
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