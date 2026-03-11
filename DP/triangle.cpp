#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    static int DPM(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
        if(i == triangle.size() - 1) {
            return dp[i][j] = triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(DPM(triangle, dp, i + 1, j), DPM(triangle, dp, i + 1, j + 1)) + triangle[i][j];
    }

    //Tabulation
    static int DPT(vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = dp.size();
        for(int i = 0; i < dp.size(); i++) dp[n - 1][i] = triangle[n - 1][i];

        for(int i = n - 2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }

    //Space Optimization
    static int DPSO(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++) dp[i] = triangle[n - 1][i];

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }


    static int minimumTotal(vector<vector<int>>& triangle) {
        return DPSO(triangle);
    }
};
int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << Solution :: minimumTotal(triangle);
}