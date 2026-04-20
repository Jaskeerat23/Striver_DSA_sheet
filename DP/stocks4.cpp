/*
THIS QUESTION IS ALMOST SAME AS PART-3 JUST WE INITIALIZE DP WITH DIMENSIONS
N, 2, K FOR MEMOIZATION 
N + 1, 2, K + 1 FOR TABULATION
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int DPM(vector<int>& prices, vector<vector<vector<int>>>& dp, int i, int buy, int t, int k) {
        if(i == prices.size() || t == k) return 0;
        if(dp[i][buy][t] != -1) return dp[i][buy][t];
        
        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + DPM(prices, dp, i + 1, 0, t, k), DPM(prices, dp, i + 1, 1, t, k));
        }
        else {
            profit = max(prices[i] + DPM(prices, dp, i + 1, 1, t + 1, k), DPM(prices, dp, i + 1, 0, t, k));
        }      
        return dp[i][buy][t] = profit;
    }

    int DPT(vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        int n = prices.size();
        for(int i = n - 1; i >= 0; i--) {
            for(int t = 0; t < k; t++) {
                dp[i][0][t] = max(prices[i] + dp[i + 1][1][t + 1], dp[i + 1][0][t]);
                dp[i][1][t] = max(-prices[i] + dp[i + 1][0][t], dp[i + 1][1][t]);
            }
        }
        return dp[0][1][0];
    }

    int DPSO(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            vector<vector<int>> temp(2, vector<int>(k + 1, 0));
            for(int t = 0; t < k; t++) {
                temp[0][t] = max(prices[i] + dp[1][t + 1], dp[0][t]);
                temp[1][t] = max(-prices[i] + dp[0][t], dp[1][t]);
            }
            dp = temp;
        }
        return dp[1][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        int ans = DPSO(prices, k);
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    Solution sol;
    cout << sol.maxProfit(k, arr);
}