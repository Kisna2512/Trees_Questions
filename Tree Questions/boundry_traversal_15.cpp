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

void boundaryTraversal(Node *root)
{
    if (root)
    {

        if (!(root->left) && !(root->right))
        {
            cout << root->data << endl;
            return;
        }

        vector<Node *> list;
        list.push_back(root);

        Node *L = root->left;
        while (L->left)
        {
            list.push_back(L);
            L = L->left;
        }

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (!(temp->left) && !(temp->right))
            {
                list.push_back(temp);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        vector<Node *> list_r;
        Node *R = root->right;
        while (R->right)
        {
            list_r.push_back(R);
            R = R->right;
        }

        reverse(list_r.begin(), list_r.end());

        list.insert(list.end(), list_r.begin(),
                    list_r.end());

        for (auto i : list)
        {
            cout << i->data << " ";
        }
        cout << endl;
        return;
    }
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

    cout<<"Boundry Traversal of the given binary Tree is:- "<<endl;
    boundaryTraversal(root);

    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}