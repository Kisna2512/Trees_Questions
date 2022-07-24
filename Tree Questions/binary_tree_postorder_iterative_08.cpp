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

vector<int> postOrder(Node *node)
{
    //code here
    vector<int>v;
        
        stack<Node*>st1,st2;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            
            st2.push(node);
            
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            
            
        }
        
        while(!st2.empty()){
            v.push_back(st2.top()->data);
            st2.pop();
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

    v = postOrder(root);
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