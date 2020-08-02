/*
QUES - Given a binary tree, determine if it is height-balanced.
*/

int Height(TreeNode *A){
if(A==NULL){
return 0;
}

 int lh = Height(A->left);
 int rh = Height(A->right);
 return 1 + max(lh , rh);
}

int Solution::isBalanced(TreeNode* A) {

if(A==NULL){
    return 1;
}

int lh = Height(A->left);
int rh = Height(A->right);

if(abs(lh-rh) > 1){
    return 0;
}

return isBalanced(A->left) & isBalanced(A->right);
}
