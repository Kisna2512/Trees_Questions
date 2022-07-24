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

int maxwidth(Node *root)
{

    if (!root)
        return 0;

    int ans = 0;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();

        int minm = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_idx = q.front().second - minm;
            Node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = curr_idx;
            if (i == size - 1)
                last = curr_idx;
            if (node->left)
            {
                q.push({node->left, curr_idx * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, curr_idx * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
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
    cout << "The Maximum Width of a Binary Tree is:- " << maxwidth(root) << endl;

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}