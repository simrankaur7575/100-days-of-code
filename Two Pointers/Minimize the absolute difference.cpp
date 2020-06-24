/*
QUES - Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.


*/
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
int mx = INT_MAX;
bool q = true;
vector<int> ppp[3];
ppp[0] = A;
ppp[1] = B;
ppp[2] = C;
string ss = "abc";
while(q){
vector a = ppp[ss[0]-'a'],b = ppp[ss[1]-'a'],c = ppp[ss[2]-'a'];
for(int i=0;i<a.size();i++)
{
int i1 = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
if(i1==b.size()) continue;
int i2 = lower_bound(c.begin(),c.end(),b[i1]) - c.begin();
if(i2==c.size()) continue;
int no = max(a[i],max(b[i1],c[i2])) - min(a[i],min(b[i1],c[i2]));
mx = min(mx,no);    
}    
q = next_permutation(ss.begin(),ss.end());
}
return mx;
}