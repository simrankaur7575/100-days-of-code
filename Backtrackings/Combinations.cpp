/*
QUES - Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
*/
void subset(vector<int> &A,vector<vector <int> > &r,vector <int> &s,int ind,int B)
{
    if(s.size()==B){
   r.push_back(s);
}
for(int i=ind;i<A.size();i++)
{
s.push_back(A[i]);
subset(A,r,s,i+1,B);
s.pop_back();
}
}


vector<vector<int> > Solution::combine(int A, int B) {
vector<vector <int> > r;
vector <int> s;
vector<int> a;
for(int i=1;i<=A;i++)
{
    a.push_back(i);
}
subset(a,r,s,0,B);
//sort(r.begin(),r.end());
return r;
}
