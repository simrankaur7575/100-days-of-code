/*
QUES - Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
*/
void helper(vector<int> &A,vector<vector<int> > &ans, int ind )
{
    if(ind==A.size()-1)
    {
        ans.push_back(A);
        return;
    }
    for(int i=ind;i<A.size();i++)
    {
        swap(A[ind], A[i]);
        helper(A,ans,ind+1);
        swap(A[ind], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    sort(A.begin(),A.end());
    helper(A,ans,0);
    return ans;
}
