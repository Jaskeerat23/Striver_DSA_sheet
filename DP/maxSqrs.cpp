#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // cout << m << " " << n << endl;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
        for(int i = 0; i < n; i++) dp[0][i] = (matrix[0][i] == '1') ? 1 : 0;
        // cout << "here\n";
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '0') continue;
                int mini = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});

                if(!mini) dp[i][j] = 1;
                else dp[i][j] = 1 + mini;
            }
        }

        int maxArea = 0;
        for(auto& it1: dp) {
            for(auto& it2: it1) {
                maxArea = max(maxArea, it2 * it2);
            }
        }
        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1'}};
    cout << Solution :: maximalSquare(matrix);
}