#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DPM(vector<int>& prices, vector<vector<int>>& dp, int i, int buy, int fee) {
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int prof = 0;
        if(buy) {
            prof = max(-prices[i] + DPM(prices, dp, i + 1, 0, fee), DPM(prices, dp, i + 1, 1, fee));
        }
        else {
            prof = max(prices[i] - fee + DPM(prices, dp, i + 1, 1, fee), DPM(prices, dp, i + 1, 0, fee));
        }
        return dp[i][buy] = prof;
    }
    int DPT(vector<int>& prices, vector<vector<int>>& dp, int fee) {
        int n = prices.size();
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][1];
    }
    int DPSO(vector<int>& prices, int fee) {
        int buy = 0, sell = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            int sell_temp = max(prices[i] - fee + buy, sell);
            int buy_temp = max(-prices[i] + sell, buy);
            sell = sell_temp;
            buy = buy_temp;
        }
        return buy;
    }
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1)); // FOR MEMOIZATION
        // int ans = DPM(prices, dp, 0, 1, fee);
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0)); // FOR TABULATION
        int ans = DPT(prices, dp, fee);
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
    cout << sol.maxProfit(arr, k);
}
