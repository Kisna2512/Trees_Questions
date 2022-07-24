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

vector<vector<int>> verticalordertraversal(Node *root)
{

    map<int, map<int, multiset<int>>> node;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {

        auto p = q.front();
        q.pop();

        Node *n = p.first;
        int x = p.second.first, y = p.second.second;
        node[x][y].insert(n->data);
        if (n->left)
        {
            q.push({n->left, {x - 1, y + 1}});
        }
        if (n->right)
        {
            q.push({n->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto ip : node)
    {
        vector<int> col;
        for (auto it : ip.second)
        {
            col.insert(col.end(), it.second.begin(), it.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v{{0, 0}};

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(7);

    cout << "The vertical order Traversal of Binary tree is:- " << endl;
    v = verticalordertraversal(root);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}