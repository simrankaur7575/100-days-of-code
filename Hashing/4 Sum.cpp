/*
QUES - Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
*/
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> quads;
    sort(A.begin(), A.end());
    int n = A.size();
    for (int i = 0; i < n; i++) { 
        if (i > 0 && A[i] == A[i-1]) continue; 
        for (int j = i + 1; j < n; j++) { 
            if ((j > i + 1) && A[j] == A[j-1]) continue; 
            int tptr = j + 1, ftptr = n - 1;
            long target = (long) A[i] + (long) A[j];
            target = B - target;
            while (tptr < ftptr) {
                long sum = (long) A[tptr] + (long) A[ftptr];
                if (sum < target) {
                    tptr++;
                } else if (sum > target) {
                    ftptr--;
                } else {
                    vector<int> quad{A[i], A[j], A[tptr], A[ftptr]};
                    quads.push_back(quad);
                    tptr++;
                    while (tptr < ftptr && A[tptr] == A[tptr-1]) tptr++;
                }
            }
        }
    }
    return quads;
}