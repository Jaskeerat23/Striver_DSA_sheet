#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DPT(string& s) {
        int n = s.length();
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));

        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= s.length(); j++) {
                // cout << s[i - 1] << " " << s[n - j] << endl;
                if(s[i - 1] == s[n - j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
    int DPSO(string& s) {
        int n = s.length();
        vector<int> dp(s.length(), 0);

        for(int i = 1; i <= s.length(); i++) {
            vector<int> temp(s.length() + 1, 0);
            for(int j = 1; j <= s.length(); j++) {
                // cout << s[i - 1] << " " << s[n - j] << endl;
                if(s[i - 1] == s[n - j]) temp[j] = 1 + dp[j - 1];
                else temp[j] = max(dp[j], temp[j - 1]);
            }
            dp = temp;
        }
        return dp.back();
    }

    int longestPalindromeSubseq(string s) {
        return DPSO(s);
    }
};

int main() {
    string s;
    Solution sol;
    cin >> s;
    cout << sol.longestPalindromeSubseq(s);
}