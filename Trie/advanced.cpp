#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26];
    int wordsEnding;
    int prefixCnt;
    bool isEnd;

    TrieNode() {
        memset(children, 0, sizeof(children));
        wordsEnding = prefixCnt = isEnd = 0;
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
        int i = 0;
        TrieNode* ptr = root;
        while(i < n) {
            if(ptr->children[word[i] - 'a'] == nullptr) {
                ptr->children[word[i] - 'a'] = new TrieNode();
            }
            ptr = ptr->children[word[i] - 'a'];
            ptr->prefixCnt += 1;
            i++;
        }
        ptr->isEnd = true;
        ptr->wordsEnding += 1;
    }

    int countWordsEqualTo(const string& word) {
        int n = word.length();
        int i = 0;
        TrieNode* ptr = root;
        while(i < n && ptr->children[word[i] - 'a']) {
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        if(i < n) return 0;
        return ptr->wordsEnding;
    }

    int countWordsStartingWith(const string& word) {
        int n = word.length();
        int i = 0;
        TrieNode* ptr = root;
        while(i < n && ptr->children[word[i] - 'a']) {
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        if(i < n)return 0;
        return ptr->prefixCnt;
    }

    void erase(const string& word) {
        int n = word.length();
        int i = 0;
        TrieNode* ptr = root;
        /*NOT CHECKING FOR EXISTANCE OF WORD IN TRIE
        AS QUESTION GURANTEES THAT IF erase IS CALLED THE
        WORD IS PRESENT IN THE TRIE*/
        while(i < n) {
            ptr = ptr->children[word[i] - 'a'];
            i++;

            ptr->prefixCnt -= 1;
        }
        ptr->wordsEnding -= 1;
        if(ptr->wordsEnding == 0) ptr->isEnd = false;
    }
};

int main() {
    Trie trie;
    int ch = 1;
    while(ch) {
        cout << "Enter 0 to exit\nEnter 1 to insert word\nEnter 2 to search for word counts\nEnter 3 to find prefix counts\nEnter 4 to delete word\nEnter:";
        cin >> ch;
        string word;
        if(!ch) continue;
        cout << "\n\n\nEnter word/prefix/search query: ";
        cin >> word;
        if(ch == 1) trie.insert(word);
        else if(ch == 2) cout << trie.countWordsEqualTo(word) << " words exists" << endl << endl;
        else if(ch == 3) cout << trie.countWordsStartingWith(word) << " words exists as prefix" << endl << endl;
        else if(ch == 4){
            cout << "BEFORE :: " << trie.countWordsEqualTo(word) << " words equal to " << word << "existed" << endl;
            trie.erase(word);
            cout << "AFTER :: " << trie.countWordsEqualTo(word) << " words equal to " << word << "existed" << endl << endl;
        }
    }
}