/*
QUES - Find the largest continuous sequence in a array which sums to zero.
*/
#define lli long long int
#define INIT 0
#define INIT_SUM 0
vector<int> Solution::lszero(vector<int> &A) 
{
    unordered_map<lli, lli> m;
    lli i, sum = INIT, start = INIT, elements = INIT;
    
    m[INIT_SUM] = 0;
    for(i=0; i<A.size(); i++)
    {
        sum = sum + A[i];
        
        if(m.find(sum) == m.end())
            m[sum] = i+1;
            
        else
        {
            if(elements < i+1 - m[sum])
            {
                elements = i+1 - m[sum];
                start = m[sum];
            }
        }
    }
    
    return vector<int>(A.begin()+start, A.begin()+start+elements);
}