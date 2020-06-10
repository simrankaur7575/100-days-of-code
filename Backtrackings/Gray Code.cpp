/*
QUES - The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.
*/
int d;
void grey_code(vector<int> &a,int n ,int n1)
{

d = pow(2,n-1);
for(int x=a.size()-1;x >=0; x--)
{
a.push_back(d+a[x]);
}
if(n>=n1)
{
return;
}
return grey_code(a,n+1,n1);
}

vector<int> Solution::grayCode(int A) {

vector<int> a;

a.push_back(0);
a.push_back(1);
if(A==1)
{
return a;
}
grey_code(a,2,A);

return a;
}