#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool DPM(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        else if(i < 0 && j >= 0) {
            for(int idx = j; idx >= 0; idx--) if(p[idx] != '*') return false;
            return true;
        }
        else if(i >= 0 && j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = DPM(i - 1, j - 1, s, p, dp);
        else if(p[j] == '*') {
            return dp[i][j] = DPM(i - 1, j - 1, s, p, dp) ||
                    DPM(i - 1, j, s, p, dp) ||
                    DPM(i, j - 1, s, p, dp);
        }
        else return dp[i][j] = false;
    }

    int DPT(string& s, string& p, vector<vector<int>>& dp) {
        int l1 = s.length(), l2 = p.length();
        dp[0][0] = 1;
        for(int i = 1; i <= l1; i++) dp[i][0] = 0;
        for(int j = 1; j <= l2 && p[j - 1] == '*'; j++) dp[0][j] = 1;

        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp.back().back();
    }

    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();
        // vector<vector<int>> dp(l1, vector<int>(l2, -1)); // -> MEMOIZATION
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        // int ans = DPM(l1 - 1, l2 - 1, s, p, dp);
        int ans = DPT(s, p, dp);
        return ans;
    } 
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << boolalpha << sol.isMatch(s1, s2);
}