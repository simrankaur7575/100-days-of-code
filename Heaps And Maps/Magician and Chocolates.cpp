/*
QUES - Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.
Find the maximum number of chocolates that kid can eat in A units of time.
*/
int Solution::nchoc(int A, vector<int> &B) {
    
    std::priority_queue<int> bag_sizes; 
    
    for (int initial_size : B) {
        bag_sizes.push(initial_size);
    }
    
    int result = 0;
    
    for (int i = 0; i < A; i++) {
        int largest = bag_sizes.top();
        if (largest == 0) { break; }
        result += largest;
        bag_sizes.pop();
        bag_sizes.push(largest / 2);
    }
    
    return result % static_cast<int>(std::pow(10, 9) + 7);
}