/*
QUES - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
void form(int n , int i, int j, string curr, vector<string> &ans) {
if(i == n and j == n) {
ans.push_back(curr);
return;
}

if(i<n) {
    form(n, i+1, j, curr+"(", ans);
}

if(j<i) {
    form(n, i, j+1, curr + ")", ans);
}
return;
}

vector<string> Solution::generateParenthesis(int A) {

vector<string> ans;

string curr = "";

form(A, 0, 0, curr, ans);

return ans;
}