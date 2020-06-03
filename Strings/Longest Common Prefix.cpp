/*

QUES - Given the array of strings A, 
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    string s1=A[0];
int l=A.size();
if(l==1)
{
return(A[0]);
}
int x1=INT_MAX;
int x;
vector <int> N;
for(int i=1;i<l;i++)
{
x=0;
while(s1[x]==A[i][x])
{
x++;
}
if(x<=x1)
x1=x;
}

string sub=s1.substr(0,x1);
return sub;
}
