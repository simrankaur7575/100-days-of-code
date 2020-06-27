/*
QUES - Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
*/
int Solution::diffPossible(vector<int> &A, int B) {
 
    for(int i=0;i<A.size()-1;i++)
    {
        int j= i+1;
        while(j<A.size())
        {
            if(abs(A[i]=A[j])==B)
            {
                return 1;
            }
            else if(abs(A[i]=A[j])<B)
            {
                j++;
            }
            else
            {
                j=A.size();
            }
        }
    }
    return 0;
}
