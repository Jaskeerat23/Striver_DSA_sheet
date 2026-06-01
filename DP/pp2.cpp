#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPalindrome(string& s, int i, int j) {
        for(int start = i, end = j; start < end; start++, end--) {
            if(s[start] != s[end]) return false;
        }
        // for(i; i <= j; i++) cout << s[i];
        // cout << " is palindrome\n";
        return true;
    }

    //My Approach
    int DPM(string& s, vector<vector<int>>& dp, int i, int j) {
        if(i == j) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k < j; k++) {
            int l = DPM(s, dp, i, k);
            int r = DPM(s, dp, k + 1, j);
            mini = min(mini, l + r + 1);
        }
        if(checkPalindrome(s, i, j)) return dp[i][j] = 0;
        return dp[i][j] = mini;
    }

    //Striver's approach - Slight Brute force because we are checking for 
    //whether the substring is palindrome or not but we can build a lookup table
    //for O(1) lookup
    int f(string& s, vector<int>& dp, vector<vector<int>>& isPalindrome, int i) {
        if(i == s.length()) return 0;
        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j = i; j < s.length(); j++) {
            if(isPalindrome[i][j]) minCost = min(minCost, 1 + f(s, dp, isPalindrome, j + 1));
        }

        return dp[i] = minCost;
    }

    //Tabulation code
    int f_tab(string& s, vector<int>& dp, vector<vector<int>>& isPalindrome) {
        int n = s.length();
        dp.push_back(0);
        for(int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalindrome[i][j]) minCost = min(minCost, 1 + dp[j + 1]);
            }
            dp[i] = minCost;
        }
        return dp[0];
    }

    int minCut(string s) {
        int n = s.length();
        // vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        vector<int> dp(n, -1);
        vector<vector<int>> isPalindrome(n, vector<int>(n, 1));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1];
        }
        return f(s, dp, isPalindrome, 0) - 1; // Because the code is making a partition at the end 
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minCut(s);
}
