/*
QUES - We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.
*/
int Solution::cntBits(vector<int> &A) {
long long b[32]={},n=A.size(),ans=0,m=1e9+7;
for(int i=0;i<32;i++)
for(int j:A) if(j & (1<<i)) b[i]++;
for(int i=0;i<32;i++)
for(int j:A) if(j & (1<<i)) ans=(ans%m+(n-b[i])%m)%m;
else ans=(ans%m+b[i]%m)%m;
return ans;
}