#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DPM(vector<int>& prices, vector<vector<vector<int>>>& dp, int i, int buy, int t) {
        if(i == prices.size() || t == 2) return 0;
        if(dp[i][buy][t] != -1) return dp[i][buy][t];
        
        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + DPM(prices, dp, i + 1, 0, t), DPM(prices, dp, i + 1, 1, t));
        }
        else {
            profit = max(prices[i] + DPM(prices, dp, i + 1, 1, t + 1), DPM(prices, dp, i + 1, 0, t));
        }      
        return dp[i][buy][t] = profit;
    }
    int DPT(vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();

        for(int i = n - 1; i >= 0; i--) {
            for(int t = 0; t < 2; t++) {
                dp[i][0][t] = max(prices[i] + dp[i + 1][1][t + 1], dp[i + 1][0][t]);
                dp[i][1][t] = max(-prices[i] + dp[i + 1][0][t], dp[i + 1][1][t]);
            }
        }
        return dp[0][1][0];
    }
    int DPSO(vector<int>& prices) {
        int b_1 = 0, b_2 = 0, s_1 = 0, s_2 = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {
            b_1 = max(-prices[i] + s_1, b_1);
            s_1 = max(prices[i] + b_2, s_1);
            b_2 = max(-prices[i] + s_2, b_2);
            s_2 = max(prices[i], s_2);
        }
        return b_1;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1))); // FOR MEMOIZATION
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0))); // FOR TABULATION
        // int ans = DPM(prices, dp, 0, 1, 0);
        // int ans = DPT(prices, dp);
        int ans = DPSO(prices);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    Solution sol;
    cout << sol.maxProfit(prices);
}