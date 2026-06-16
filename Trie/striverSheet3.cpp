#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        int n = word.length();
        TrieNode* ptr = root;
        for(auto& chr: word) {
            int idx = chr - 'a';
            if(!ptr->children[idx]) {
                ptr->children[idx] = new TrieNode();
            }
            ptr = ptr->children[idx];
        }
        ptr->isEnd = true;
    }
};

class Solution {
public:
    string ans;

    Solution() {
        ans = "";
    }

    void exploreTrieNode(TrieNode* root, string& cand_ans) {
        // cout << "exploring " << cand_ans << "\n";
        // if(root->isEnd == false) return;
        // cout << cand_ans << endl;

        for(int i = 0; i < 26; i++) {
            if(!root->children[i]) continue;

            if(root->children[i]->isEnd) {
                cand_ans += ('a' + i);
                if(ans.length() < cand_ans.length()) ans = cand_ans;

                exploreTrieNode(root->children[i], cand_ans);
                cand_ans.pop_back();
            }
        }
    }

    string longestValidWord(vector<string>& words) {
        // code here
        int n = words.size();
        Trie trie;

        for(int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        cout << "Successfully inserted words\n";

        string cand_ans = "";
        for(int i = 0; i < 26; i++) {
            if(!trie.root->children[i] || !trie.root->children[i]->isEnd) {
                // cout << "Continuing for " << i << " child\n";
                continue;
            }
            cand_ans += ('a' + i);
            if(ans.length() < cand_ans.length()) ans = cand_ans;

            exploreTrieNode(trie.root->children[i], cand_ans);
            cand_ans.pop_back();
        }
        return ans;
    }
};

int main() {
    int n; 
    vector<string> words;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    Solution sol;
    cout << sol.longestValidWord(words);
}