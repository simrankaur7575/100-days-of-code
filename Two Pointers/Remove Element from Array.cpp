/*
QUES - Remove Element

Given an array and a value, remove all the instances of that value in the array. 
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.


*/

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]==B)
        {
            A.erase(A.begin()+i);
        }
    }
    return A.size();
}
