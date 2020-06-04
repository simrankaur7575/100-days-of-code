/*
QUES - Given a string A.

Return the string A after reversing the string word by word.
*/
string Solution::solve(string A) {
    int j=A.size()-1;
    string s="";

    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i]==' ')
        {
            for(int k=i+1;k<=j;k++)
            {
                s+=A[k];

            }
            s+=' ';
           
            j=i-1;
            i--;
        }
    }
      for   (int k=0;k<=j;k++)
            {
                s+=A[k];
               
            }
    return s;
}
