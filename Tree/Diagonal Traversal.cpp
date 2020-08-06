/*
QUES - Consider lines of slope -1 passing between nodes.

Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.
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
vector<int> Solution::solve(TreeNode* A) {
    vector<int> v;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty())
    {
        TreeNode * x = q.front();
        q.pop();
        v.push_back(x->val);
        if(x->left!=NULL)
        {
            q.push(x->left);
        }
        x=x->right;
        while(x!=NULL)
        {
            v.push_back(x->val);
            if(x->left!=NULL)
            {
                q.push(x->left);
            }
            x=x->right;
        }
    }
    return v;
}

