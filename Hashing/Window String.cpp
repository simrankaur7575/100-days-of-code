/*
QUES - Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.
*/
string Solution::minWindow(string A, string B) {
  vector<int> m(128, 0);
  for (char c : B) 
      m[c]++;

int remaining = B.length();
int left = 0, right = 0, minStart = 0, minLen = numeric_limits<int>::max();

while (right < A.length()){
    if (--m[A[right++]] >= 0) 
        remaining--;
    
    while (remaining == 0){
        if (right - left < minLen){
            minLen = right - left;
            minStart = left;
        }
        if (++m[A[left++]] > 0) 
            remaining++;
    }
}
    
return minLen < numeric_limits<int>::max() ? A.substr(minStart, minLen) : "";
}