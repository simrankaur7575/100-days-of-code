/*
QUES - You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only. 
Each string goes through a number of operations, where:

1.	At time 1, you circularly rotate each string by 1 letter.
2.	At time 2, you circularly rotate the new rotated strings by 2 letters.
3.	At time 3, you circularly rotate the new rotated strings by 3 letters.
4.	At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"

1.	At time 1, string is "baaa", as 1 letter is circularly rotated to the back
2.	At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
3.	At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
4.	At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
5.	At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back
After some units of time, a string becomes equal to it’s original self. 
Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be it’s original self at 2t time. 
You have to find the minimum time, where maximum number of strings are equal to their original self. 
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.
*/
int Solution::solve(vector<string> &A) {
    long long n=A.size();
vector<int> v(n);
for(long long i=0;i<n;i++){
long long x=A[i].size();
if(x<=1)
v[i]=1;
else{
long long k=1,c=0;
while(1){
c=(k*(k+1))/2;
if(c%x==0){
v[i]=k;
break;
}
k++;
}
}
}
long long ans=1;
for(long long i=0;i<n;i++){
for(long long j=i+1;j<n&&v[i]!=1;j++){
v[j]=v[j]/__gcd(v[i],v[j]);
}
ans = (long long)(ans%1000000007*(v[i])%1000000007)%1000000007;
}
return ans%1000000007;
}
