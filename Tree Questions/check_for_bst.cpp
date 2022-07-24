public class Solution
{
    //Function to check whether a Binary Tree is BST or not.
    boolean isBST(Node root)
    {
          return isValidBST(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
     public boolean isValidBST(Node root,long minvalue,long maxvalue)
    {
        if(root==null) return true;
        if(root.data >= maxvalue || root.data <= minvalue) return false;
        return isValidBST(root.left,minvalue,root.data) && isValidBST(root.right,root.data,maxvalue);
    }
}