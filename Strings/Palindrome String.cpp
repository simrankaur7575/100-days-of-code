/*
QUES - Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {
    int x=A.size()-1;
    int i=0;
    while(i<x)
    {
        if(A[i]!=' ' && A[i]!=',' && A[i]!=':'&&  A[i]!='"')
        {
            if(A[x]==' ' || A[x]==',' || A[x]==':' ||  A[x]=='"')
            {
                x--;
            }
            while( A[x]==' ' || A[x]==',' || A[x]==':' ||  A[x]=='"')
            {
                x--;
            }
            if(A[i]!=A[x])
            {
                if(A[i]+32==A[x] || A[i]==A[x]+32)
                {
                    
                }
                else
                {
                
                return 0;
                }
            }
             x--;
        }
        i++;
    }
    return 1;
}
