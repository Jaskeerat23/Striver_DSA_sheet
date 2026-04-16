#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DPM(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(j < 0) return i + 1;
        if(i < 0) return j + 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = DPM(i - 1, j - 1, s1, s2, dp);
        else {
            return dp[i][j] = min({
                1 + DPM(i - 1, j - 1, s1, s2, dp),
                1 + DPM(i, j - 1, s1, s2, dp),
                1 + DPM(i - 1, j, s1, s2, dp)
            });
        }
    }

    int DPT(string& s1, string& s2, vector<vector<int>>& dp) {
        int l1 = s1.length(), l2 = s2.length();

        for(int i = 0; i <= l1; i++) dp[i][0] = i;
        for(int j = 0; j <= l2; j++) dp[0][j] = j;

        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min({
                        1 + dp[i - 1][j - 1],
                        1 + dp[i - 1][j],
                        1 + dp[i][j - 1]
                    });
                }
            }
        }
        return dp.back().back();
    }
    int DPSO(string& s1, string& s2) {
        int l1 = s1.length(), l2 = s2.length();
        vector<int> dp(l2 + 1, 0);
        for(int j = 0; j <= l2; j++) dp[j] = j;

        for(int i = 1; i <= l1; i++) {
            vector<int> temp(l2 + 1, 0);
            temp[0] = i;
            for(int j = 1; j <= l2; j++) {
                if(s1[i - 1] == s2[j - 1]) temp[j] = dp[j - 1];
                else {
                    temp[j] = min({
                        1 + dp[j - 1],
                        1 + dp[j],
                        1 + temp[j - 1]
                    });
                }
            }
            dp = temp;
        }
        return dp.back();
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if(l1 == 0) return l2;
        // vector<vector<int>> dp(l1, vector<int>(l2, -1)); // -> THIS INITIALIZATION IS FOR DP USING MEMOIZATION
        // vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0)); // -> THIS INITIALIZATION IS FOR DP USING TABULATION
        int ans = DPSO(word1, word2); //SPACE OPTIMIZATION CODE WILL INIT DP ITSELF
        return ans;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.minDistance(s1, s2);
}