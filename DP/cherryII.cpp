#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> dir = {-1, 0, 1};

    //Memoization
    int DPM(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2, int n, int m) {
        if(j1 <= -1 || j1 >= m || j2 <= -1 || j2 >= m) return INT_MIN;
        if(i == n - 1) {
            if(j1 == j2) return dp[i][j1][j2] = grid[i][j1]; //can also take j2
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        int maxi = 0;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                int cand = DPM(grid, dp, i + 1, j1 + dir[k], j2 + dir[l], n, m);
                maxi = max(maxi, cand);
            }
        }

        if(j1 == j2)  return dp[i][j1][j2] = maxi + grid[i][j1];

        return dp[i][j1][j2] = maxi + grid[i][j1] + grid[i][j2];

    }

    //Tabulation
    int DPT(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n, int m) {
        //Initialize DP
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m ; j++) {
                if(i == j) dp[n - 1][i][j] = grid[n - 1][i];
                else dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
            }
        }

        //For every Row
        for(int i = n - 2; i >= 0; i--) {

            //For a matrix in every row
            for(int j1 = 0; j1 < m ; j1++) {
                for(int j2 = 0; j2 < m; j2++) {

                    for(int k = 0; k < 3; k++) {

                        int j1_tgt = j1 + dir[k];
                        for(int l = 0; l < 3; l++) {

                            int j2_tgt = j2 + dir[l];

                            int num = (j1_tgt <= -1 || j1_tgt >= m || j2_tgt <= -1 || j2_tgt >= m)? INT_MIN : dp[i + 1][j1_tgt][j2_tgt];

                            //If we land on the same cell after this we only want to take 1 consideration of that cell
                            if(j1 == j2) {
                                dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j2] + num);
                            }
                            else {
                                dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j1] + grid[i][j2] + num);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][m - 1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return DPT(grid, dp, n, m);
    }
};

int main() {
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    Solution sol;
    cout << sol.cherryPickup(grid);
}