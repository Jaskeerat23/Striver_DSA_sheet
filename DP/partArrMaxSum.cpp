#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    int f_rec(vector<int>& arr, vector<int>& dp, int i, int k) {
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = arr[i], maxAns = 0;
        for(int j = i; j < min(i + k, (int)arr.size()); j++) {
            maxi = max(maxi, arr[j]);
            int sum = maxi * (j - i + 1) + f_rec(arr, dp, j + 1, k);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }

    //Tabulation
    int f_tab(vector<int>& arr, vector<int>& dp, int k) {
        int n = arr.size();
        if(dp.size() == arr.size()) dp.push_back(0);
        for(int i = n - 1; i >= 0; i--) {
            int maxi = arr[i], maxAns = 0;
            for(int j = i; j < min(i + k, (int)arr.size()); j++) {
                maxi = max(maxi, arr[j]);
                int sum = maxi * (j - i + 1) + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return f_tab(arr, dp, k);
    }
};

int main() {
    int n, l;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> l;
    Solution sol;
    cout << sol.maxSumAfterPartitioning(arr, l);
}