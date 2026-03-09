#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    static int DPM(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        if(i <= -1 || j <= -1) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = min(DPM(grid, dp, i - 1, j), DPM(grid, dp, i, j - 1)) + grid[i][j];
    }
    
    
    //Tabulation
    static int DPT(vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = dp.size(), n = dp[0].size();
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        
        for(int i = n - 2; i > -1; i-=1) dp.back()[i] = grid.back()[i] + dp.back()[i + 1];
        for(int i = m - 2; i > -1; i-=1) dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];

        for(int i = m - 2; i > -1; i-=1) {
            for(int j = n - 2; j > -1; j-=1) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
    
    //Space Optimization
    static int DPSO(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n, -1);
        dp.back() = grid[m - 1][n - 1];

        for(int i = n - 2; i > -1; i-=1) dp[i] = grid.back()[i] + dp[i + 1];

        for(int i = m - 2; i > -1; i-=1) {
            for(int j = n - 1; j > -1; j-=1) {

                if(j == n - 1) {
                    dp[j] = grid[i][j] + dp[j];
                }
                else
                    dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[0];
    }
    
    static int minPathSum(vector<vector<int>>& grid) {

        //These 2 lines are only for Memoization and Tabulation
        // int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        return DPSO(grid);
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    cout << Solution :: minPathSum(grid);
}