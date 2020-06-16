/*
QUES - Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.
*/
vector<string> Solution::fullJustify(vector<string> &A, int B) {
vector<string> vs;
string s;
string first;
int size;
int space=0;
for(int i = 0;i<A.size();i++){
int j = i;
first = A[i];
size = A[i].size();
space=0;
while(A[i+1].size()+size+space<B and i<A.size()-1){
space++;
i++;
size+=A[i].size();
}
if(i == A.size()-1){
for(int x = j;x<i;x++){
s.append(A[x]);
s.push_back(' ');
}
s.append(A[i]);
while(s.size()<B){
s.push_back(' ');
}
vs.push_back(s);
}
else{
int sum=0;
for(int k = j;k<=i;k++){
sum+=A[k].size();
}
int avg;
int firstspace;
space = B-sum;
if(j==i){firstspace = space;}
else{
avg = space/(i-j);
if((i-j)*avg != space){
firstspace = space-(i-j)*avg;
}
else firstspace = 0;
}
// s.append(first);
// printf(“sum = %d, space = %d,i = %d j = %d avg = %d,firstspace = %d\n”,sum,space,i,j,avg,firstspace );
// for(int k = 0;k < firstspace;k++){
// s.push_back(’ ');
// }

  for(int x = j;x<=i;x++){
    s.append(A[x]);
    if(x!=i){
      if((x-j)<firstspace)s.push_back(' ');
    for(int k = 0;k < avg;k++){
      s.push_back(' ');
    }}
  }
  while(s.size()<B)s.push_back(' ');
  vs.push_back(s);
  s.clear();
}
}

return vs;
}