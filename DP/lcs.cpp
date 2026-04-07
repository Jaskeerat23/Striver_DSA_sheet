#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    static int DPM(string& text1, string& text2, vector<vector<int>>& dp,int i1, int i2) {
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(text1[i1] == text2[i2]) {
            return dp[i1][i2] = 1 + DPM(text1, text2, dp, i1 - 1, i2 - 1);
        }
        return dp[i1][i2] = max(
            DPM(text1, text2, dp, i1 - 1, i2),
            DPM(text1, text2, dp, i1, i2 - 1)
        );
    }

    static int DPT(string& text1, string& text2, vector<vector<int>>& dp) {
        int l1 = text1.length(), l2 = text2.length();
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }

    static int DPSO(string& text1, string& text2) {
        vector<int> dp(text2.length() + 1, 0);
        int l1 = text1.length(), l2 = text2.length();
        for(int i = 1; i <= l1; i++) {
            vector<int> temp(text2.length() + 1, 0);
            for(int j = 1; j <= l2; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    temp[j] = 1 + dp[j - 1];
                } 
                else {
                    temp[j] = max(dp[j], temp[j - 1]);
                }
            }
            dp = temp;
        }
        return dp[l2];
    }

    static int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1)); -> MEMOIZATION
        // vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0)); -> TABULATION
        // int ans = DPM(text1, text2, dp, text1.length() - 1, text2.length() - 1);
        int ans = DPSO(text1, text2);
        return ans;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution :: longestCommonSubsequence(s1, s2);
}