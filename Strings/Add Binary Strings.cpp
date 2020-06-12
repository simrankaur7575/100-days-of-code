/*
QUES - Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.
*/

string Solution::addBinary(string A, string B) {
    int n = A.length();
int m = B.length();
if(n > m){
while(A.length() != B.length()){
B = '0' + B;
}
}
if(m > n){
while(A.length() != B.length()){
A = '0' + A;
}
}

int carry = 0;
int a = A.length() - 1;
int b = B.length() - 1;
string ans;
while(a >= 0){
if(A[a]== '1' && B[b] == '1' && carry == 1){
ans = '1' + ans;
}
else if(A[a] == '1' && B[b] == '1' && carry == 0){
ans = '0' + ans;
carry = 1;
}
else if((A[a] == '1' || B[b] == '1') && carry == 1){
ans = '0' + ans;
}
else if((A[a] == '1' || B[b] == '1') && carry == 0){
ans = '1' + ans;
}
else if((A[a] == '0' && B[a] == '0') && carry == 1){
ans = '1' + ans;
carry = 0;
}
else if((A[a] == '0' && B[a] == '0') && carry == 0){
ans = '0' + ans;
}
a--;
b--;
}
if(carry == 1)
ans = '1' + ans;
return ans;
}
