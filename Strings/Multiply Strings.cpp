/*
QUES - Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.
*/

string multiply_digit(string b, char a){

int carry=0;

string ans="";

for(int i=b.length()-1;i>=0;--i){

int p=(a-'0')*(b[i]-'0');

p+=carry;

carry=p/10;

string temp(1, (p%10)+'0');

ans=temp+ans;

}

if(carry){

string temp(1,carry+'0');

ans=temp+ans;

}

return ans;

}


string add(string a, string b){

int carry=0;

string c="";

int i=a.length()-1,j=b.length()-1;

while(i>=0 && j>=0){

int s=(a[i]-'0')+(b[j]-'0');

s+=carry;

carry=s/10;

string temp(1,(s%10)+'0');

c=temp+c;

i--;

j--;

}

while(i>=0){ //a left

int s=(a[i]-'0');

s+=carry;

carry=s/10;

string temp(1,(s%10)+'0');

c=temp+c;

i--;

}

while(j>=0){ //b left

int s=(b[j]-'0');

s+=carry;

carry=s/10;

string temp(1,(s%10)+'0');

c=temp+c;

j--;

}

if(carry){

string temp(1,'1');

c=temp+c;

}

return c;

}


string Solution::multiply(string A, string B) {

string ans="";

int j=0;

for(int i=A.length()-1;i>=0;--i){

string c = multiply_digit(B,A[i]);

string d = add(ans.substr(0,ans.length()-j),c);

d+=ans.substr(ans.length()-j);

ans=d;

j++;

}

int i=0;

while(i!=ans.length()-1 && ans[i]=='0')i++;


return ans.substr(i);


}
