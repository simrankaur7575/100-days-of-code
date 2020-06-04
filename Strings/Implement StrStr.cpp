int Solution::strStr(const string A, const string B) {
    int ans=-1;
    int flag=0;
    if(A.size()==0 || B.size()==0)
    {
        return -1;
    }
    int n=A.size()-B.size();
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B[0])
        {
            flag=0;
            int j=i+1;
            for(int x=1;x<B.size();x++)
            {
                if(A[j]!=B[x])
                {
                    flag=1;
                    break;
                }
                j++;
            }
            if(flag==0)
            {
                return i;
            }
        }
    }
    return -1;
}
