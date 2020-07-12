/*
QUES - Given a string, 
find the length of the longest substring without repeating characters.
*/
int Solution::lengthOfLongestSubstring(string A) {
    unordered_map <char,int> m;
    int x=0;
    int max=0;
    int count=0;
    for(int i=0;A[i]!='\0';i++)
    {
        if(m.find(A[i])==m.end())
        {
            count++;
            m[A[i]]=i;
        }
        else
        {
            if(m[A[i]]==x)
            {
                x++;
                m[A[i]]=i;
            }
            else if(m[A[i]]<x)
            {
                count++;
                m[A[i]]=i;
            }
            else{
                x=m[A[i]]+1;
                if(count>max)
                {
                    max=count;
                }
                count=i-x+1;
                m[A[i]]=i;
            }
        }
    }
    if(count>max)
                {
                    max=count;
                }
     return max;
}
