#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    //Memoization
    int DPM(vector<vector<int>>& mat, vector<vector<int>>& dp, int day, int last) {

        if(day >= n) return 0;

        if(last > -1 && dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last) maxi = max(maxi, mat[day][i] + DPM(mat, dp, day + 1, i));

        }
        
        //For first recursive call, we can take a dp of size 4 as 2nd Dim to avoid writing the following conditions
        if(last > -1)
            return dp[day][last] = maxi;
        return maxi;

    }

    //Tabulation
    int DPT(vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = dp.size();
        for(int i = 0; i < 3; i++) {
            dp[n - 1][i] = mat[n - 1][i];
        }

        for(int i = n - 2; i > -1; i-=1) {
            for(int j = 0; j < 3; j++) {

                for(int today = 0; today < 3; today++) {
                    if(j != today)
                        dp[i][today] = max(dp[i][today], mat[i][today] + dp[i + 1][j]);
                }
            }
        }

        return max(dp[0][0], max(dp[0][1], dp[0][2]));

    }

    //Space Optimization
    int DPTSO(vector<vector<int>>& mat, vector<int>& dp) {
        int n = dp.size();
        for(int i = 0; i < 3; i++) {
            dp[i] = mat[n - 1][i];
        }

        for(int i = n - 2; i > -1; i-=1) {
            vector<int> temp(3, 0);
            for(int j = 0; j < 3; j++) {

                for(int today = 0; today < 3; today++) {

                    if(j != today)
                        temp[today] = max(dp[today], mat[i][today] + dp[j]);

                }
            }
            dp = temp;
        }

        return max(dp[0], max(dp[0], dp[0]));
    }

    int maximumPoints(vector<vector<int>>& mat) {
        vector<int> dp(3, 0);

        return DPTSO(mat, dp);

    }
};

int main() {
    vector<vector<int>> mat = {
        {1,1,1},
        {2,2,2},
        {3,3,3}
    };

    Solution sol;

    cout <<  sol.maximumPoints(mat);
}