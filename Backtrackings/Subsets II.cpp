/*
QUES - Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
*/

void helper(vector<int> &A,vector<vector<int> > &r, vector<int> &s,int ind)
{
    r.push_back(s);
    for(int i=ind;i<A.size();i++)
    {
        s.push_back(A[i]);
        helper(A,r,s,i+1);
        s.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > r;
    vector<int> s;
    sort(A.begin(),A.end());
    helper(A,r,s,0);
    sort(r.begin(),r.end());
    vector<vector<int>> ::iterator it;
    it = std::unique(r.begin(),r.end());
    r.resize(std::distance(r.begin(),it));
    return r;
}
