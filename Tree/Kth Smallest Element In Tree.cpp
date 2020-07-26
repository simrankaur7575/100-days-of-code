
/*
QUES - Given a binary search tree, write a function to find the kth smallest element in the tree.
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
 
 void inorder(TreeNode* A, vector<int> &v)
 {
     if(A==NULL)
     {
         return;
     }
     inorder(A->left,v);
     v.push_back(A->val);
     inorder(A->right,v);
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> v;
    inorder(A,v);
    return v[B-1];
}
