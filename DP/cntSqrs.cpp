#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) dp[i][0] = matrix[i][0];
        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) continue;
                else {
                    int mini = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    if(!mini) dp[i][j] = 1;
                    else dp[i][j] = 1 + mini;
                }
            }
        }
        int sum = 0;
        for(auto& it1: dp) for(auto& it2: it1) sum += it2;
        return sum;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };

    cout << Solution :: countSquares(mat);
}