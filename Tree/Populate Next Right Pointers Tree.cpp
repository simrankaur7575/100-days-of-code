/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
 QUES - Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 */

void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode *> q;
    q.push(A);
    q.push(NULL);
    while(q.size()!=1)
    {
        TreeLinkNode *x1 = q.front();
        q.pop();
        if(x1!=NULL){
        TreeLinkNode *x2 = q.front();
         x1->next = x2;
         if(x1->left!=NULL){
        q.push(x1->left);
        }
        if(x1->right!=NULL){
        q.push(x1->right);
        }
        }
        else
        {
            q.push(NULL);
        }
    }
}
