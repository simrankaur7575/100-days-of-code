/*
QUES - Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.
*/
vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> ans;
    priority_queue<int> p;
    for(int i:A)
    {
        p.push(i);
    }
    for(int i=0;i<B;i++)
    {
        ans.push_back(p.top());
        p.pop();
    }
    return ans;
}
