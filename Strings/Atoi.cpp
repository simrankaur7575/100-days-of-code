/*
QUES - There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.
*/

bool checkstring(string N)
{
if(48<=N[0]<=57 || N[0]=='+' ||N[0]=='-')
return true;
else
return false;
}
int Solution::atoi(const string A) {
int i=0,sum=0;
vector <int> v;
if(checkstring(A))
{
if(A[0]=='+' || A[0]=='-')
i++;
while(A[i]>=48 && A[i]<=57)
{
v.push_back(int(A[i]-'0'));
i++;
}
i=0;
for(int j=v.size()-1;j>=0;j--)
{
if(sum + v[j]*pow(10,i)>INT_MAX && A[0]!='-')
return INT_MAX;
else if(sum + v[j]*pow(10,i)>INT_MAX && A[0]=='-')
return INT_MIN;
else
{
sum=sum + v[j]*pow(10,i);
i++;
}
}
if(A[0]=='-')
return 0-sum;
else
return sum;
}
else
return 0;
}
