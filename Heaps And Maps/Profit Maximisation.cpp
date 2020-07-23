/*
QUES - Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.
*/
int Solution::solve(vector<int> &A, int B) 
{
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
    mp[A[i]]++;
    int n=0;
    long long p=0;
    while(n<B)
    {
        n++;
        int x=(mp.rbegin())->first;
        if(mp[x]==1)
        mp.erase(x);
        else
        mp[x]--;
        mp[x-1]++;
        p+=x;
    }
    return p;
}