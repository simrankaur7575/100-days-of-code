
   /*
   QUES - Given a digit string, return all possible letter combinations that the number could represent.
   */         

        void generateHelper(string &current, int index, string &digits, vector<string> &ans, string charmap[10]) {
            if (index == digits.length()) {
                ans.push_back(current);
                return;
            }
            int digit = digits[index] - '0';
            for (int i = 0; i < charmap[digit].length(); i++) {
                current.push_back(charmap[digit][i]);
                generateHelper(current, index + 1, digits, ans,charmap);
                current.pop_back();
            }
            return;
        }

        vector<string> Solution::letterCombinations(string digits) {
            string charmap[10];
            charmap[0] = "0";
            charmap[1] = "1";
            charmap[2] = "abc";
            charmap[3] = "def";
            charmap[4] = "ghi";
            charmap[5] = "jkl";
            charmap[6] = "mno";
            charmap[7] = "pqrs";
            charmap[8] = "tuv";
            charmap[9] = "wxyz";
            vector<string> ans;
            string current = "";
            generateHelper(current, 0, digits, ans,charmap);
            return ans;
        }