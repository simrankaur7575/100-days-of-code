/*
QUES - Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
*/
vector<vector<int> > threeSum(vector<int> &num) {
            sort(num.begin(), num.end());
            
            int sum = 0;
            vector<vector<int> > ans;
            int sz = num.size();
            for (int i = 0; i < sz - 2; i++) {
                if (i > 0 && num[i] == num[i - 1]) {
                    continue;
                }
                int ptr1 = i + 1, ptr2 = num.size() - 1;
                while (ptr1 < ptr2) {
                    sum = num[i] + num[ptr1] + num[ptr2];
                    if (sum == 0) {
                        vector<int> tmp; 
                        tmp.push_back(num[i]);
                        tmp.push_back(num[ptr1]);
                        tmp.push_back(num[ptr2]);
                        ans.push_back(tmp);    
                    }
                    if (sum > 0) {
                        ptr2--;
                    } else if (sum < 0) {
                        ptr1++;
                    } else if (sum == 0) {
                        ptr1++;
                        while (ptr1 < ptr2 && num[ptr1] == num[ptr1 - 1]) {
                            ptr1++;
                        }
                    }
                }
            }
            return ans;
        }