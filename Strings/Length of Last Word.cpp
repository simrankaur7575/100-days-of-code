/*
QUES - Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.
*/
int Solution::lengthOfLastWord(const string A) {
    int count=0;
    int flag=0;
    for(int i =A.size()-1; i>=0 ;i--)
    {
        if(A[i]==' ' && flag==0)
        {
        }
        else if(A[i]!=' ')
        {
            count++;
            flag=1;
        }
        else
        {
            break;
        }
    }
    return count;
}
