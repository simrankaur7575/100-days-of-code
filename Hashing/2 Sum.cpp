/*
QUES - Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.
*/
#include <unordered_map>
vector<int> Solution::twoSum(const vector<int> &num, int target) {
    // map to store the mapping from number to its index. 
                        map<int, int> M;
            vector<int> ans;

            for (int i = 0; i < num.size(); i++) {
                int required = target - num[i];
                if (M.find(required) != M.end()) {
                    // We have our solution. index1 = M[required], index2 = i + 1 ( 1 based ). 
                    ans.push_back(M[required]);
                    ans.push_back(i + 1);
                    return ans;
                }
                if (M.find(num[i]) == M.end()) {
                    // We want to maintain the minimum index at M[num[i]]. i + 1 will 
                    // obviously be greater than whats already present.
                    M[num[i]] = i + 1;
                }
            }
            return ans;
}
