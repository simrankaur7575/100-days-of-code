/*
QUES - Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.
*/
string Solution::intToRoman(int A) {

vector<pair<int, string>> m;
m.push_back(make_pair(1,"I")); 
m.push_back(make_pair(4,"IV"));
m.push_back(make_pair(5,"V"));
m.push_back(make_pair(9,"IX"));
m.push_back(make_pair(10,"X"));
m.push_back(make_pair(40,"XL"));
m.push_back(make_pair(50,"L"));
m.push_back(make_pair(90,"XC"));
m.push_back(make_pair(100,"C"));
m.push_back(make_pair(400,"CD"));
m.push_back(make_pair(500,"D"));
m.push_back(make_pair(900,"CM"));
m.push_back(make_pair(1000,"M"));

int n = m.size();
string s="";
int remain = A;

for(int i=n-1; i>=0; i--){
    
    int divisor = m[i].first;
    int divident = remain/divisor;
    remain = remain%divisor;
    
    string temp="";
    for(int j=0; j<divident; j++){
        temp += m[i].second;
    }
    
    s += temp;
}

return s;
}