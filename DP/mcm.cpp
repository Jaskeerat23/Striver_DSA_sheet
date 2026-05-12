#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //memoization
    int dpm(vector<int>& arr, vector<vector<int>>& dp, int i, int j) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int part = i; part < j; part++) {
            int part_1 = dpm(arr, dp, i, part);
            int part_2 = dpm(arr, dp, part + 1, j);
            mini = min(mini, part_1 + part_2 + (arr[i - 1] * arr[part] * arr[j]));
        }
        return dp[i][j] = mini;
    }

    //tabulation
    int dpt(vector<int>& arr, vector<vector<int>>& dp) {
        int n = arr.size();
        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                int mini = 1e9;
                for(int part = i; part < j; part++) {
                    int part_1 = dp[i][part];
                    int part_2 = dp[part + 1][j];
                    cout << i << " " << j << " " << part_1 << " " << part_2 << endl;
                    mini = min(mini, part_1 + part_2 + (arr[i - 1] * arr[part] * arr[j]));
                }
                dp[i][j] = mini;
            }
        }

        for(auto& it1: dp) {
            for(auto& it2: it1) {
                cout << it2 << " ";
            }
            cout << endl;
        }

        return dp[1][n - 1];
    }

    int matrixMultiplication(vector<int> &arr) {
        // vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1)); -> dp for memoization
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        return dpt(arr, dp);
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
    cout << sol.matrixMultiplication(arr);
}