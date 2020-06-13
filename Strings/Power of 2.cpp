/*
QUES - Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.
*/
int Solution::power(string A) {
    int n = A.size();
int k = n;
int num = 0;
int j = 0;

if(A=="0"|| A=="1")
{
    return 0;
}
while(A[n-1]!='1' || j!=n-1)
{
    j = 0;
    num = 0;
    if(((A[n-1]-'0')%2)==1)
    {
        return 0;
    }
    while(A[j]=='0')
    {
        j++;
    }
    

    
    for(int i=j;i<n;i++)
    {
        
        num = num*10+(A[i]-'0');
        
        A[i] = (num/2)+'0';
        num = num%2;
        
    }
    
    //cout<<A<<"---";
    
}

return 1;
}
