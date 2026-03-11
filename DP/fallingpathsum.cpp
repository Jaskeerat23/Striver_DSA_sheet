#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    static int DPM(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j) {
        if(i <= -1 || j <= -1 || i >= dp.size() || j >= dp.size()) return INT_MAX;
        if(i == dp.size() - 1) return dp[i][j] = mat[i][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = min({
            DPM(mat, dp, i + 1, j - 1),   //Left Diagonal
            DPM(mat, dp, i + 1, j),       //Same column
            DPM(mat, dp, i + 1, j + 1)    //Right Diagonal
        }) + mat[i][j];
    }

    //Tabulation
    static int DPT(vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = dp.size(), mini = INT_MAX;
        for(int i = 0; i < n; i++) dp[n - 1][i] = mat[n - 1][i];

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int left = (j == 0) ? INT_MAX : dp[i + 1][j - 1];
                int right = (j == n - 1) ? INT_MAX : dp[i + 1][j + 1];
                int middle = dp[i + 1][j];
                dp[i][j] = min({left, right, middle}) + mat[i][j];
            }
        }

        for(auto& it : dp[0]) mini = min(mini, it);
        return mini;
    }

    //Space Optimization - Constant Space
    static int DPSO(vector<vector<int>>& mat) {
        int n = mat.size(), mini = INT_MAX;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int left = (j == 0) ? INT_MAX : mat[i + 1][j - 1];
                int right = (j == n - 1) ? INT_MAX : mat[i + 1][j + 1];
                int middle = mat[i + 1][j];
                mat[i][j] = min({left, right, middle}) + mat[i][j];
            }
        }

        for(auto& it : mat[0]) mini = min(mini, it);
        return mini;
    }

    static int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), INT_MIN));
        
        //The below snippet is used in MEMOIZATION
        //because when we start we can start from any cell
        //So we have to explore the recursion states of each 
        //cell
        //Comment it out if using DPM - func

        /*
        int mini = INT_MAX;
        for(int i = 0; i < matrix.size(); i++) {
            mini = min(mini, DPM(matrix, dp, 0, i));
        }
        */
        
        return DPSO(matrix);
    }
};

int main() {
    vector<vector<int>> mat = {{2,1,3},{6,5,4},{7,8,9}};
    cout << Solution :: minFallingPathSum(mat);
}