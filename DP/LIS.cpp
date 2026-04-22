#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DPM(vector<int>& nums, vector<vector<int>>& dp, int i, int prev) {
        if(i == nums.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int take = 0;
        if(i == -1 || nums[i] > nums[prev]) take = 1 + DPM(nums, dp, i + 1, i);
        int not_take = DPM(nums, dp, i + 1, prev);
        return dp[i][prev + 1] = max(not_take, take);
    }

    int DPT(vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        // for(int i = 0; i <= n; i++) dp[n][0] = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int prev = i - 1; prev >= -1; prev--) {
                int take = 0;
                if(prev == -1 || nums[prev] < nums[i]) take = 1 + dp[i + 1][i + 1];
                int not_take = dp[i + 1][prev + 1];
                dp[i][prev + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }

    int binary_search(vector<int>& lis, int num) {
        int low = 0, high = lis.size() - 1, ans = INT_MIN;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(lis[mid] >= num) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1)); // -> MEMOIZATION
        // int ans = DPM(nums, dp, 0, INT_MIN); // -> MEMOIZATION
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        // int ans = DPT(nums, dp);
        // return ans;

        vector<int> lis;
        for(int i = 0; i < nums.size(); i++) {
            if(lis.size() == 0 || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
            }
            else {
                int k = binary_search(lis, nums[i]);
                lis[k] = nums[i];
            }
        }
        return lis.size();
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
    cout << sol.lengthOfLIS(arr);
}