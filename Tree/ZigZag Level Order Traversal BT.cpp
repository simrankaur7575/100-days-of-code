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
 QUES - Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    vector<int> v;
    v.push_back(A->val);
    ans.push_back(v);
    v.clear();
    bool flag = true;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode * x = q.front();
        q.pop();
        if(x==NULL)
        {
            if(flag==true)
            {
                flag=false;
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            else
            {
                flag=true;
                ans.push_back(v);
            }
            v.clear();
            q.push(NULL);
        }
        else
        {
            if(x->left!=NULL && x->right!=NULL){
                q.push(x->left);
                q.push(x->right);
                v.push_back(x->left->val);
                v.push_back(x->right->val);
            }
            else if(x->left!=NULL)
            {
                q.push(x->left);
                v.push_back(x->left->val);
            }
            else if(x->right!=NULL)
            {
                q.push(x->right);
                v.push_back(x->right->val);
            }
        }
    }
    return ans;
}
