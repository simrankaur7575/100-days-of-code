/*
QUES - Find shortest unique prefix to represent each word in the list.


*/
struct Node {
    Node* children[26];
    int val;
    
    Node() {
        val = 0;
        for(int i=0; i<26; i++) children[i] = NULL;
    }
};


void insert(string s, Node* trie) {
    for(char a: s) {
        int k = a - 'a';
        if(trie->children[k] == NULL) trie->children[k] = new Node();
        trie->children[k]->val++;
        trie = trie->children[k];
    }
}

string findUniquePrefix(string s, Node* trie) {
    string ans = "";
    for(char a: s) {
        ans+=a;
        int k = a-'a';
        if(trie->children[k]->val == 1) return ans;
        trie = trie->children[k];
    }
    return s;
}

vector<string> Solution::prefix(vector<string> &A) {
    Node* trie = new Node();
    for(string s: A) insert(s, trie);
    vector<string> ans;
    
    for(string s: A) {
        ans.push_back( findUniquePrefix(s, trie) );
    }
    return ans;
}
