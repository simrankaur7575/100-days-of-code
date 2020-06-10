/*
QUES - Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.
*/
int Solution::isNumber(const string A) {
bool negative_flag=false;
int result=0;
int i=0;
if(i<A.length())
{
while(A[i]==' ')
{
i=i+1;
}
if(A[i]=='-')
{
i=i+1;
}
if(A[i]=='+')
{
i=i+1;
}
while((A[i]-'0')>=0 && (A[i]-'0')<=9)
{
result=1;
i=i+1;
}
while(A[i]==' ')
{
i++;
}
if(i==(A.length()))
{
return result;
}
else if(A[i]=='e' || A[i]=='.')
{
result=0;
i=i+1;
}
else
{
return 0;
}
if(!((A[i]-'0')>=0 && (A[i]-'0')<=9))
{
return 0;
}
while((A[i]-'0')>=0 && (A[i]-'0')<=9)
{
result=1;
i=i+1;
}
while(A[i]==' ')
{
i++;
}
if(i==(A.length()))
{
return 1;
}
else if(A[i]=='e')
{
result=0;
i++;
}
else
{
return 0;
}
if(A[i]=='-' or A[i]=='+')
{
i++;
}
if(!((A[i]-'0')>=0 && (A[i]-'0')<=9))
{
return 0;
}
while((A[i]-'0')>=0 && (A[i]-'0')<=9)
{
result=1;
i=i+1;
}
while(A[i]==' ')
{
i++;
}
if(i==(A.length()))
{
return 1;
}
else
{
return 0;
}
}
return result;
}