/*
QUES - Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.
*/
int Solution::braces(string s) {
    int n=s.size();
    int c=0;
    for (int i=0;i<n;i++){
        if (s[i]=='(')
        c++;
        else if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        if (c>0) c--;
    }
    return c>0?1:0;
}
