/*
QUES - For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
*/

int Solution::colorful(int A) {
     string num = to_string(A);
    unordered_map<long long, bool>hash;
    for(int i=0;i<num.length();i++) {
        long long mul = 1;
        for(int j=i;j<num.length();j++){
            mul*=(num[j]-'0');
            if(hash.find(mul)!=hash.end())
                return 0;
            hash[mul]=true;
        }
    }
    return 1;
}
