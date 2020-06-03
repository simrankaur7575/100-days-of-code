/*
QUES - You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

*/
int Solution::solve(string A) {
    int ans =0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U')
        {
            ans =ans + (A.size()-i);
        }
    }
    return ans%10003;
}
