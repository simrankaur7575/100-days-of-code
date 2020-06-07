/*
QUES - Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
*/
void subset(vector<int> &A,vector<vector <int> > &r,vector <int> &s,int ind)
{
r.push_back(s);
for(int i=ind;i<A.size();i++)
{
s.push_back(A[i]);
subset(A,r,s,i+1);
s.pop_back();
}
}
vector<vector <int> > Solution::subsets(vector <int> &A) {
vector<vector <int> > r;
vector <int> s;
sort(A.begin(),A.end());
subset(A,r,s,0);
//sort(r.begin(),r.end());
return r;
}