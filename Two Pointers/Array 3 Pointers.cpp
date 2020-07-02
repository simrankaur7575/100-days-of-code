/*
QUES - You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))
*/
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
int j=0;
int k=0;
int i=0;
int ans=INT_MAX;
int mina;
while(i<A.size()&&j<B.size()&&k<C.size())
{mina=max(max(abs(A[i]-B[j]),abs(A[i]-C[k])),abs(B[j]-C[k]));
if(mina<ans)
ans=mina;
if(A[i]>=B[j]&&B[j]<=C[k])
j++;
else if(A[i]<=B[j]&&A[i]<=C[k])
i++;
else if(C[k]<=A[i]&&C[k]<=B[j])
k++;
}
return ans;
}