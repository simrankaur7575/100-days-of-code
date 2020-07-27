/*
QUES - Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.
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
 
int Solution::t2Sum(TreeNode* A, int k) {
    vector<int> v;
    inorder(A,v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j< v.size();j++)
        {
            if(v[i]+v[j]==k)
            {
                return 1;
            }
            if(v[i]+v[j]>k)
            {
                break;
            }
        }
    }
    return 0;
}
