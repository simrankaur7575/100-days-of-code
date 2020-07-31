/*
QUES - Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.
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
 
 bool helper(TreeNode* A, int B, vector<int> &v)
 {
     if(A->val==B)
     {
         v.push_back(A->val);
         return true;
     }
     if(A->left!=NULL)
     {
         if(helper(A->left,B,v))
         {
             v.push_back(A->val);
             return true;
         }
     }
     if(A->right!=NULL)
     {
         if(helper(A->right,B,v))
         {
             v.push_back(A->val);
             return true; 
         }
     }
     return false;
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    if(A->val==B)
    {
        v.push_back(A->val);
        return v;
    }
    helper(A,B,v);
    reverse(v.begin(),v.end());
    return v;
}
