/*
QUES - Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
*/
int Solution::removeDuplicates(vector<int> &A) {
int x=A.size()-1;
while(x>0)
{
if(A[x]==A[x-1]) A.erase(A.begin()+x); x--;
}
return A.size();
}