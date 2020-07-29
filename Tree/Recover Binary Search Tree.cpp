/*
QUES - Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.
*/
void inorder(TreeNode* node, TreeNode* & first, TreeNode* & second, TreeNode* &prev)
{
if(node==NULL)
return;

inorder(node->left, first, second, prev);
if(prev!=NULL){
    if(prev->val > node->val){
        if(first == NULL){
            first = prev;
        }
        second = node;
    }
}
prev = node;

inorder(node->right, first, second, prev);
}

vector<int> Solution::recoverTree(TreeNode* node) {
TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = NULL;
inorder(node, first, second, prev);
vector<int> res;
res.push_back(first->val);
res.push_back(second->val);
sort(res.begin(), res.end());
return res;
}