/*
QUES - You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.*/
int Solution::nTriang(vector<int> &A) {
sort(A.begin(),A.end());
int n=A.size();
long long cnt=0;
for(int i=n-1;i>=2;i--)
{
    int l =0;int r =i-1;
    while(l<r)
    {
        if(A[l]+A[r]>A[i])
        {cnt=cnt+r-l;
         cnt=cnt%1000000007;
         r--;
        }
        else l++;
    }
}
return cnt;
    
}
