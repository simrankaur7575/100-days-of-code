/*
QUES - Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* root,TreeNode* p,char c)
 {
     if(root->left!=NULL && root->right!=NULL)
     {
         helper(root->left,root,'l');
         helper(root->right,root,'r');
     }
     else if(root->left==NULL && root->right==NULL)
     {
         return;
     }
     else{
         if(root->left==NULL)
         {
             if(c=='r')
             {
             p->right=root->right;
             helper(p->right,p,'r');
             }
             else
             {
                 p->left=root->right;
                 helper(p->left,p,'l');
             }
         }
         else
         {
             if(c=='r')
             {
             p->right=root->left;
             helper(p->right,p,'r');
             }
             else
             {
                 p->left=root->left;
                 helper(p->left,p,'l');
             }
         }
     }
 }
 
TreeNode* Solution::solve(TreeNode* A) {
    TreeNode * root;
    if(A->left!= NULL && A->right!=NULL)
    {
        root=A;
    }
    else if(A->left==NULL && A->right==NULL)
    {
        return A;
    }
    else
    {
        if(A->left==NULL)
        {
            root=A->right;
        }
        else
        {
            root=A->left;
        }
    }
    if(root->left!=NULL){
    helper(root->left,root,'l');
    }
    if(root->right!=NULL){
    helper(root->right,root,'r');
    }
    return root;
}
