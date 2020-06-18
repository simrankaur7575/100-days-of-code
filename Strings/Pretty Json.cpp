/*
QUES - Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
*/

vector<string> Solution::prettyJSON(string A)
{
vector<string> ans;
int n=A.length();
int i=0;
int space=0;
while(i<n)
{
if(A[i]=='['||A[i]=='{')
{
int j=0;
string temp="";
while(j<space)
{

            temp=temp+"\t";
            j++;
        }
        if(A[i]=='[')
        {
            temp=temp+'[';
        }
        if(A[i]=='{')
        {
            temp=temp+'{';
        }
        ans.push_back(temp);
        space++;
        i++;
    }
    else if(A[i]==']'||A[i]=='}')
    {
        int j=0;
        space--;
        string temp="";
        while(j<space)
        {
            j++;
            temp=temp+"\t";
        }
         if(A[i]==']')
        {
            temp=temp+']';
        }
        if(A[i]=='}')
        {
            temp=temp+'}';
        }
        if(A[i+1]==','&&i<n)
        {
            temp=temp+A[i+1];
            i++;
        }
        ans.push_back(temp);
        i++;
    }
    else
    {
        string temp="";
         int j=0;
        while(j<space)
        {
            j++;
            temp=temp+"\t";
        }
        
          while(A[i]!=','&&A[i]!='['&&A[i]!='{'&&A[i]!=']'&&A[i]!='}')
           {
            temp=temp+A[i];
            i++;
            }
           if(A[i]==',')
           {
             temp=temp+A[i];
             ans.push_back(temp);
             i++;
           }
           else
           {
               ans.push_back(temp);
           }
    }
    
}
return ans;
}
