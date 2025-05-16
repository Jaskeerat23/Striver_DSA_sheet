#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<bits/stdc++.h>
#include<utility>
#include<string>
using namespace std;
class Solution{
public:
    // APPROACH-1 : DFS
    struct pair_hash{
        size_t operator()(const pair<int, int>& ind) const {
            return hash<int>()(ind.first) ^ (hash<int>()(ind.second) << 1);
        }
    };
    void push_neighbours(vector<vector<char>>& board, stack<pair<int, int>>& Stack, unordered_set<pair<int, int>, pair_hash>& visited, int i, int j, int m, int n){
        int idx = 0;
        if(i != 0 && visited.find({i-1, j}) == visited.end()){
            Stack.push({i-1, j});
            cout << "Pushed char is : " << board[i-1][j] << endl;
            idx++;
        }
        if(i != m-1 && visited.find({i+1, j}) == visited.end()){
            Stack.push({i+1, j});
            cout << "Pushed char is : " << board[i+1][j] << endl;
            idx++;
        }
        if(j != 0 && visited.find({i, j-1}) == visited.end()){
            Stack.push({i, j-1});
            cout << "Pushed char is : " << board[i][j-1] << endl;
            idx++;
        }
        if(j != n-1 && visited.find({i, j+1}) == visited.end()){
            Stack.push({i, j+1});
            cout << "Pushed char is : " << board[i][j+1] << endl;
            idx++;
        }
        // cout << "Total " << idx << " pushed in stack" << endl;
    }
    bool wordsearch(vector<vector<char>>& board, string word){
        int m = board.size(), n = board[0].size(), idx = 0;
        stack<pair<int, int>> Stack;
        unordered_set<pair<int, int>, pair_hash> visited;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                Stack.push({i, j});
                while(!Stack.empty()){
                    // cout << "Exploring neighbour nodes" << endl;
                    pair<int, int> curr = Stack.top();
                    Stack.pop();
                    int idx_i = curr.first, idx_j = curr.second;
                    cout << "Stack top is " << board[idx_i][idx_j] << endl;
                    visited.insert({idx_i, idx_j});
                    if(board[idx_i][idx_j] == word[idx]){
                        cout << "Matched char is : " << board[idx_i][idx_j] << endl;
                        idx++;
                        push_neighbours(board, Stack, visited, idx_i, idx_j, m, n);
                    }
                    else{
                        visited.erase(visited.find({idx_i, idx_j}));
                    }
                    cout << "idx  : " << idx << endl;
                    if(idx == word.length())
                        return true;
                }
                idx = 0;
                visited.clear();
            }
        }
        return false;
    }
};
int main(){
    int m, n;
    char ch;
    string word;
    vector<vector<char>> board;
    cout << "Enter m : ";
    cin >> m;
    cout << "Enter n : ";
    cin >> n;
    for(int i = 0; i<m; i++){
        vector<char> temp;
        for(int j = 0; j<n; j++){
            cin >> ch;
            temp.push_back(ch);
        }
        board.push_back(temp);
    }
    cout << "Enter word : ";
    cin >> word;
    Solution obj;
    bool ans = obj.wordsearch(board, word);
    cout << "Ans is : " << ans << endl;
}