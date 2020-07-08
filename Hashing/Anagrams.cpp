/*
QUES - Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.
*/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
unordered_map<string, vector<int>> map;
vector<vector<int>> ans;
for(int i=0; i<A.size(); i++){
vector<int> temp;
string t = A[i];
sort(t.begin(), t.end());
if(map.find(t) != map.end()){
map[t].push_back(i+1);
}else{
temp.push_back(i+1);
map.insert(make_pair(t,temp ));
}
}
for(auto x: map){
ans.push_back(x.second);
}
return ans;
}