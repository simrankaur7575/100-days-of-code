/*
Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.
*/
int getVal(char c)
{
int cur = 0;
switch(c)
{
case 'I': cur = 1;break;
case 'V': cur = 5;break;
case 'X': cur = 10;break;
case 'L': cur = 50;break;
case 'C': cur = 100;break;
case 'D': cur = 500;break;
case 'M': cur = 1000;break;
}
return cur;
}

int Solution::romanToInt(string A)
{
int n = A.length(),result = 0;

for(int i=0;i<n;i++)
{
    result += getVal(A[i]);
    if(i > 0 && getVal(A[i]) > getVal(A[i-1]))
        result = result - 2*getVal(A[i-1]);
}
return result;    
}