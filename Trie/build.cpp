#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26];
    bool flag;
    TrieNode() {
        memset(children, 0, sizeof(children));
        flag = false;
    }
    void setFlag() {
        flag = true;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        int n = word.length(), i = 0;
        TrieNode* ptr = root;
        while(i < n) {
            if(ptr->children[word[i] - 'a'] == nullptr) {
                ptr->children[word[i] - 'a'] = new TrieNode();
            }
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        ptr->setFlag();
    }
    
    bool search(const string& word) {
        int n = word.length(), i = 0;
        TrieNode* ptr = root;
        while(i < n && ptr->children[word[i] - 'a']) {
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        if(i < n) return false;
        return ptr->flag;
    }
    
    bool startsWith(const string& prefix) {
        int n = prefix.length(), i = 0;
        TrieNode* ptr = root;
        while(i < n && ptr->children[prefix[i] - 'a']) {
            ptr = ptr->children[prefix[i] - 'a'];
            i++;
        }
        if(i < n) return false;
        return true;
    }
};

int main() {
    Trie trie;
    int ch = 1;
    while(ch) {
        cout << "Enter 0 to exit\nEnter 1 to insert word\nEnter 2 to search for word\nEnter 3 to find prefix existance\nEnter:       ";
        cin >> ch;
        string word;
        cout << "Enter word/prefix/search query: ";
        cin >> word;
        if(ch == 1) trie.insert(word);
        else if(ch == 2) cout << boolalpha << trie.search(word) << endl;
        else if(ch == 3) cout << boolalpha << trie.startsWith(word) << endl;
    }
}