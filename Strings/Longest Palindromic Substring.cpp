/*
QUES - Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).
*/

string Solution::longestPalindrome(string A) {
    
    if(A == "") return "";
    int start_index = 0, end_index = 0;
    int best_start_index = 0, best_end_index = 0;
    
    
    for(int i=0; i<A.size(); i++) {
        start_index = i;
        end_index = i+1;
        while(start_index >=0 && end_index<A.size()) {
            if(A[start_index] == A[end_index]) {
                if(end_index - start_index > best_end_index - best_start_index) {
                    best_start_index = start_index;
                    best_end_index = end_index;
                }
            }   else {
                break;
            }
            start_index--;
            end_index++;
        }
        
    }
    
   
    for(int i=0; i<A.size(); i++) {
        start_index = i;
        end_index = i;
        while(start_index >=0 && end_index<A.size()) {
            if(A[start_index] == A[end_index]) {
                if(end_index - start_index > best_end_index - best_start_index) {
                    best_start_index = start_index;
                    best_end_index = end_index;
                }
            }   else {
                break;
            }
            start_index--;
            end_index++;
        }
        
    }
    string str = A.substr(best_start_index, best_end_index - best_start_index + 1);
    return str;
}
