/*
THE IDEA IS COMPLETELY SAME AS PART 2 JUST WE DO I + 2 AFTER SELLING STOCK
I WILL ONLY IMPLEMENT TABULATION AND SPACE OPTIMIZATION
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int DPT(vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
        // int ans = DPT(prices, dp);
        // return ans;

        /*----SPACE OPTIMIZATION----*/
        int buy = 0, sell = 0, cooldown = 0;
        int buy_temp = 0, sell_temp = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            sell_temp = max(prices[i] + cooldown, sell);
            buy_temp = max(-prices[i] + sell, buy);
            cooldown = buy;
            buy = buy_temp;
            sell = sell_temp;
        }
        return buy;
    }
};

int main() {
    int n;  
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.maxProfit(arr);
}