/*
QUES - Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
*/

void GetData(TreeNode *root,vector<int> &v)
{
if(root==NULL) return;
GetData(root->left,v);
v.push_back(root->val);
GetData(root->right,v);
}
vector<int> v;
BSTIterator::BSTIterator(TreeNode *root) {
v.clear();
GetData(root,v);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
if(v.size()==0) return false;
return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
int ans=v[0];
v.erase(v.begin());
return ans;
}
