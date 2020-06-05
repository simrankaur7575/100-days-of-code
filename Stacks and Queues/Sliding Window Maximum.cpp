/*
QUES - Given an array of integers A. There is a sliding window of size B which 
is moving from the very left of the array to the very right. 
You can only see the w numbers in the window. Each time the sliding window moves 
rightwards by one position. You have to find the maximum for each window. 
The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.
*/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    if(A.size()==0 || B==1)
    return A;
    queue<int> window;
    int n=A.size();
    int max=A[0];
    window.push(A[0]);
    for(int i=1;i<n && i<B;i++){
        if(A[i]>max)
        max=A[i];
        window.push(A[i]);
    }
    
    vector<int> result;
    result.push_back(max);
    for(int i=B;i<n;i++){
        if(A[i]>=max)
          {  max=A[i];
           window.pop();
          
           window.push(A[i]);
           
           result.push_back(max);
          }
          else{
              if(window.front()==max){
                
                
            window.pop();
            //if(!window.empty())
            max=window.front();
            for(int j=i-B+1;j<=i;j++)
            max=(max>A[j])?max:A[j];
            
           window.push(A[i]);
           
           result.push_back(max);
            
        }
        else{
             window.pop();
             window.push(A[i]);
           
           result.push_back(max);
        }
              
          }
    }
        
       
    return result;
}