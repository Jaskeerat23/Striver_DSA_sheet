#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    static int DPM(vector<vector<int>>& dp, int i, int j) {

        if(i == 0 && j == 0) {
            return dp[i][j] = 1;
        }

        if(i <= -1 || j <= -1) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int up = DPM(dp, i - 1, j);
        int left = DPM(dp, i, j - 1);

        return dp[i][j] = up + left;
    }

    //Tabulation
    static int DPT(vector<vector<int>>& dp, int m, int n) {
        cout << m << " " << n << endl;
        for(int i = n - 1; i > -1; i-=1) dp[m - 1][i] = 1;
        for(int i = m - 1; i > -1; i-=1) dp[i][n - 1] = 1;

        for(int i = m - 2; i > -1; i-=1) {
            for(int j = n - 2; j > -1; j-=1) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

    //Space Optimization
    static int DPSO(int m, int n) {
        vector<int> dp(n, 1);

        for(int i = m - 2; i > -1; i-=1) {
            for(int j = n - 2; j > -1; j-=1) {
                dp[j] = dp[j] + dp[j + 1];
            }
        }
        return dp[0];
    }

    static int uniquePaths(int m, int n) {

        //for tabulation and memoization only
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        return DPSO(m, n);
    }
};

int main() {
    cout << Solution :: uniquePaths(3,7);
}