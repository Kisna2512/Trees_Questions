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

vector<int> inOrder(Node *root)
{
    //code here
   stack<Node*>st;
        
        Node* n=root;
        vector<int>v;
        
        while(true){
            
            if(n!=NULL){
                st.push(n);
                n=n->left;
            }
            else{
                
                if(st.empty()==true) break;
                
                n=st.top();
                st.pop();
                
                
                v.push_back(n->data);
                n=n->right;
            
            }
            
            
    
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

    v = inOrder(root);
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