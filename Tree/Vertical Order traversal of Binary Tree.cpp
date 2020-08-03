/*
QUES - Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector< vector<int>> ans;

if( A == NULL )
    return ans;

queue< pair< TreeNode*, int>> q;
map < int, vector<int>> levelorder;

q.push( make_pair( A, 0 ) );

while( !q.empty() ){
    
    pair<TreeNode*, int> qvar;
    qvar = q.front();
    q.pop();
    
    levelorder[ qvar.second ].push_back( qvar.first->val );
    
    if( qvar.first->left != NULL ){
        
        q.push( make_pair( qvar.first->left, qvar.second-1 ) );
    }
    
    if( qvar.first->right != NULL ){
        
        q.push( make_pair( qvar.first->right, qvar.second+1 ) );
    }
    
}

for( auto it=levelorder.begin(); it != levelorder.end(); it++ ){
    
    ans.push_back( it->second );
}


return ans;
}
