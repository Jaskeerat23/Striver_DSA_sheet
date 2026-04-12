#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;
    int DPT(string& s1, string& s2, vector<vector<int>>& dp) {
        int m = s1.length(), n = s2.length();
        int maxi = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++ ) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
    int DPM(string& s1, string& s2, vector<vector<int>>& dp, int i, int j) {
        if(i == -1 || j == -1) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            int lcs = 1 + DPM(s1, s2, dp, i - 1, j - 1);
            ans = max(ans, lcs);
            return dp[i][j] = ans;
        }
        DPM(s1, s2, dp, i - 1, j);
        DPM(s1, s2, dp, i, j - 1);
        return dp[i][j] = 0;
    }
    int longCommSubstr(string& s1, string& s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        int _ = DPM(s1, s2, dp, s1.length() - 1, s2.length() - 1);
        return ans;
    }
};

int main() { 
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.longCommSubstr(s1, s2);
}