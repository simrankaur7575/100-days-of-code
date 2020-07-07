/*
QUES - Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
*/
int Solution::diffPossible(const vector<int> &A, int B) {
    if(A.size()==1 || A.size()==1)
    {
        return 0;
    }
    unordered_map <int,int> m;
    for(int i=0;i<A.size();i++)
    {
        m[A[i]]=0;
    }
    for(int i=0;i<A.size();i++)
    {
        m[A[i]]=m[A[i]]+1;
    }
    for(int i=0 ;i <A.size();i++)
    {
        int x = B + A[i];
        if(m.find(x)!=m.end())
        {
            if(x==A[i])
            {
                if(m[A[i]]>1)
                {
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}
