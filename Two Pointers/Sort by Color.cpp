/*
QUES - Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
void Solution::sortColors(vector<int> &A) {
   int n=A.size();
   int cnt=0;
   for(int i=0;i<n;i++){
       if(A[i]!=0)
       continue;
       else{
           swap(A[cnt],A[i]);
           cnt++;
       }
   }
   cnt=n-1;
   for(int i=n-1;i>=0;i--){
       if(A[i]!=2)
       continue;
       else{
           swap(A[cnt],A[i]);
           cnt--;
       }
   }
}
