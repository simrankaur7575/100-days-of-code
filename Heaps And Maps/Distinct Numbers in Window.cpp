/*
QUES - You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.
*/
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    map<int,int> m;
    for(int i=0;i<B;i++)
    {
        if(m.find(A[i])!=m.end()){
            m[A[i]]=m[A[i]]+1;
        }
        else
        {
            m[A[i]]=1;
        }
    }
    int y=0;
    int x = A[y];
    ans.push_back(m.size());
    for(int i=B;i<A.size();i++)
    {
        m[x]=m[x]-1;
        if (m[x]==0)
        {
            m.erase(x);
        }
        if(m.find(A[i])!=m.end()){
            m[A[i]]=m[A[i]]+1;
        }
        else
        {
            m[A[i]]=1;
        }
        ans.push_back(m.size());
        y++;
        x=A[y];
    }
    return ans;
} 
