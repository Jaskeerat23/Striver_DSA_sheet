#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //MEMOIZATION
    int DPM(vector<int>& arr, vector<vector<int>>& dp, int ind, int target) {
        if(ind == 0) {
            if(target%arr[ind] == 0) return dp[ind][target] = target/arr[ind];
            return dp[ind][target] = 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = DPM(arr, dp, ind - 1, target);
        int take = 1e9;
        
        if(arr[ind] <= target) {
            take = DPM(arr, dp, ind, target - arr[ind]) + 1;
        }
        
        cout << ind << " " << target << " and returning min of take, notTake " << take << " " << notTake << endl;
        return dp[ind][target] = min(take, notTake);
    }

    //TABULATION
    int DPT(vector<int>& arr, vector<vector<int>>& dp, int amount) {
        int n = arr.size();
        for(int i = 0; i < amount + 1; i++) {
            if(i%arr[0] == 0)
                dp[0][i] = i/arr[0];
            else dp[0][i] = 1e9;
        }
        
        cout << "Init dp is\n";
        for(auto& it1: dp) {
            for(int& it2 : it1) cout << it2 << " ";
            cout << endl;
        }

        for(int i = 1; i < n; i++) {
            for(int target = 0; target < amount + 1; target++) {
                int take = 1e9;
                if(arr[i] <= target) {
                    take = dp[i][target - arr[i]] + 1;
                }
                else {
                    cout << "Not running for " << target << endl;
                }
                int notTake = dp[i - 1][target];

                dp[i][target] = min(take, notTake);
            }
        }

        cout << "final dp is\n";
        for(auto& it1: dp) {
            for(int& it2 : it1) cout << it2 << " ";
            cout << endl;
        }

        return dp[n - 1][amount];
    }

    //SPACE OPTIMIZATION
    int DPSO(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<int> dp(amount + 1, 0);
        for(int i = 0; i < amount + 1; i++) {
            if(i%arr[0] == 0)
                dp[i] = i/arr[0];
            else dp[i] = 1e9;
        }

        for(int i = 1; i < n; i++) {
            for(int target = 0; target < amount + 1; target++) {
                int take = 1e9;
                if(arr[i] <= target) {
                    take = dp[target - arr[i]] + 1;
                }
                int notTake = dp[target];
                dp[target] = min(take, notTake);
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        // BELOW 'dp' IS USED FOR MEMOIZATION AND TABULATION ONLY
        // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        int ans = DPSO(coins, amount);

        if(ans == 1e9) return -1;
        return ans;
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

    // for(int& i: arr) cout << i << " ";


    Solution sol;
    cout << sol.coinChange(arr, amount);
}