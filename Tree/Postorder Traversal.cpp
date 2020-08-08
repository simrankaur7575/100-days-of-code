/**
 QUES - Given a binary tree, return the postorder traversal of its nodes’ values.
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
stack<TreeNode *> q,q1;
q.push(A);
TreeNode *curr = A;
while(!q.empty())
{
curr = q.top();
q.pop();
ans.push_back(curr->val);

    if(curr->left!=NULL)
        q.push(curr->left);
    if(curr->right!=NULL)
        q.push(curr->right);
}
reverse(ans.begin(),ans.end());
return ans;
}
