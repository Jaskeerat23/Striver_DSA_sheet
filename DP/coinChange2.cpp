#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //MEMOIZATION
    static int DPM(vector<int>& coins, vector<vector<int>>& dp, int ind, int target) {
        if(ind == 0) {
            if(target%coins[ind] == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int l = 0;
        if(coins[ind] <= target) {
            l = DPM(coins, dp, ind, target - coins[ind]);
        }

        int r = DPM(coins, dp, ind - 1, target);

        return dp[ind][target] = l + r;
    }

    //TABULATION
    static int DPT(vector<int>& coins, vector<vector<int>>& dp, int target) {
        int n = coins.size(), m = target + 1;
        for(int tgt = 0; tgt < target + 1; tgt++) {
            if(tgt%coins[0] == 0) dp[0][tgt] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < target + 1; j++) {
                int l = 0, r = dp[i - 1][j];
                if(coins[i] <= j) l = dp[i][j - coins[i]];

                dp[i][j] = l + r;
            }
        }
        return dp[n - 1][target];
    }

    static int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0)); //Init with 0 for tabulation and -1 for memoization
        return DPT(coins, dp, amount);
    }
};

int main() {
    int n, amount;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> amount;

    cout << Solution :: change(amount, arr);
}