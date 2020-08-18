/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
QUES - Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    bool flag=false;
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    if(A->val==B)
    {
        return v;
    }
    while(true)
    {
        TreeNode * x = q.front();
        q.pop();
        if(x==NULL)
        {
            if(flag==true)
            {
                return v;
            }
            v.clear();
            q.push(NULL);
        }
        else
        {
            if(x->left!=NULL && x->right!=NULL){
            if(x->left->val==B || x->right->val==B)
            {
                flag=true;
            }
            else
            {
                q.push(x->left);
                q.push(x->right);
                v.push_back(x->left->val);
                v.push_back(x->right->val);
            }
            }
            else if(x->left!=NULL)
            {
                if(x->left->val==B ){
                    flag=true;
                }
                else
            {
                q.push(x->left);
                v.push_back(x->left->val);
            }
            }
            else if(x->right!=NULL)
            {
                if(x->right->val==B ){
                    flag=true;
                }
                else
            {
                q.push(x->right);
                v.push_back(x->right->val);
            }
            }
        }
    }
}
