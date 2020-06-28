/*
QUES - Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.
*/

int Solution::removeDuplicates(vector<int> &A) {
int i = 0, j = 0, flag = 0;
if (A[j]==A[i])
{
flag++;
}
for (i=1; i<A.size(); i++)
{
if (A[j]==A[i] && flag<2)
{
j++;
A[j] = A[i];
flag++;
}
if (A[j]!=A[i])
{
flag = 0;
j++;
A[j] = A[i];
flag++;
}
}
return j+1;
}