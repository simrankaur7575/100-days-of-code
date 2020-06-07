/*
QUES - Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
*/
void subset(vector<int> &A,vector<vector <int> > &r,vector <int> &s,int ind,int B,int sum)
{
     if (sum > B) {
        return;
    }
    if(sum==B){
  r.push_back(s);
  return;
}
for(int i=ind;i<A.size();i++)
{
s.push_back(A[i]);
sum = sum+A[i];
subset(A,r,s,i,B,sum);
s.pop_back();
sum=sum-A[i];
}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
vector<vector <int> > r;
vector <int> s;
sort(A.begin(),A.end());
int sum=0;
vector<int> uniqueCandidates;
    for (int i = 0; i < A.size(); i++) {
        if (i == 0 || A[i] != A[i-1]) {
            uniqueCandidates.push_back(A[i]);
        }
    }
subset(uniqueCandidates,r,s,0,B,sum);
//sort(r.begin(),r.end());
return r;
}
