/*
Problem Description

Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

    Half nodes are nodes which have only one child.
    Leaves should not be touched as they have both children as NULL.



Problem Constraints

1 <= N <= 105


Input Format

First and only argument is an pointer to the root of binary tree A.


Output Format

Return a pointer to the root of the new binary tree.
*/

TreeNode* Solution::solve(TreeNode* root) 
{
    if(!root)
        return NULL;
    root->left  = solve(root->left);
    root->right = solve(root->right);
    
    if(root->left ==NULL && root->right ==NULL)
        return root;
    if(root->left ==NULL)
        return root->right;
    if(root->right ==NULL)
        return root->left;
        
    return root;
}
