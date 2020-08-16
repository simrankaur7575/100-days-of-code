/*
QUES - Given a binary tree, return the inorder traversal of its nodes’ values.

*/
vector<int> Solution::inorderTraversal(TreeNode* A) {

stack<TreeNode *> s;
vector<int> ans;
TreeNode* root = A;
while(true){
    
    while(root){
        s.push(root);
        root = root->left;
    }
    
    if(s.empty()){
        break;
    }
    
    root = s.top();
    s.pop();
    ans.push_back(root->val);
    root = root->right;
    
}
return ans;
}
