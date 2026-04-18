//Best time to buy and sell stock - 2
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    /*-------------GREEDY-----------------*/
    // int maxProfit(vector<int>& prices) {
    //     int mini = prices[0], profit = 0, currProf = 0;
    //     for(int i = 1; i < prices.size(); i++) {
    //         if(prices[i] < prices[i - 1]) {
    //             profit += currProf;
    //             currProf = 0;
    //             mini = prices[i];
    //         }
    //         else currProf = prices[i] - mini;
    //     }
    //     return profit + currProf;
    // }

    /*-------------DP-----------------*/
    int DPM(vector<int>& prices, vector<vector<int>>& dp, int i, int buy) {
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int prof = 0;
        if(buy) {
            prof = max(
                -prices[i] + DPM(prices, dp, i + 1, 0),
                DPM(prices, dp, i + 1, 1)
            );
        }
        else {
            prof = max(
                prices[i] + DPM(prices, dp, i + 1, 1),
                DPM(prices, dp, i + 1, 0)
            );
        }
        return dp[i][buy] = prof;
    }

    int DPT(vector<int>& prices, vector<vector<int>>& dp) { // DP dimensions are (n + 1, 2)
        int n = prices.size();
        dp.back()[0] = dp.back()[1] = 0;

        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        int ans = DPT(prices, dp);
        return ans;
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