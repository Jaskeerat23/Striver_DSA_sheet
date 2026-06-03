#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //MEMOIZATION
    int f_rec(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
        if(r - l - 1 == 0) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int maxi = -1;
        for(int k = l + 1; k < r; k++) {
            int wt = nums[l] * nums[k] * nums[r];
            int partition1 = f_rec(nums, dp, l, k);
            int partition2 = f_rec(nums, dp, k, r);
            maxi = max(maxi, partition1 + partition2 + wt);
        }
        return dp[l][r] = maxi;
    }

    //TABULATION
    int f(vector<int>& nums, vector<vector<int>>& dp) {

        for(int l = nums.size() - 1; l >= 0; l--) {
            for(int r = 0; r < nums.size(); r++) {
                if(l > r) continue;
                int maxi = 0;
                for(int k = l + 1; k < r; k++) {
                    int wt = nums[l] * nums[k] * nums[r];
                    int partition1 = dp[l][k];
                    int partition2 = dp[k][r];
                    maxi = max(maxi, partition1 + partition2 + wt);
                }
                dp[l][r] = maxi;
            }
        }

        return dp[0][nums.size() - 1];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size(); // new Size
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        return f(nums, dp);
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
    cout << sol.maxCoins(arr);
}