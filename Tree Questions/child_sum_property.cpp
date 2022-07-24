class solution
{
public:
    void changetree(Node *root)
    {
        if (root == NULL)
            return;
        int child = 0;

        if (root->left)
        {
            child += root->left->data;
        }
        if (root->right)
        {
            child += root->right->data;
        }

        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }

        changetree(root->left);
        changetree(root->right);

        int tot = 0;
        if (root->left)
            tot += root->left->data;
        if (root->right)
            tot += root->right->data;
        if (root->left or root->right)
            root->data=tot;
    }
}