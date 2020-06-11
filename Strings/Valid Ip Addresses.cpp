/*
QUES - Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/
void myfun(string &A, int &n,int i, int dots, string cur_ip, int cur, vector<string> &res,int cur_len)
{
if(i>n || dots>4 || cur>255) return;
if(i==n && dots==4 && cur_len==0)
{
cur_ip.pop_back();
res.push_back(cur_ip);
return;
}

 if(cur_len!=0)
{
    if(cur_len>1 && 1+floor(log10(cur))<cur_len) return;
    cur_ip=cur_ip+".";
    myfun(A,n,i,dots+1,cur_ip,0,res,0); 
    cur_ip.pop_back();
}

    cur=cur*10+(A[i]-'0');
    cur_ip=cur_ip+A[i];
    myfun(A,n,i+1,dots,cur_ip,cur,res,cur_len+1);
}

vector<string> Solution::restoreIpAddresses(string A) {
vector<string> res;
int n=A.length();
string cur_ip="";
int cur,dots;
dots=0;
int cur_len=0;
myfun(A,n,0,dots,cur_ip,cur,res,cur_len);
return res;

}