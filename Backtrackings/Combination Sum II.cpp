/*
QUES - Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
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
subset(A,r,s,i+1,B,sum);
s.pop_back();
sum=sum-A[i];
}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   vector<vector <int> > r;
vector <int> s;
sort(A.begin(),A.end());
int sum=0;
subset(A,r,s,0,B,sum);
sort(r.begin(),r.end());
vector<vector<int>>::iterator ip; 
ip = std::unique(r.begin(), r.begin() + r.size()); 
r.resize(std::distance(r.begin(), ip)); 
return r;
    
}
