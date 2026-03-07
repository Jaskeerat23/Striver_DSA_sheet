#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    //Memoization
    int DPM(vector<vector<int>>& mat, vector<vector<int>>& dp, int day, int last) {

        cout << "Last day i performed " << last << endl;

        if(day >= n) {cout << last << endl; return 0;}

        if(last > -1 && dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            cout << "Inside loop\n";
            if(i != last) maxi = max(maxi, mat[day][i] + DPM(mat, dp, day + 1, i));

        }

        return dp[day][last] = maxi;

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

        cout << "Final DP is\n";
        for(auto& it1 : dp) {
            for(auto& it2 : it1) 
                cout << it2 << " ";
            cout << endl;
        }

        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            maxi = max(maxi, dp[0][i]);
        }
        return maxi;

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

        // cout << "Final DP is\n";
        // for(auto& it1 : dp) {
        //     for(auto& it2 : it1) 
        //         cout << it2 << " ";
        //     cout << endl;
        // }

        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            maxi = max(maxi, dp[i]);
        }
        return maxi;

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