#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
unordered_map<char, vector<string>> digitMap = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
};
class Solution {
public:
    void combine(string digits, string currStr, vector<string>& res, int idx){
        if(idx == digits.length()){
            res.push_back(currStr);
            return;
        }
        vector<string> digitPair = digitMap[digits[idx]];
        for(int i = 0; i < digitPair.size(); i++){
            currStr+=digitPair[i];
            combine(digits, currStr, res, idx + 1);
            currStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.size()) return {};
        if(digits.length() == 1) return digitMap[digits[0]];
        string currStr = "";
        combine(digits, currStr, res, 0);
        return res;
    }
};

int main(){
    string input;
    cout << "Enter string : ";
    cin >> input;
    Solution sol;
    sol.letterCombinations(input);
}