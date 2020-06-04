/*
QUES - Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*/
int Solution::evalRPN(vector<string> &A) {
    stack<string> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/")
        {
            if(A[i]=="+")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                int c = a+b;
                s.push(to_string(c));
            }
            else if(A[i]=="-")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                int c = b-a;
                s.push(to_string(c));
            }
            else if(A[i]=="*")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                int c = b*a;
                s.push(to_string(c));
            }
            else if(A[i]=="/")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                int c = b/a;
                s.push(to_string(c));
            }
        }
        else
        {
            s.push(A[i]);
        }
    }
    int ans = stoi(s.top());
    return ans;
}
