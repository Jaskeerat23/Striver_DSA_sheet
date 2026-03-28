#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    //Memoization
    int DPM(vector<int>& nums, vector<vector<int>>& dp, int i, int target) {
        if(i == 0) {
            if(nums[0] != 0 && target == 0) return dp[i][target] = 1;
            if(nums[0] != 0 && target != 0) return dp[i][target] = nums[0] == target;
            if(nums[0] == 0 && target == 0) return dp[i][target] = 2;
            if(nums[0] == 0 && target != 0) return dp[i][target] = 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        int l = 0;

        if(nums[i] <= target) {
            l = DPM(nums, dp, i - 1, target - nums[i]);
        }
        
        int r = DPM(nums, dp, i - 1, target);
        
        return dp[i][target] = l + r;
    }

    //Tabulation
    int DPT(vector<int>& nums, vector<vector<int>>& dp, int target) {
        int m = dp.size(), n = dp[0].size();

        if(nums[0] == 0) {
            dp[0][0] = 2; // or even you can write dp[0][nums[0]]
        }
        else {
            if(nums[0] <= target) dp[0][nums[0]] = 1;
            dp[0][0] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int l = 0;
                if(j >= nums[i]) l = dp[i - 1][j - nums[i]];
                int r = dp[i - 1][j];
                dp[i][j] = l + r;
            }
        }
        return dp[m - 1][target];
    }

    //Space Optimization
    int DPSO(vector<int>& nums, int target) {
        int m = nums.size(), n = target + 1;
        vector<int> dp(target + 1, 0);

        if(nums[0] == 0) {
            dp[0] = 2; // or even you can write dp[0][nums[0]]
        }
        else {
            if(nums[0] <= target) dp[nums[0]] = 1;
            dp[0] = 1;
        }

        for(int i = 1; i < m; i++) {
            vector<int> temp(target + 1, 0);
            for(int j = 0; j < n; j++) {
                int l = 0;
                if(j >= nums[i]) l = dp[j - nums[i]];
                int r = dp[j];
                temp[j] = l + r;
            }
            dp = temp;
        }
        return dp[target];
    }
    
    int perfectSum(vector<int>& nums, int target) {
        int n = nums.size();
        // FOR MEMOIZATION & TABULATION vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // MEMOIZATION - return DPM(nums, dp, n - 1, target);
        // TABULATION - return DPT(nums, dp, target);
        return DPSO(nums, target);
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 10, 6, 8};
    Solution sol;
    cout << sol.perfectSum(nums, 10);
}