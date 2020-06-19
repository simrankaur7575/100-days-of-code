/*
QUES - Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.
*/
int Solution::findMinXor(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    int smallestXor = numbers[0] ^ numbers[1];
    for (int i = 2; numbers.size(); i ++) {
        smallestXor = min(smallestXor, numbers[i - 1] ^ numbers[i]);
    }
    return smallestXor;
}
