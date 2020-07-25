/*
QUES - You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.
*/
int Solution::solve(vector<int> &A) {
    stack<int> s; 

    int root = INT_MIN; 
  
    for (int i=0; i<A.size(); i++) 
    { 
        // If we find a node who is on right side 
        // and smaller than root, return false 
        if (A[i] < root) 
            return false; 
  
        // If pre[i] is in right subtree of stack top, 
        // Keep removing items smaller than pre[i] 
        // and make the last removed item as new 
        // root. 
        while (!s.empty() && s.top()<A[i]) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
  
        // At this point either stack is empty or 
        // pre[i] is smaller than root, push pre[i] 
        s.push(A[i]); 
    } 
    return true; 
}
