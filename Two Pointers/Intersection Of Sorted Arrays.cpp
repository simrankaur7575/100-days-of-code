/*
QUES - Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.
*/
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int > v;
    int j=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B[j])
        {
            v.push_back(A[i]);
            j++;
            if(j==B.size())
            {
                break;
            }
        }
        else if(A[i]>B[j])
        {
            j++;
            i--;
            if(j==B.size())
            {
                break;
            }
        }
    }
    
    return v;
}
