#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26]{};
    char ch;
    bool isEnd;
    
    TrieNode(char ch) {
        this->ch = ch;
        isEnd = false;
    }
};


class Solution {
public:

    TrieNode* root;
    Solution() {
        root = new TrieNode('a');
    }
    
    TrieNode* insert(char ch, TrieNode* root_curr) {
        if(root_curr->children[ch - 'a']) return root_curr->children[ch - 'a'];
        TrieNode* ptr = root_curr->children[ch - 'a'] = new TrieNode(ch);
        ptr->isEnd = 1;
        return ptr;
    }
    
    int countUniqueSubstrings(TrieNode* root) {
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(root->children[i]) {
                cnt += countUniqueSubstrings(root->children[i]);
            }
        }
        return root->isEnd + cnt;
    }

    int countSubs(string& s) {
        for(int i = 0; i < s.length(); i++) {
            TrieNode* prev = root;
            for(int j = i; j < s.length(); j++) {
                prev = insert(s[j], prev);
            }
        }
        return countUniqueSubstrings(root);
    }
};

int main() {
    string str;
    cin >> str;
    Solution sol;
    cout << sol.countSubs(str);
}