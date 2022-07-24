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

vector<int> preOrder(Node *root)
{
    //code here
    vector<int> v;
    if (root == NULL)
        return v;

    stack<Node *> st;

    st.push(root);
    while (!st.empty())
    {

        root = st.top();
        st.pop();

        v.push_back(root->data);

        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }

    return v;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<vector<int>> v{{0,0}};
    vector<int> v{0};

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(7);

    v = preOrder(root);
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