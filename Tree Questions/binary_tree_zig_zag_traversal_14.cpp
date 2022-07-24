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

vector<vector<int>> zigzag(Node *root)
{

    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;

    q.push(root);

    bool ltor = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++)
        {
            Node *n = q.front();
            q.pop();

            int idx = (ltor) ? i : (size - 1 - i);

            level[idx] = n->data;

            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        ltor = !ltor;
        ans.push_back(level);
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

    cout << "The zig-zag Traversal of Binary tree is:- " << endl;
    v = zigzag(root);
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